/*
** NetXMS - Network Management System
** Log Parsing Library
** Copyright (C) 2003-2012 Victor Kirhenshtein
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** File: nxlpapi.h
**
**/

#ifndef _nxlpapi_h_
#define _nxlpapi_h_

#ifdef _WIN32
#ifdef LIBNXLP_EXPORTS
#define LIBNXLP_EXPORTABLE __declspec(dllexport)
#else
#define LIBNXLP_EXPORTABLE __declspec(dllimport)
#endif
#else    /* _WIN32 */
#define LIBNXLP_EXPORTABLE
#endif

#include <netxms-regex.h>
#include <nms_util.h>


//
// Parser status
//

#define MAX_PARSER_STATUS_LEN	64

#define LPS_INIT              _T("INIT")
#define LPS_RUNNING           _T("RUNNING")
#define LPS_NO_FILE           _T("FILE MISSING")
#define LPS_OPEN_ERROR        _T("FILE OPEN ERROR")


//
// Context actions
//

#define CONTEXT_SET_MANUAL    0
#define CONTEXT_SET_AUTOMATIC 1
#define CONTEXT_CLEAR         2


//
// File encoding
//

#define LP_FCP_ACP      0
#define LP_FCP_UTF8     1
#define LP_FCP_UCS2     2
#define LP_FCP_UCS2_LE  3
#define LP_FCP_UCS4     4
#define LP_FCP_UCS4_LE  5

/**
 * Log parser callback
 * Parameters:
 *    NetXMS event code, NetXMS event name, original text, source,
 *    original event ID (facility), original severity,
 *    number of capture groups, list of capture groups,
 *    object id, user arg
 */
typedef void (* LogParserCallback)(UINT32, const TCHAR *, const TCHAR *, const TCHAR *, UINT32, UINT32, int, TCHAR **, UINT32, int, void *);

class LIBNXLP_EXPORTABLE LogParser;

/**
 * Log parser rule
 */
class LIBNXLP_EXPORTABLE LogParserRule
{
   friend class LogParser;

private:
	LogParser *m_parser;
	regex_t m_preg;
	UINT32 m_eventCode;
	TCHAR *m_eventName;
	bool m_isValid;
	int m_numParams;
	regmatch_t *m_pmatch;
	TCHAR *m_regexp;
	TCHAR *m_source;
	UINT32 m_level;
	UINT32 m_idStart;
	UINT32 m_idEnd;
	TCHAR *m_context;
	int m_contextAction;
	TCHAR *m_contextToChange;
	bool m_isInverted;
	bool m_breakOnMatch;
	TCHAR *m_description;
	int m_repeatInterval;
	int m_repeatCount;
   IntegerArray<time_t> *m_matchArray;
	bool m_resetRepeat;
	UINT32 m_checkCount;
	UINT32 m_matchCount;

	bool matchInternal(bool extMode, const TCHAR *source, UINT32 eventId, UINT32 level,
	                   const TCHAR *line, LogParserCallback cb, UINT32 objectId, void *userArg);
	bool matchRepeatCount();
   void expandMacros(const TCHAR *regexp, String &out);

public:
	LogParserRule(LogParser *parser,
	              const TCHAR *regexp, UINT32 eventCode = 0, const TCHAR *eventName = NULL,
					  int numParams = 0, int repeatInterval = 0, int repeatCount = 0,
					  bool resetRepeat = true, const TCHAR *source = NULL, UINT32 level = 0xFFFFFFFF,
					  UINT32 idStart = 0, UINT32 idEnd = 0xFFFFFFFF);
	LogParserRule(LogParserRule *src, LogParser *parser);
	~LogParserRule();

	bool isValid() const { return m_isValid; }
	bool match(const TCHAR *line, LogParserCallback cb, UINT32 objectId, void *userArg);
	bool matchEx(const TCHAR *source, UINT32 eventId, UINT32 level,
	             const TCHAR *line, LogParserCallback cb, UINT32 objectId, void *userArg);

	void setContext(const TCHAR *context) { safe_free(m_context); m_context = (context != NULL) ? _tcsdup(context) : NULL; }
	void setContextToChange(const TCHAR *context) { safe_free(m_contextToChange); m_contextToChange = (context != NULL) ? _tcsdup(context) : NULL; }
	void setContextAction(int action) { m_contextAction = action; }

	void setInverted(bool flag) { m_isInverted = flag; }
	BOOL isInverted() const { return m_isInverted; }

	void setBreakFlag(bool flag) { m_breakOnMatch = flag; }
	BOOL getBreakFlag() const { return m_breakOnMatch; }

	const TCHAR *getContext() const { return m_context; }
	const TCHAR *getContextToChange() const { return m_contextToChange; }
	int getContextAction() const { return m_contextAction; }

	void setDescription(const TCHAR *descr) { safe_free(m_description); m_description = (descr != NULL) ? _tcsdup(descr) : NULL; }
	const TCHAR *getDescription() const { return CHECK_NULL_EX(m_description); }

	void setSource(const TCHAR *source) { safe_free(m_source); m_source = (source != NULL) ? _tcsdup(source) : NULL; }
	const TCHAR *getSource() const { return CHECK_NULL_EX(m_source); }

	void setLevel(UINT32 level) { m_level = level; }
	UINT32 getLevel() const { return m_level; }

	void setIdRange(UINT32 start, UINT32 end) { m_idStart = start; m_idEnd = end; }
	QWORD getIdRange() const { return ((QWORD)m_idStart << 32) | (QWORD)m_idEnd; }

