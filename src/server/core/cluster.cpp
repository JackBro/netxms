/*
** NetXMS - Network Management System
** Copyright (C) 2003-2016 Victor Kirhenshtein
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** File: cluster.cpp
**
**/

#include "nxcore.h"

/**
 * Cluster class default constructor
 */
Cluster::Cluster() : DataCollectionTarget()
{
	m_dwClusterType = 0;
   m_syncNetworks = new ObjectArray<InetAddress>(8, 8, true);
	m_dwNumResources = 0;
	m_pResourceList = NULL;
	m_tmLastPoll = 0;
	m_zoneId = 0;
}

/**
 * Cluster class new object constructor
 */
Cluster::Cluster(const TCHAR *pszName, UINT32 zoneId) : DataCollectionTarget(pszName)
{
	m_dwClusterType = 0;
   m_syncNetworks = new ObjectArray<InetAddress>(8, 8, true);
	m_dwNumResources = 0;
	m_pResourceList = NULL;
	m_tmLastPoll = 0;
	m_zoneId = zoneId;
}

/**
 * Destructor
 */
Cluster::~Cluster()
{
   delete m_syncNetworks;
	safe_free(m_pResourceList);
}

/**
 * Create object from database data
 */
bool Cluster::loadFromDatabase(DB_HANDLE hdb, UINT32 dwId)
{
	TCHAR szQuery[256];
   bool bResult = false;
	DB_RESULT hResult;
	UINT32 dwNodeId;
	NetObj *pObject;
	int i, nRows;

   m_id = dwId;
   if (!loadCommonProperties(hdb))
   {
      nxlog_debug(2, _T("Cannot load common properties for cluster object %d"), dwId);
      return false;
   }

	_sntprintf(szQuery, 256, _T("SELECT cluster_type,zone_guid FROM clusters WHERE id=%d"), (int)m_id);
	hResult = DBSelect(hdb, szQuery);
	if (hResult == NULL)
		return false;

	m_dwClusterType = DBGetFieldULong(hResult, 0, 0);
	m_zoneId = DBGetFieldULong(hResult, 0, 1);
	DBFreeResult(hResult);

   // Load DCI and access list
   loadACLFromDB(hdb);
   loadItemsFromDB(hdb);
   for(i = 0; i < m_dcObjects->size(); i++)
      if (!m_dcObjects->get(i)->loadThresholdsFromDB(hdb))
         return false;

   if (!m_isDeleted)
   {
		// Load member nodes
		_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("SELECT node_id FROM cluster_members WHERE cluster_id=%d"), m_id);
		hResult = DBSelect(hdb, szQuery);
		if (hResult != NULL)
		{
			nRows = DBGetNumRows(hResult);
			for(i = 0; i < nRows; i++)
			{
				dwNodeId = DBGetFieldULong(hResult, i, 0);
				pObject = FindObjectById(dwNodeId);
				if (pObject != NULL)
				{
					if (pObject->getObjectClass() == OBJECT_NODE)
					{
                  addChild(pObject);
                  pObject->addParent(this);
					}
					else
					{
                  nxlog_write(MSG_CLUSTER_MEMBER_NOT_NODE, EVENTLOG_ERROR_TYPE, "dd", m_id, dwNodeId);
						break;
					}
				}
				else
				{
               nxlog_write(MSG_INVALID_CLUSTER_MEMBER, EVENTLOG_ERROR_TYPE, "dd", m_id, dwNodeId);
					break;
				}
			}
			if (i == nRows)
				bResult = true;
			DBFreeResult(hResult);
		}

		// Load sync net list
		if (bResult)
		{
			_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("SELECT subnet_addr,subnet_mask FROM cluster_sync_subnets WHERE cluster_id=%d"), m_id);
			hResult = DBSelect(hdb, szQuery);
			if (hResult != NULL)
			{
				int count = DBGetNumRows(hResult);
				for(i = 0; i < count; i++)
				{
               InetAddress *addr = new InetAddress(DBGetFieldInetAddr(hResult, i, 0));
               addr->setMaskBits(DBGetFieldLong(hResult, i, 1));
               m_syncNetworks->add(addr);
				}
				DBFreeResult(hResult);
			}
			else
			{
				bResult = false;
			}
		}

		// Load resources
		if (bResult)
		{
			_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("SELECT resource_id,resource_name,ip_addr,current_owner FROM cluster_resources WHERE cluster_id=%d"), m_id);
			hResult = DBSelect(hdb, szQuery);
			if (hResult != NULL)
			{
				m_dwNumResources = DBGetNumRows(hResult);
				if (m_dwNumResources > 0)
				{
					m_pResourceList = (CLUSTER_RESOURCE *)malloc(sizeof(CLUSTER_RESOURCE) * m_dwNumResources);
					for(i = 0; i < (int)m_dwNumResources; i++)
					{
						m_pResourceList[i].dwId = DBGetFieldULong(hResult, i, 0);
						DBGetField(hResult, i, 1, m_pResourceList[i].szName, MAX_DB_STRING);
						m_pResourceList[i].ipAddr = DBGetFieldInetAddr(hResult, i, 2);
						m_pResourceList[i].dwCurrOwner = DBGetFieldULong(hResult, i, 3);
					}
				}
				DBFreeResult(hResult);
			}
			else
			{
				bResult = false;
			}
		}
	}
   else
   {
      bResult = true;
   }

   return bResult;
}

