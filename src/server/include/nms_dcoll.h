/*
** NetXMS - Network Management System
** Copyright (C) 2003-2013 Victor Kirhenshtein
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
** File: nms_dcoll.h
**
**/

#ifndef _nms_dcoll_h_
#define _nms_dcoll_h_


//
// Data collection errors
//

#define DCE_SUCCESS           0
#define DCE_COMM_ERROR        1
#define DCE_NOT_SUPPORTED     2
#define DCE_IGNORE            3
#define DCE_NO_SUCH_INSTANCE  4

/**
 * Threshold check results
 */
enum ThresholdCheckResult
{
   ACTIVATED = 0,
   DEACTIVATED = 1,
   ALREADY_ACTIVE = 2,
   ALREADY_INACTIVE = 3
};

/**
 * DCI value
 */
class NXCORE_EXPORTABLE ItemValue
{
private:
   double m_dFloat;
   INT32 m_iInt32;
   INT64 m_iInt64;
   UINT32 m_dwInt32;
   UINT64 m_qwInt64;
   TCHAR m_szString[MAX_DB_STRING];
   UINT32 m_dwTimeStamp;

public:
   ItemValue();
   ItemValue(const TCHAR *pszValue, UINT32 dwTimeStamp);
   ItemValue(const ItemValue *pValue);
   ~ItemValue();

   void setTimeStamp(UINT32 dwTime) { m_dwTimeStamp = dwTime; }
   UINT32 getTimeStamp() { return m_dwTimeStamp; }

   INT32 getInt32() { return m_iInt32; }
   UINT32 getUInt32() { return m_dwInt32; }
   INT64 getInt64() { return m_iInt64; }
   UINT64 getUInt64() { return m_qwInt64; }
   double getDouble() { return m_dFloat; }
   const TCHAR *getString() { return m_szString; }

   operator double() { return m_dFloat; }
   operator UINT32() { return m_dwInt32; }
   operator UINT64() { return m_qwInt64; }
   operator INT32() { return m_iInt32; }
   operator INT64() { return m_iInt64; }
   operator const TCHAR*() const { return m_szString; }

   const ItemValue& operator=(const ItemValue &src);
   const ItemValue& operator=(const TCHAR *pszStr);
   const ItemValue& operator=(double dFloat);
   const ItemValue& operator=(INT32 iInt32);
   const ItemValue& operator=(INT64 iInt64);
   const ItemValue& operator=(UINT32 dwInt32);
   const ItemValue& operator=(UINT64 qwInt64);
};


class DCItem;
class DataCollectionTarget;

/**
 * Threshold definition class
 */
class NXCORE_EXPORTABLE Threshold
{
private:
   UINT32 m_id;             // Unique threshold id
   UINT32 m_itemId;         // Parent item id
   UINT32 m_targetId;       // Parent data collection target ID
   UINT32 m_eventCode;      // Event code to be generated
   UINT32 m_rearmEventCode;
   ItemValue m_value;
   BYTE m_function;          // Function code
   BYTE m_operation;         // Comparision operation code
   BYTE m_dataType;          // Related item data type
	BYTE m_currentSeverity;   // Current everity (NORMAL if threshold is inactive)
   int m_sampleCount;        // Number of samples to calculate function on
   TCHAR *m_scriptSource;
   NXSL_Program *m_script;
   BOOL m_isReached;
	int m_numMatches;			// Number of consecutive matches
	int m_repeatInterval;		// -1 = default, 0 = off, >0 = seconds between repeats
	time_t m_lastEventTimestamp;

   const ItemValue& value() { return m_value; }
   void calculateAverageValue(ItemValue *pResult, ItemValue &lastValue, ItemValue **ppPrevValues);
   void calculateSumValue(ItemValue *pResult, ItemValue &lastValue, ItemValue **ppPrevValues);
   void calculateMDValue(ItemValue *pResult, ItemValue &lastValue, ItemValue **ppPrevValues);
   void calculateDiff(ItemValue *pResult, ItemValue &lastValue, ItemValue **ppPrevValues);
   void setScript(TCHAR *script);

public:
	Threshold();
   Threshold(DCItem *pRelatedItem);
   Threshold(Threshold *pSrc);
   Threshold(DB_RESULT hResult, int iRow, DCItem *pRelatedItem);
	Threshold(ConfigEntry *config, DCItem *parentItem);
   ~Threshold();

