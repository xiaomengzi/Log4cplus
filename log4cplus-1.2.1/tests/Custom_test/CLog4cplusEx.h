#ifndef _CLOG4CPLUSEX_H_
#define _CLOG4CPLUSEX_H_

#include <string>

/************************************************************************/
/* 利用RAII惯用法辅助打印函数出入口日志类                        */
/************************************************************************/
class FuncInOutLog
{
public:
    ~FuncInOutLog();
    explicit FuncInOutLog(const std::string& strFuncName);

private:
    const std::string m_strFuncName; // 函数名称
};

/************************************************************************/
/* 通过该宏自动打印函数出入口日志                                */
/************************************************************************/
#define IOLOG FuncInOutLog fiol(__FUNCTION__)

#define LOG_TRACE(input) TRACE_LOG((input), (__FUNCTION__), (__FILE__), (__LINE__));
#define LOG_DEBUG(input) DEBUG_LOG((input), (__FUNCTION__), (__FILE__), (__LINE__));
#define LOG_INFO(input) INFO_LOG((input), (__FUNCTION__), (__FILE__), (__LINE__));
#define LOG_WARN(input) WARN_LOG((input), (__FUNCTION__), (__FILE__), (__LINE__));
#define LOG_ERROR(input) ERROR_LOG((input), (__FUNCTION__), (__FILE__), (__LINE__));
#define LOG_FATAL(input) FATAL_LOG((input), (__FUNCTION__), (__FILE__), (__LINE__));


void TRACE_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine);
void DEBUG_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine);
void INFO_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine);
void WARN_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine);
void ERROR_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine);
void FATAL_LOG(const std::string& strInfo, const std::string& strFunction, const std::string& strFile, int iLine);

class CLog4cplusEx
{
public:
    static CLog4cplusEx* Initialize(const std::string& strLogFile);
    static void UnInitialize();

private:
	CLog4cplusEx(const std::string& strLogFile);
	static CLog4cplusEx* pInstance;
};

#endif //_CLOG4CPLUSEX_H_