/**
 * Called by client session handler to check if threshold summary should be shown for this object.
 */
bool Cluster::showThresholdSummary()
{
   return true;
}

/**
 * Save object to database
 */
BOOL Cluster::saveToDatabase(DB_HANDLE hdb)
{
	TCHAR szQuery[4096], szIpAddr[64];
   BOOL bResult;

   // Lock object's access
   lockProperties();

   saveCommonProperties(hdb);

   if (IsDatabaseRecordExist(hdb, _T("clusters"), _T("id"), m_id))
      _sntprintf(szQuery, 4096,
                 _T("UPDATE clusters SET cluster_type=%d,zone_guid=%d WHERE id=%d"),
                 (int)m_dwClusterType, (int)m_zoneId, (int)m_id);
	else
      _sntprintf(szQuery, 4096,
                 _T("INSERT INTO clusters (id,cluster_type,zone_guid) VALUES (%d,%d,%d)"),
                 (int)m_id, (int)m_dwClusterType, (int)m_zoneId);
   bResult = DBQuery(hdb, szQuery);

   // Save data collection items
   if (bResult)
   {
		lockDciAccess(false);
      for(int i = 0; i < m_dcObjects->size(); i++)
         m_dcObjects->get(i)->saveToDatabase(hdb);
		unlockDciAccess();

		// Save cluster members list
		if (DBBegin(hdb))
		{
			_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("DELETE FROM cluster_members WHERE cluster_id=%d"), m_id);
			DBQuery(hdb, szQuery);
			lockChildList(false);
			for(int i = 0; i < m_childList->size(); i++)
			{
				if (m_childList->get(i)->getObjectClass() == OBJECT_NODE)
				{
					_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("INSERT INTO cluster_members (cluster_id,node_id) VALUES (%d,%d)"),
								 m_id, m_childList->get(i)->getId());
					bResult = DBQuery(hdb, szQuery);
					if (!bResult)
						break;
				}
			}
			unlockChildList();
			if (bResult)
				DBCommit(hdb);
			else
				DBRollback(hdb);
		}
		else
		{
			bResult = FALSE;
		}

		// Save sync net list
		if (bResult)
		{
			if (DBBegin(hdb))
			{
				_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("DELETE FROM cluster_sync_subnets WHERE cluster_id=%d"), m_id);
				DBQuery(hdb, szQuery);
				for(int i = 0; i < m_syncNetworks->size(); i++)
				{
               InetAddress *net = m_syncNetworks->get(i);
					_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("INSERT INTO cluster_sync_subnets (cluster_id,subnet_addr,subnet_mask) VALUES (%d,'%s',%d)"),
                          (int)m_id, net->toString(szIpAddr), net->getMaskBits());
					bResult = DBQuery(hdb, szQuery);
					if (!bResult)
						break;
				}
				if (bResult)
					DBCommit(hdb);
				else
					DBRollback(hdb);
			}
			else
			{
				bResult = FALSE;
			}
		}

		// Save resource list
		if (bResult)
		{
			if (DBBegin(hdb))
			{
				_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("DELETE FROM cluster_resources WHERE cluster_id=%d"), m_id);
				DBQuery(hdb, szQuery);
				for(UINT32 i = 0; i < m_dwNumResources; i++)
				{
					_sntprintf(szQuery, sizeof(szQuery) / sizeof(TCHAR), _T("INSERT INTO cluster_resources (cluster_id,resource_id,resource_name,ip_addr,current_owner) VALUES (%d,%d,%s,'%s',%d)"),
					           m_id, m_pResourceList[i].dwId, (const TCHAR *)DBPrepareString(hdb, m_pResourceList[i].szName),
								  m_pResourceList[i].ipAddr.toString(szIpAddr),
								  m_pResourceList[i].dwCurrOwner);
					bResult = DBQuery(hdb, szQuery);
					if (!bResult)
						break;
				}
				if (bResult)
					DBCommit(hdb);
				else
					DBRollback(hdb);
			}
			else
			{
				bResult = FALSE;
			}
		}
   }

   // Save access list
   saveACLToDB(hdb);

   // Clear modifications flag and unlock object
	if (bResult)
		m_isModified = false;
   unlockProperties();

   return bResult;
}