   void bindToItem(UINT32 itemId, UINT32 targetId) { m_itemId = itemId; m_targetId = targetId; }

   UINT32 getId() { return m_id; }
   UINT32 getEventCode() { return m_eventCode; }
   UINT32 getRearmEventCode() { return m_rearmEventCode; }
	int getFunction() { return m_function; }
	int getOperation() { return m_operation; }
	int getSampleCount() { return m_sampleCount; }
   const TCHAR *getStringValue() { return m_value.getString(); }
   BOOL isReached() { return m_isReached; }

	int getRepeatInterval() { return m_repeatInterval; }
	time_t getLastEventTimestamp() { return m_lastEventTimestamp; }
	int getCurrentSeverity() { return m_currentSeverity; }
	void markLastEvent(int severity);

   BOOL saveToDB(DB_HANDLE hdb, UINT32 dwIndex);
   ThresholdCheckResult check(ItemValue &value, ItemValue **ppPrevValues, ItemValue &fvalue, NetObj *target, DCItem *dci);
   ThresholdCheckResult checkError(UINT32 dwErrorCount);

   void createMessage(NXCPMessage *msg, UINT32 baseId);
   void updateFromMessage(NXCPMessage *msg, UINT32 baseId);

   void createId();
   UINT32 getRequiredCacheSize() { return ((m_function == F_LAST) || (m_function == F_ERROR)) ? 0 : m_sampleCount; }

   BOOL compare(Threshold *pThr);

   void createNXMPRecord(String &str, int index);

	void associate(DCItem *pItem);
	void setFunction(int nFunc) { m_function = nFunc; }
	void setOperation(int nOp) { m_operation = nOp; }
	void setEvent(UINT32 dwEvent) { m_eventCode = dwEvent; }
	void setRearmEvent(UINT32 dwEvent) { m_rearmEventCode = dwEvent; }
	void setSampleCount(int nVal) { m_sampleCount = nVal; }
	void setValue(const TCHAR *value) { m_value = value; }
	void setDataType(BYTE type) { m_dataType = type; }
};

class Template;

/**
 * Generic data collection object
 */
class NXCORE_EXPORTABLE DCObject
{
protected:
   UINT32 m_id;
   uuid m_guid;
   TCHAR m_name[MAX_ITEM_NAME];
   TCHAR m_description[MAX_DB_STRING];
	TCHAR m_systemTag[MAX_DB_STRING];
   time_t m_tLastPoll;           // Last poll time
   int m_iPollingInterval;       // Polling interval in seconds
   int m_iRetentionTime;         // Retention time in days
   BYTE m_source;                // origin: SNMP, agent, etc.
   BYTE m_status;                // Item status: active, disabled or not supported
   BYTE m_busy;                  // 1 when item is queued for polling, 0 if not
	BYTE m_scheduledForDeletion;  // 1 when item is scheduled for deletion, 0 if not
	UINT16 m_flags;
   UINT32 m_dwTemplateId;         // Related template's id
   UINT32 m_dwTemplateItemId;     // Related template item's id
   Template *m_owner;             // Pointer to node or template object this item related to
   MUTEX m_hMutex;
   StringList *m_schedules;
   time_t m_tLastCheck;          // Last schedule checking time
   UINT32 m_dwErrorCount;         // Consequtive collection error count
	UINT32 m_dwResourceId;	   	// Associated cluster resource ID
	UINT32 m_sourceNode;          // Source node ID or 0 to disable
	WORD m_snmpPort;					// Custom SNMP port or 0 for node default
	TCHAR *m_pszPerfTabSettings;
   TCHAR *m_transformationScriptSource;   // Transformation script (source code)
   NXSL_Program *m_transformationScript;  // Compiled transformation script
	TCHAR *m_comments;
	bool m_forcePoll;