   void setRepeatInterval(int repeatInterval) { m_repeatInterval = repeatInterval; }
   int getRepeatInterval() const { return m_repeatInterval; }

   void setRepeatCount(int repeatCount) { m_repeatCount = repeatCount; }
   int getRepeatCount() const { return m_repeatCount; }

   void setRepeatReset(bool resetRepeat) { m_resetRepeat = resetRepeat; }
   bool isRepeatReset() const { return m_resetRepeat; }

	const TCHAR *getRegexpSource() const { return CHECK_NULL(m_regexp); }

	UINT32 getCheckCount() const { return m_checkCount; }
   UINT32 getMatchCount() const { return m_matchCount; }
};

/**
 * Log parser class
 */
class LIBNXLP_EXPORTABLE LogParser
{
	friend bool LogParserRule::matchInternal(bool, const TCHAR *, UINT32, UINT32, const TCHAR *, LogParserCallback, UINT32, void *);

private:
	int m_numRules;
	LogParserRule **m_rules;
	StringMap m_contexts;
	StringMap m_macros;
	LogParserCallback m_cb;
	void *m_userArg;
	TCHAR *m_fileName;
	int m_fileEncoding;
	TCHAR *m_name;
	CODE_TO_TEXT *m_eventNameList;
	bool (*m_eventResolver)(const TCHAR *, UINT32 *);
	THREAD m_thread;	// Associated thread
	int m_recordsProcessed;
	int m_recordsMatched;
	bool m_processAllRules;
	int m_traceLevel;
	void (*m_traceCallback)(const TCHAR *, va_list);
	TCHAR m_status[MAX_PARSER_STATUS_LEN];
#ifdef _WIN32
   TCHAR *m_marker;
#endif

	const TCHAR *checkContext(LogParserRule *rule);
	void trace(int level, const TCHAR *format, ...);
	bool matchLogRecord(bool hasAttributes, const TCHAR *source, UINT32 eventId, UINT32 level, const TCHAR *line, UINT32 objectId);

#ifdef _WIN32
   void parseEvent(EVENTLOGRECORD *rec);

	bool monitorEventLogV6(CONDITION stopCondition);
	bool monitorEventLogV4(CONDITION stopCondition);

   time_t readLastProcessedRecordTimestamp();
#endif

public:
	LogParser();
	LogParser(LogParser *src);
	~LogParser();

	static ObjectArray<LogParser> *createFromXml(const char *xml, int xmlLen = -1,
		TCHAR *errorText = NULL, int errBufSize = 0, bool (*eventResolver)(const TCHAR *, UINT32 *) = NULL);

	void setFileName(const TCHAR *name);
	const TCHAR *getFileName() { return m_fileName; }

	void setFileEncoding(int encoding) { m_fileEncoding = encoding; }
	int getFileEncoding() { return m_fileEncoding; }

	void setName(const TCHAR *name);
	const TCHAR *getName() { return m_name; }

	void setStatus(const TCHAR *status) { nx_strncpy(m_status, status, MAX_PARSER_STATUS_LEN); }
	const TCHAR *getStatus() { return m_status; }

	void setThread(THREAD th) { m_thread = th; }
	THREAD getThread() { return m_thread; }

	void setProcessAllFlag(bool flag) { m_processAllRules = flag; }
	bool getProcessAllFlag() { return m_processAllRules; }

	bool addRule(const TCHAR *regexp, UINT32 eventCode = 0, const TCHAR *eventName = NULL, int numParams = 0, int repeatInterval = 0, int repeatCount = 0, bool resetRepeat = true);
	bool addRule(LogParserRule *rule);
	void setCallback(LogParserCallback cb) { m_cb = cb; }
	void setUserArg(void *arg) { m_userArg = arg; }
	void setEventNameList(CODE_TO_TEXT *ctt) { m_eventNameList = ctt; }
	void setEventNameResolver(bool (*cb)(const TCHAR *, UINT32 *)) { m_eventResolver = cb; }
	UINT32 resolveEventName(const TCHAR *name, UINT32 defVal = 0);

	void addMacro(const TCHAR *name, const TCHAR *value);
	const TCHAR *getMacro(const TCHAR *name);

	bool matchLine(const TCHAR *line, UINT32 objectId = 0);
	bool matchEvent(const TCHAR *source, UINT32 eventId, UINT32 level, const TCHAR *line, UINT32 objectId = 0);

	int getProcessedRecordsCount() { return m_recordsProcessed; }
	int getMatchedRecordsCount() { return m_recordsMatched; }

	int getTraceLevel() { return m_traceLevel; }
	void setTraceLevel(int level) { m_traceLevel = level; }
	void setTraceCallback(void (*cb)(const TCHAR *, va_list)) { m_traceCallback = cb; }

	bool monitorFile(CONDITION stopCondition, bool readFromCurrPos = true);
#ifdef _WIN32
	bool monitorEventLog(CONDITION stopCondition, const TCHAR *markerPrefix);
   void saveLastProcessedRecordTimestamp(time_t timestamp);
#endif
};

/**
 * Init log parser library
 */
void LIBNXLP_EXPORTABLE InitLogParserLibrary();

/**
 * Cleanup event log parsig library
 */
void LIBNXLP_EXPORTABLE CleanupLogParserLibrary();

/**
 * Set trace callback for log parser library
 */
void LIBNXLP_EXPORTABLE SetLogParserTraceCallback(void (* traceCallback)(int, const TCHAR *, va_list));

#endif