/**
 * Delete object from database
 */
bool Cluster::deleteFromDatabase(DB_HANDLE hdb)
{
   bool success = DataCollectionTarget::deleteFromDatabase(hdb);
   if (success)
   {
      success = executeQueryOnObject(hdb, _T("DELETE FROM clusters WHERE id=?"));
      if (success)
         success = executeQueryOnObject(hdb, _T("DELETE FROM cluster_members WHERE cluster_id=?"));
      if (success)
         success = executeQueryOnObject(hdb, _T("DELETE FROM cluster_sync_subnets WHERE cluster_id=?"));
   }
   return success;
}

/**
 * Create CSCP message with object's data
 */
void Cluster::fillMessageInternal(NXCPMessage *pMsg)
{
	UINT32 i, dwId;

   DataCollectionTarget::fillMessageInternal(pMsg);
   pMsg->setField(VID_CLUSTER_TYPE, m_dwClusterType);
	pMsg->setField(VID_ZONE_ID, m_zoneId);

   pMsg->setField(VID_NUM_SYNC_SUBNETS, (UINT32)m_syncNetworks->size());
   for(i = 0, dwId = VID_SYNC_SUBNETS_BASE; i < (UINT32)m_syncNetworks->size(); i++)
      pMsg->setField(dwId++, *(m_syncNetworks->get(i)));

   pMsg->setField(VID_NUM_RESOURCES, m_dwNumResources);
	for(i = 0, dwId = VID_RESOURCE_LIST_BASE; i < m_dwNumResources; i++, dwId += 6)
	{
		pMsg->setField(dwId++, m_pResourceList[i].dwId);
		pMsg->setField(dwId++, m_pResourceList[i].szName);
		pMsg->setField(dwId++, m_pResourceList[i].ipAddr);
		pMsg->setField(dwId++, m_pResourceList[i].dwCurrOwner);
	}
}

/**
 * Modify object from message
 */
UINT32 Cluster::modifyFromMessageInternal(NXCPMessage *pRequest)
{
   // Change cluster type
   if (pRequest->isFieldExist(VID_CLUSTER_TYPE))
      m_dwClusterType = pRequest->getFieldAsUInt32(VID_CLUSTER_TYPE);

   // Change sync subnets
   if (pRequest->isFieldExist(VID_NUM_SYNC_SUBNETS))
	{
      m_syncNetworks->clear();
      int count = pRequest->getFieldAsInt32(VID_NUM_SYNC_SUBNETS);
      UINT32 fieldId = VID_SYNC_SUBNETS_BASE;
      for(int i = 0; i < count; i++)
      {
         m_syncNetworks->add(new InetAddress(pRequest->getFieldAsInetAddress(fieldId++)));
      }
	}

   // Change resource list
   if (pRequest->isFieldExist(VID_NUM_RESOURCES))
	{
		UINT32 i, j, dwId, dwCount;
		CLUSTER_RESOURCE *pList;

      dwCount = pRequest->getFieldAsUInt32(VID_NUM_RESOURCES);
		if (dwCount > 0)
		{
			pList = (CLUSTER_RESOURCE *)malloc(sizeof(CLUSTER_RESOURCE) * dwCount);
			memset(pList, 0, sizeof(CLUSTER_RESOURCE) * dwCount);
			for(i = 0, dwId = VID_RESOURCE_LIST_BASE; i < dwCount; i++, dwId += 7)
			{
				pList[i].dwId = pRequest->getFieldAsUInt32(dwId++);
				pRequest->getFieldAsString(dwId++, pList[i].szName, MAX_DB_STRING);
				pList[i].ipAddr = pRequest->getFieldAsInetAddress(dwId++);
			}

			// Update current owner information in existing resources
			for(i = 0; i < m_dwNumResources; i++)
			{
				for(j = 0; j < dwCount; j++)
				{
					if (m_pResourceList[i].dwId == pList[j].dwId)
					{
						pList[j].dwCurrOwner = m_pResourceList[i].dwCurrOwner;
						break;
					}
				}
			}

			// Replace list
			safe_free(m_pResourceList);
			m_pResourceList = pList;
		}
		else
		{
			safe_free_and_null(m_pResourceList);
		}
		m_dwNumResources = dwCount;
	}

   return DataCollectionTarget::modifyFromMessageInternal(pRequest);
}