   void lock() { MutexLock(m_hMutex); }
   void unlock() { MutexUnlock(m_hMutex); }

	bool loadCustomSchedules(DB_HANDLE hdb);
   bool matchSchedule(struct tm *pCurrTime, const TCHAR *pszSchedule, BOOL *bWithSeconds, time_t currTimestamp);

	void expandMacros(const TCHAR *src, TCHAR *dst, size_t dstLen);

	virtual bool isCacheLoaded();

	// --- constructors ---
   DCObject();
   DCObject(const DCObject *src);
   DCObject(UINT32 dwId, const TCHAR *szName, int iSource, int iPollingInterval, int iRetentionTime, Template *pNode,
            const TCHAR *pszDescription = NULL, const TCHAR *systemTag = NULL);
	DCObject(ConfigEntry *config, Template *owner);

public:
	virtual ~DCObject();

	virtual int getType() const { return DCO_TYPE_GENERIC; }

   virtual void updateFromTemplate(DCObject *dcObject);
   virtual void updateFromImport(ConfigEntry *config);

   virtual bool saveToDatabase(DB_HANDLE hdb);
   virtual void deleteFromDatabase();
   virtual bool loadThresholdsFromDB(DB_HANDLE hdb);

   virtual bool processNewValue(time_t nTimeStamp, const void *value, bool *updateStatus);
   void processNewError(bool noInstance);
   virtual void processNewError(bool noInstance, time_t now);

	virtual bool hasValue();

	UINT32 getId() const { return m_id; }
	const uuid& getGuid() const { return m_guid; }
   int getDataSource() const { return m_source; }
   int getStatus() const { return m_status; }
   const TCHAR *getName() const { return m_name; }
   const TCHAR *getDescription() const { return m_description; }
	const TCHAR *getSystemTag() const { return m_systemTag; }
	const TCHAR *getPerfTabSettings() const { return m_pszPerfTabSettings; }
   int getPollingInterval() const { return m_iPollingInterval; }
   int getEffectivePollingInterval() const { return (m_iPollingInterval > 0) ? m_iPollingInterval : m_defaultPollingInterval; }
   Template *getOwner() const { return m_owner; }
   UINT32 getOwnerId() const;
   const TCHAR *getOwnerName() const;
   UINT32 getTemplateId() const { return m_dwTemplateId; }
   UINT32 getTemplateItemId() const { return m_dwTemplateItemId; }
	UINT32 getResourceId() const { return m_dwResourceId; }
	UINT32 getSourceNode() const { return m_sourceNode; }
	time_t getLastPollTime() const { return m_tLastPoll; }
	UINT32 getErrorCount() const { return m_dwErrorCount; }
	WORD getSnmpPort() const { return m_snmpPort; }
   bool isShowOnObjectTooltip() const { return (m_flags & DCF_SHOW_ON_OBJECT_TOOLTIP) ? true : false; }
   bool isShowInObjectOverview() const { return (m_flags & DCF_SHOW_IN_OBJECT_OVERVIEW) ? true : false; }
   bool isAggregateOnCluster() const { return (m_flags & DCF_AGGREGATE_ON_CLUSTER) ? true : false; }
	bool isStatusDCO() const { return (m_flags & DCF_CALCULATE_NODE_STATUS) ? true : false; }
   bool isAggregateWithErrors() const { return (m_flags & DCF_AGGREGATE_WITH_ERRORS) ? true : false; }
   int getAggregationFunction() const { return DCF_GET_AGGREGATION_FUNCTION(m_flags); }
   int getRetentionTime() const { return m_iRetentionTime; }
   int getEffectiveRetentionTime() const { return (m_iRetentionTime > 0) ? m_iRetentionTime : m_defaultRetentionTime; }
   const TCHAR *getComments() const { return m_comments; }
   INT16 getAgentCacheMode();

