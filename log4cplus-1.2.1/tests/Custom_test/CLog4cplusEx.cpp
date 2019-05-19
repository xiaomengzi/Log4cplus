#include "CLog4cplusEx.h"
#include <sstream>
#include <memory>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/configurator.h>
#include "log4cplus/helpers/loglog.h"
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include "log4cplus/tstring.h"
using namespace std;
using namespace log4cplus;
static Logger global_pLogger;

CLog4cplusEx* CLog4cplusEx::pInstance = NULL;

FuncInOutLog::FuncInOutLog(const std::string& strFuncName)
    : m_strFuncName(strFuncName)
{
    stringstream ssLogData;
    ssLogData << "[" << m_strFuncName << "] in";
    LOG4CPLUS_INFO(global_pLogger, ssLogData.str().c_str());
}

FuncInOutLog::~FuncInOutLog()
{
    stringstream ssLogData;
    ssLogData << "[" << m_strFuncName << "] out";
    LOG4CPLUS_INFO(global_pLogger, ssLogData.str().c_str());
}


CLog4cplusEx* CLog4cplusEx::Initialize(const string& strLogFile) {
	if (NULL == pInstance)
		pInstance = new CLog4cplusEx(strLogFile);
	return pInstance;
}

void CLog4cplusEx::UnInitialize()
{
    log4cplus::Logger::shutdown();
    if (NULL != pInstance)
    {
        delete pInstance;
        pInstance = NULL;
    }
}

CLog4cplusEx::CLog4cplusEx(const string& strLogFile) {
    log4cplus::initialize();
    log4cplus::helpers::LogLog::getLogLog()->setInternalDebugging(true);
    global_pLogger = Logger::getRoot();
    try 
    {
        log4cplus::tstring file = LOG4CPLUS_C_STR_TO_TSTRING(strLogFile);
        PropertyConfigurator::doConfigure(file);
    }
    catch (...) 
    {
        LOG4CPLUS_FATAL(global_pLogger, "Exception occured...");
    }
}


void TRACE_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine)
{
    stringstream ssLogData;
    ssLogData << "[" << strFunction << "] " << strInfo << " [" << strFile << ":" << iLine << "]";
    LOG4CPLUS_TRACE(global_pLogger, ssLogData.str().c_str());
}

void DEBUG_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine) {
	stringstream ssLogData;
    ssLogData << "[" << strFunction << "] " << strInfo << " [" << strFile << ":" << iLine << "]";
	LOG4CPLUS_DEBUG(global_pLogger, ssLogData.str().c_str());
}

void INFO_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine) {
    stringstream ssLogData;
    ssLogData << "[" << strFunction << "] " << strInfo << " [" << strFile << ":" << iLine << "]";
    LOG4CPLUS_INFO(global_pLogger, ssLogData.str().c_str());
}

void WARN_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine) {
    stringstream ssLogData;
    ssLogData << "[" << strFunction << "] " << strInfo << " [" << strFile << ":" << iLine << "]";
    LOG4CPLUS_WARN(global_pLogger, ssLogData.str().c_str());
}

void ERROR_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine) {
	stringstream ssLogData;
    ssLogData << "[" << strFunction << "] " << strInfo << " [" << strFile << ":" << iLine << "]";
	LOG4CPLUS_ERROR(global_pLogger, ssLogData.str().c_str());
}

void FATAL_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine)
{
    stringstream ssLogData;
    ssLogData << "[" << strFunction << "] " << strInfo << " [" << strFile << ":" << iLine << "]";
    LOG4CPLUS_FATAL(global_pLogger, ssLogData.str().c_str());
}