/**
 * Check if given address is within sync network
 */
bool Cluster::isSyncAddr(const InetAddress& addr)
{
	bool bRet = false;

	lockProperties();
	for(int i = 0; i < m_syncNetworks->size(); i++)
	{
		if (m_syncNetworks->get(i)->contain(addr))
		{
			bRet = true;
			break;
		}
	}
	unlockProperties();
	return bRet;
}

/**
 * Check if given address is a resource address
 */
bool Cluster::isVirtualAddr(const InetAddress& addr)
{
	UINT32 i;
	bool bRet = false;

	lockProperties();
	for(i = 0; i < m_dwNumResources; i++)
	{
      if (m_pResourceList[i].ipAddr.equals(addr))
		{
			bRet = true;
			break;
		}
	}
	unlockProperties();
	return bRet;
}

/**
 * Entry point for status poller thread
 */
void Cluster::statusPoll(PollerInfo *poller)
{
   poller->startExecution();
   statusPoll(NULL, 0, poller);
   delete poller;
}

/**
 * Status poll
 */
void Cluster::statusPoll(ClientSession *pSession, UINT32 dwRqId, PollerInfo *poller)
{
   if (IsShutdownInProgress())
      return;

	int i, pollListSize;
	InterfaceList *pIfList;
	BOOL bModified = FALSE, bAllDown;
	BYTE *pbResourceFound;
	NetObj **ppPollList;

   // Create polling list
   ppPollList = (NetObj **)malloc(sizeof(NetObj *) * m_childList->size());
   lockChildList(false);
   for(i = 0, pollListSize = 0; i < m_childList->size(); i++)
   {
      NetObj *object = m_childList->get(i);
      if ((object->getStatus() != STATUS_UNMANAGED) &&
			 (object->getObjectClass() == OBJECT_NODE))
      {
         object->incRefCount();
			((Node *)object)->lockForStatusPoll();
         ppPollList[pollListSize++] = object;
      }
   }
   unlockChildList();

	// Perform status poll on all member nodes
	DbgPrintf(6, _T("CLUSTER STATUS POLL [%s]: Polling member nodes"), m_name);
	for(i = 0, bAllDown = TRUE; i < pollListSize; i++)
	{
		((Node *)ppPollList[i])->statusPoll(pSession, dwRqId, poller);
		if (!((Node *)ppPollList[i])->isDown())
			bAllDown = FALSE;
	}

	if (bAllDown)
	{
		if (!(m_flags & CLF_DOWN))
		{
		   m_flags |= CLF_DOWN;
			PostEvent(EVENT_CLUSTER_DOWN, m_id, NULL);
		}
	}
	else
	{
		if (m_flags & CLF_DOWN)
		{
		   m_flags &= ~CLF_DOWN;
			PostEvent(EVENT_CLUSTER_UP, m_id, NULL);
		}
	}

	// Check for cluster resource movement
	if (!bAllDown)
	{
		pbResourceFound = (BYTE *)malloc(m_dwNumResources);
		memset(pbResourceFound, 0, m_dwNumResources);

		DbgPrintf(6, _T("CLUSTER STATUS POLL [%s]: Polling resources"), m_name);
		for(i = 0; i < pollListSize; i++)
		{
			pIfList = ((Node *)ppPollList[i])->getInterfaceList();
			if (pIfList != NULL)
			{
				lockProperties();
				for(int j = 0; j < pIfList->size(); j++)
				{
					for(UINT32 k = 0; k < m_dwNumResources; k++)
					{
                  if (pIfList->get(j)->hasAddress(m_pResourceList[k].ipAddr))
						{
							if (m_pResourceList[k].dwCurrOwner != ppPollList[i]->getId())
							{
								DbgPrintf(5, _T("CLUSTER STATUS POLL [%s]: Resource %s owner changed"),
											 m_name, m_pResourceList[k].szName);

								// Resource moved or go up
								if (m_pResourceList[k].dwCurrOwner == 0)
								{
									// Resource up
									PostEvent(EVENT_CLUSTER_RESOURCE_UP, m_id, "dsds",
												 m_pResourceList[k].dwId, m_pResourceList[k].szName,
												 ppPollList[i]->getId(), ppPollList[i]->getName());
								}
								else
								{
									// Moved
									NetObj *pObject;

									pObject = FindObjectById(m_pResourceList[k].dwCurrOwner);
									PostEvent(EVENT_CLUSTER_RESOURCE_MOVED, m_id, "dsdsds",
												 m_pResourceList[k].dwId, m_pResourceList[k].szName,
												 m_pResourceList[k].dwCurrOwner,
												 (pObject != NULL) ? pObject->getName() : _T("<unknown>"),
												 ppPollList[i]->getId(), ppPollList[i]->getName());
								}
								m_pResourceList[k].dwCurrOwner = ppPollList[i]->getId();
								bModified = TRUE;
							}
							pbResourceFound[k] = 1;
						}
					}
				}
				unlockProperties();
				delete pIfList;
			}
			else
			{
				DbgPrintf(6, _T("CLUSTER STATUS POLL [%s]: Cannot get interface list from %s"),
							 m_name, ppPollList[i]->getName());
			}
		}

		// Check for missing virtual addresses
		lockProperties();
		for(i = 0; i < (int)m_dwNumResources; i++)
		{
			if ((!pbResourceFound[i]) && (m_pResourceList[i].dwCurrOwner != 0))
			{
				NetObj *pObject;

				pObject = FindObjectById(m_pResourceList[i].dwCurrOwner);
				PostEvent(EVENT_CLUSTER_RESOURCE_DOWN, m_id, "dsds",
							 m_pResourceList[i].dwId, m_pResourceList[i].szName,
							 m_pResourceList[i].dwCurrOwner,
							 (pObject != NULL) ? pObject->getName() : _T("<unknown>"));
				m_pResourceList[i].dwCurrOwner = 0;
				bModified = TRUE;
			}
		}
		unlockProperties();
		safe_free(pbResourceFound);
	}

	// Cleanup
	for(i = 0; i < pollListSize; i++)
	{
		ppPollList[i]->decRefCount();
	}
	safe_free(ppPollList);

	lockProperties();
	if (bModified)
		setModified();
	m_tmLastPoll = time(NULL);
	m_flags &= ~CLF_QUEUED_FOR_STATUS_POLL;
	unlockProperties();

	DbgPrintf(6, _T("CLUSTER STATUS POLL [%s]: Finished"), m_name);
}