	bool matchClusterResource();
   bool isReadyForPolling(time_t currTime);
	bool isScheduledForDeletion() { return m_scheduledForDeletion ? true : false; }
   void setLastPollTime(time_t tLastPoll) { m_tLastPoll = tLastPoll; }
   void setStatus(int status, bool generateEvent);
   void setBusyFlag(BOOL busy) { m_busy = (BYTE)busy; }
   void setTemplateId(UINT32 dwTemplateId, UINT32 dwItemId) { m_dwTemplateId = dwTemplateId; m_dwTemplateItemId = dwItemId; }

   virtual void createMessage(NXCPMessage *pMsg);
   virtual void updateFromMessage(NXCPMessage *pMsg);

   virtual void changeBinding(UINT32 dwNewId, Template *newOwner, BOOL doMacroExpansion);

	virtual void deleteExpiredData();
	virtual bool deleteAllData();

   virtual void getEventList(UINT32 **ppdwList, UINT32 *pdwSize);
   virtual void createExportRecord(String &str);

   NXSL_Value *createNXSLObject();

	void setName(const TCHAR *name) { nx_strncpy(m_name, name, MAX_ITEM_NAME); }
	void setDescription(const TCHAR *description) { nx_strncpy(m_description, description, MAX_DB_STRING); }
	void setOrigin(int origin) { m_source = origin; }
	void setRetentionTime(int nTime) { m_iRetentionTime = nTime; }
	void setInterval(int nInt) { m_iPollingInterval = nInt; }
	void setAdvScheduleFlag(BOOL bFlag) { if (bFlag) m_flags |= DCF_ADVANCED_SCHEDULE; else m_flags &= ~DCF_ADVANCED_SCHEDULE; }
	void addSchedule(const TCHAR *pszSchedule);
   void setTransformationScript(const TCHAR *source);
   void setForcePoll(bool poll) { m_forcePoll = poll; }

	bool prepareForDeletion();

	static int m_defaultRetentionTime;
	static int m_defaultPollingInterval;
};

/**
 * Data collection item class
 */
class NXCORE_EXPORTABLE DCItem : public DCObject
{
protected:
   TCHAR m_instance[MAX_DB_STRING];
   BYTE m_deltaCalculation;      // Delta calculation method
   BYTE m_dataType;
	int m_sampleCount;            // Number of samples required to calculate value
	ObjectArray<Threshold> *m_thresholds;
   UINT32 m_cacheSize;          // Number of items in cache
   UINT32 m_requiredCacheSize;
   ItemValue **m_ppValueCache;
   ItemValue m_prevRawValue;     // Previous raw value (used for delta calculation)
   time_t m_tPrevValueTimeStamp;
   bool m_bCacheLoaded;
	int m_nBaseUnits;
	int m_nMultiplier;
	TCHAR *m_customUnitName;
	WORD m_snmpRawValueType;		// Actual SNMP raw value type for input transformation
	WORD m_instanceDiscoveryMethod;
	TCHAR *m_instanceDiscoveryData;
	TCHAR *m_instanceFilterSource;
	NXSL_Program *m_instanceFilter;

   bool transform(ItemValue &value, time_t nElapsedTime);
   void checkThresholds(ItemValue &value);
   void updateCacheSizeInternal(UINT32 conditionId = 0);
   void clearCache();

	virtual bool isCacheLoaded();

   using DCObject::updateFromMessage;

public:
   DCItem();
   DCItem(const DCItem *pItem);
   DCItem(DB_HANDLE hdb, DB_RESULT hResult, int iRow, Template *pNode);
   DCItem(UINT32 dwId, const TCHAR *szName, int iSource, int iDataType,
          int iPollingInterval, int iRetentionTime, Template *pNode,
          const TCHAR *pszDescription = NULL, const TCHAR *systemTag = NULL);
	DCItem(ConfigEntry *config, Template *owner);
   virtual ~DCItem();

	virtual int getType() const { return DCO_TYPE_ITEM; }

   virtual void updateFromTemplate(DCObject *dcObject);
   virtual void updateFromImport(ConfigEntry *config);

   virtual bool saveToDatabase(DB_HANDLE hdb);
   virtual void deleteFromDatabase();
   virtual bool loadThresholdsFromDB(DB_HANDLE hdb);

   void updateCacheSize(UINT32 conditionId = 0) { lock(); updateCacheSizeInternal(conditionId); unlock(); }
   void reloadCache();

   int getDataType() { return m_dataType; }
	bool isInterpretSnmpRawValue() { return (m_flags & DCF_RAW_VALUE_OCTET_STRING) ? true : false; }
	WORD getSnmpRawValueType() { return m_snmpRawValueType; }
	bool hasActiveThreshold();
   int getThresholdSeverity();
	WORD getInstanceDiscoveryMethod() { return m_instanceDiscoveryMethod; }
	const TCHAR *getInstanceDiscoveryData() { return m_instanceDiscoveryData; }
	const TCHAR *getInstance() { return m_instance; }
	int getSampleCount() { return m_sampleCount; }

	void filterInstanceList(StringMap *instances);
	void expandInstance();

   virtual bool processNewValue(time_t nTimeStamp, const void *value, bool *updateStatus);
   virtual void processNewError(bool noInstance, time_t now);

	virtual bool hasValue();

   void fillLastValueMessage(NXCPMessage *pMsg, UINT32 dwId);
   NXSL_Value *getValueForNXSL(int nFunction, int nPolls);
   NXSL_Value *getRawValueForNXSL();
   const TCHAR *getLastValue();
   ItemValue *getInternalLastValue();
   TCHAR *getAggregateValue(AggregationFunction func, time_t periodStart, time_t periodEnd);

   virtual void createMessage(NXCPMessage *pMsg);
   void updateFromMessage(NXCPMessage *pMsg, UINT32 *pdwNumMaps, UINT32 **ppdwMapIndex, UINT32 **ppdwMapId);
   void fillMessageWithThresholds(NXCPMessage *msg);

   virtual void changeBinding(UINT32 dwNewId, Template *pNode, BOOL doMacroExpansion);

   virtual void deleteExpiredData();
	virtual bool deleteAllData();

   virtual void getEventList(UINT32 **ppdwList, UINT32 *pdwSize);
   virtual void createExportRecord(String &str);

	int getThresholdCount() const { return (m_thresholds != NULL) ? m_thresholds->size() : 0; }
	BOOL enumThresholds(BOOL (* pfCallback)(Threshold *, UINT32, void *), void *pArg);

	void setInstance(const TCHAR *instance) { nx_strncpy(m_instance, instance, MAX_DB_STRING); }
	void setDataType(int dataType) { m_dataType = dataType; }
	void setDeltaCalcMethod(int method) { m_deltaCalculation = method; }
	void setAllThresholdsFlag(BOOL bFlag) { if (bFlag) m_flags |= DCF_ALL_THRESHOLDS; else m_flags &= ~DCF_ALL_THRESHOLDS; }
	void addThreshold(Threshold *pThreshold);
	void deleteAllThresholds();
	void setInstanceDiscoveryMethod(WORD method) { m_instanceDiscoveryMethod = method; }
	void setInstanceDiscoveryData(const TCHAR *data) { safe_free(m_instanceDiscoveryData); m_instanceDiscoveryData = _tcsdup_ex(data); }
   void setInstanceFilter(const TCHAR *pszScript);

   static bool testTransformation(DataCollectionTarget *object, const TCHAR *script, const TCHAR *value, TCHAR *buffer, size_t bufSize);
};

/**
 * Table column definition
 */
class NXCORE_EXPORTABLE DCTableColumn
{
private:
	TCHAR m_name[MAX_COLUMN_NAME];
   TCHAR *m_displayName;
	SNMP_ObjectId *m_snmpOid;
	UINT16 m_flags;

public:
	DCTableColumn(const DCTableColumn *src);
	DCTableColumn(NXCPMessage *msg, UINT32 baseId);
	DCTableColumn(DB_RESULT hResult, int row);
   DCTableColumn(ConfigEntry *e);
	~DCTableColumn();