/**
 * Check if node is current owner of resource
 */
bool Cluster::isResourceOnNode(UINT32 dwResource, UINT32 dwNode)
{
	bool bRet = FALSE;

	lockProperties();
	for(UINT32 i = 0; i < m_dwNumResources; i++)
	{
		if (m_pResourceList[i].dwId == dwResource)
		{
			if (m_pResourceList[i].dwCurrOwner == dwNode)
				bRet = true;
			break;
		}
	}
	unlockProperties();
	return bRet;
}

/**
 * Get node ID of resource owner
 */
UINT32 Cluster::getResourceOwnerInternal(UINT32 id, const TCHAR *name)
{
   UINT32 ownerId = 0;
   lockProperties();
   for(UINT32 i = 0; i < m_dwNumResources; i++)
   {
      if (((name != NULL) && !_tcsicmp(name, m_pResourceList[i].szName)) ||
          (m_pResourceList[i].dwId == id))
      {
         ownerId = m_pResourceList[i].dwCurrOwner;
         break;
      }
   }
   unlockProperties();
   return ownerId;
}

/**
 * Collect aggregated data for cluster nodes - single value
 */
UINT32 Cluster::collectAggregatedData(DCItem *item, TCHAR *buffer)
{
   lockChildList(true);
   ItemValue **values = (ItemValue **)malloc(sizeof(ItemValue *) * m_childList->size());
   int valueCount = 0;
   for(int i = 0; i < m_childList->size(); i++)
   {
      if (m_childList->get(i)->getObjectClass() != OBJECT_NODE)
         continue;

      Node *node = (Node *)m_childList->get(i);
      DCObject *dco = node->getDCObjectByTemplateId(item->getId());
      if ((dco != NULL) &&
          (dco->getType() == DCO_TYPE_ITEM) &&
          (dco->getStatus() == ITEM_STATUS_ACTIVE) &&
          ((dco->getErrorCount() == 0) || dco->isAggregateWithErrors()) &&
          dco->matchClusterResource())
      {
         ItemValue *v = ((DCItem *)dco)->getInternalLastValue();
         if (v != NULL)
            values[valueCount++] = v;
      }
   }
   unlockChildList();

   UINT32 rcc = DCE_SUCCESS;
   if (valueCount > 0)
   {
      ItemValue result;
      switch(item->getAggregationFunction())
      {
         case DCF_FUNCTION_AVG:
            CalculateItemValueAverage(result, item->getDataType(), valueCount, values);
            break;
         case DCF_FUNCTION_MAX:
            CalculateItemValueMax(result, item->getDataType(), valueCount, values);
            break;
         case DCF_FUNCTION_MIN:
            CalculateItemValueMin(result, item->getDataType(), valueCount, values);
            break;
         case DCF_FUNCTION_SUM:
            CalculateItemValueTotal(result, item->getDataType(), valueCount, values);
            break;
         default:
            rcc = DCE_NOT_SUPPORTED;
            break;
      }
      nx_strncpy(buffer, result.getString(), MAX_RESULT_LENGTH);
   }
   else
   {
      rcc = DCE_COMM_ERROR;
   }

   for(int i = 0; i < valueCount; i++)
      delete values[i];
   safe_free(values);

   return rcc;
}