	const TCHAR *getName() { return m_name; }
   const TCHAR *getDisplayName() { return (m_displayName != NULL) ? m_displayName : m_name; }
   UINT16 getFlags() { return m_flags; }
   int getDataType() { return TCF_GET_DATA_TYPE(m_flags); }
   int getAggregationFunction() { return TCF_GET_AGGREGATION_FUNCTION(m_flags); }
	SNMP_ObjectId *getSnmpOid() { return m_snmpOid; }
   bool isInstanceColumn() { return (m_flags & TCF_INSTANCE_COLUMN) != 0; }

   void createNXMPRecord(String &str, int id);
};

/**
 * Table column ID hash entry
 */
struct TC_ID_MAP_ENTRY
{
	INT32 id;
	TCHAR name[MAX_COLUMN_NAME];
};

/**
 * Condition for table DCI threshold
 */
class NXCORE_EXPORTABLE DCTableCondition
{
private:
   TCHAR *m_column;
   int m_operation;
   ItemValue m_value;

public:
   DCTableCondition(const TCHAR *column, int operation, const TCHAR *value);
   DCTableCondition(DCTableCondition *src);
   ~DCTableCondition();

   bool check(Table *value, int row);

   const TCHAR *getColumn() { return m_column; }
   int getOperation() { return m_operation; }
   const TCHAR *getValue() { return m_value.getString(); }
};

/**
 * Condition group for table DCI threshold
 */
class NXCORE_EXPORTABLE DCTableConditionGroup
{
private:
   ObjectArray<DCTableCondition> *m_conditions;

public:
   DCTableConditionGroup();
   DCTableConditionGroup(NXCPMessage *msg, UINT32 *baseId);
   DCTableConditionGroup(DCTableConditionGroup *src);
   DCTableConditionGroup(ConfigEntry *e);
   ~DCTableConditionGroup();

   bool check(Table *value, int row);

   UINT32 fillMessage(NXCPMessage *msg, UINT32 baseId);

   ObjectArray<DCTableCondition> *getConditions() { return m_conditions; }
};

/**
 * Threshold definition for tabe DCI
 */
class NXCORE_EXPORTABLE DCTableThreshold
{
private:
   UINT32 m_id;
   ObjectArray<DCTableConditionGroup> *m_groups;
   UINT32 m_activationEvent;
   UINT32 m_deactivationEvent;
   StringSet *m_activeKeys;

   void loadConditions(DB_HANDLE hdb);

public:
   DCTableThreshold();
   DCTableThreshold(DB_HANDLE hdb, DB_RESULT hResult, int row);
   DCTableThreshold(NXCPMessage *msg, UINT32 *baseId);
   DCTableThreshold(DCTableThreshold *src);
   DCTableThreshold(ConfigEntry *e);
   ~DCTableThreshold();

   void copyState(DCTableThreshold *src);

   ThresholdCheckResult check(Table *value, int row, const TCHAR *instance);

   bool saveToDatabase(DB_HANDLE hdb, UINT32 tableId, int seq);
   UINT32 fillMessage(NXCPMessage *msg, UINT32 baseId);
   void createNXMPRecord(String &str, int id);

   UINT32 getId() { return m_id; }
   UINT32 getActivationEvent() { return m_activationEvent; }
   UINT32 getDeactivationEvent() { return m_deactivationEvent; }
};

/**
 * Tabular data collection object
 */
class NXCORE_EXPORTABLE DCTable : public DCObject
{
protected:
	ObjectArray<DCTableColumn> *m_columns;
   ObjectArray<DCTableThreshold> *m_thresholds;
	Table *m_lastValue;

	static TC_ID_MAP_ENTRY *m_cache;
	static int m_cacheSize;
	static int m_cacheAllocated;
	static MUTEX m_cacheMutex;

   bool transform(Table *value);
   void checkThresholds(Table *value);

   bool loadThresholds(DB_HANDLE hdb);
   bool saveThresholds(DB_HANDLE hdb);

public:
	DCTable();
   DCTable(const DCTable *src);
   DCTable(UINT32 id, const TCHAR *name, int source, int pollingInterval, int retentionTime,
	        Template *node, const TCHAR *description = NULL, const TCHAR *systemTag = NULL);
   DCTable(DB_HANDLE hdb, DB_RESULT hResult, int iRow, Template *pNode);
   DCTable(ConfigEntry *config, Template *owner);
	virtual ~DCTable();