/**
 * Collect aggregated data for cluster nodes - table
 */
UINT32 Cluster::collectAggregatedData(DCTable *table, Table **result)
{
   lockChildList(true);
   Table **values = (Table **)malloc(sizeof(Table *) * m_childList->size());
   int valueCount = 0;
   for(int i = 0; i < m_childList->size(); i++)
   {
      if (m_childList->get(i)->getObjectClass() != OBJECT_NODE)
         continue;

      Node *node = (Node *)m_childList->get(i);
      DCObject *dco = node->getDCObjectByTemplateId(table->getId());
      if ((dco != NULL) &&
          (dco->getType() == DCO_TYPE_TABLE) &&
          (dco->getStatus() == ITEM_STATUS_ACTIVE) &&
          ((dco->getErrorCount() == 0) || dco->isAggregateWithErrors()) &&
          dco->matchClusterResource())
      {
         Table *v = ((DCTable *)dco)->getLastValue();
         if (v != NULL)
            values[valueCount++] = v;
      }
   }
   unlockChildList();

   UINT32 rcc = DCE_SUCCESS;
   if (valueCount > 0)
   {
      *result = new Table(values[0]);
      for(int i = 1; i < valueCount; i++)
         table->mergeValues(*result, values[i], i);
   }
   else
   {
      rcc = DCE_COMM_ERROR;
   }

   for(int i = 0; i < valueCount; i++)
      values[i]->decRefCount();
   safe_free(values);

   return rcc;
}

/**
 * Unbind cluster from template
 */
void Cluster::unbindFromTemplate(UINT32 dwTemplateId, bool removeDCI)
{
   DataCollectionTarget::unbindFromTemplate(dwTemplateId, removeDCI);
   queueUpdate();
}

/**
 * Called when data collection configuration changed
 */
void Cluster::onDataCollectionChange()
{
   queueUpdate();
}

/**
 * Create NXSL object for this object
 */
NXSL_Value *Cluster::createNXSLObject()
{
   return new NXSL_Value(new NXSL_Object(&g_nxslClusterClass, this));
}

/**
 * Get cluster nodes as NXSL array
 */
NXSL_Array *Cluster::getNodesForNXSL()
{
   NXSL_Array *nodes = new NXSL_Array();
   int index = 0;

   lockChildList(false);
   for(int i = 0; i < m_childList->size(); i++)
   {
      if (m_childList->get(i)->getObjectClass() == OBJECT_NODE)
      {
         nodes->set(index++, new NXSL_Value(new NXSL_Object(&g_nxslNodeClass, m_childList->get(i))));
      }
   }
   unlockChildList();

   return nodes;
}