	virtual int getType() const { return DCO_TYPE_TABLE; }

   virtual void updateFromTemplate(DCObject *dcObject);
   virtual void updateFromImport(ConfigEntry *config);

   virtual bool saveToDatabase(DB_HANDLE hdb);
   virtual void deleteFromDatabase();

   virtual bool processNewValue(time_t nTimeStamp, const void *value, bool *updateStatus);
   virtual void processNewError(bool noInstance, time_t now);

   virtual bool hasValue();

   virtual void createMessage(NXCPMessage *pMsg);
   virtual void updateFromMessage(NXCPMessage *pMsg);

	virtual void deleteExpiredData();
	virtual bool deleteAllData();

   virtual void createExportRecord(String &str);

	void fillLastValueMessage(NXCPMessage *msg);
   void fillLastValueSummaryMessage(NXCPMessage *pMsg, UINT32 dwId);

   int getColumnDataType(const TCHAR *name);
   ObjectArray<DCTableColumn> *getColumns() { return m_columns; }
   Table *getLastValue();

   void mergeValues(Table *dest, Table *src, int count);

   void updateResultColumns(Table *t);

	static INT32 columnIdFromName(const TCHAR *name);
};

/**
 * Data collection object information (for NXSL)
 */
class DCObjectInfo
{
private:
   UINT32 m_id;
   int m_type;
   TCHAR m_name[MAX_ITEM_NAME];
   TCHAR m_description[MAX_DB_STRING];
   TCHAR m_systemTag[MAX_DB_STRING];
   TCHAR m_instance[MAX_DB_STRING];
   TCHAR *m_comments;
   int m_dataType;
   int m_origin;
   int m_status;
   UINT32 m_errorCount;
   time_t m_lastPollTime;

public:
   DCObjectInfo(DCObject *object);
   ~DCObjectInfo();

   UINT32 getId() const { return m_id; }
   int getType() const { return m_type; }
   const TCHAR *getName() const { return m_name; }
   const TCHAR *getDescription() const { return m_description; }
   const TCHAR *getSystemTag() const { return m_systemTag; }
   const TCHAR *getInstance() const { return m_instance; }
   const TCHAR *getComments() const { return m_comments; }
   int getDataType() const { return m_dataType; }
   int getOrigin() const { return m_origin; }
   int getStatus() const { return m_status; }
   UINT32 getErrorCount() const { return m_errorCount; }
   time_t getLastPollTime() const { return m_lastPollTime; }
};

/**
 * Functions
 */
BOOL InitDataCollector();
void DeleteAllItemsForNode(UINT32 dwNodeId);
void WriteFullParamListToMessage(NXCPMessage *pMsg, WORD flags);
int GetDCObjectType(UINT32 nodeId, UINT32 dciId);

void CalculateItemValueDiff(ItemValue &result, int nDataType, ItemValue &value1, ItemValue &value2);
void CalculateItemValueAverage(ItemValue &result, int nDataType, int nNumValues, ItemValue **ppValueList);
void CalculateItemValueMD(ItemValue &result, int nDataType, int nNumValues, ItemValue **ppValueList);
void CalculateItemValueTotal(ItemValue &result, int nDataType, int nNumValues, ItemValue **ppValueList);
void CalculateItemValueMin(ItemValue &result, int nDataType, int nNumValues, ItemValue **ppValueList);
void CalculateItemValueMax(ItemValue &result, int nDataType, int nNumValues, ItemValue **ppValueList);

/**
 * Global variables
 */
extern double g_dAvgPollerQueueSize;
extern double g_dAvgDBWriterQueueSize;
extern double g_dAvgIDataWriterQueueSize;
extern double g_dAvgRawDataWriterQueueSize;
extern double g_dAvgDBAndIDataWriterQueueSize;
extern double g_dAvgSyslogProcessingQueueSize;
extern double g_dAvgSyslogWriterQueueSize;
extern UINT32 g_dwAvgDCIQueuingTime;


#endif   /* _nms_dcoll_h_ */
