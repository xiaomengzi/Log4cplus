#include <cstdlib>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include "log4cplus/tstring.h"
#include "CLog4cplusEx.h"
#include "log4cplus/helpers/sleep.h"



using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

int main()
{
    //log4cplus::initialize();
    //LogLog::getLogLog()->setInternalDebugging(true);
    //Logger root = Logger::getRoot();
    //try {
    //    log4cplus::tstring file = LOG4CPLUS_C_STR_TO_TSTRING("./log4cplus.properties");
    //    PropertyConfigurator::doConfigure(file);
    //    int nCount = 50;
    //    while (nCount >= 0)
    //    {
    //        LOG4CPLUS_WARN(root, "Testing....");
    //        //LOG4CPLUS_TRACE_METHOD(logger, LOG4CPLUS_TEXT("::printDebug()"));
    //        LOG4CPLUS_DEBUG(root, "This is a DEBUG message, 这是一个测试消息");
    //        LOG4CPLUS_INFO(root, "This is a INFO message, 这是一个测试消息");
    //        LOG4CPLUS_WARN(root, "This is a WARN message, 这是一个测试消息");
    //        LOG4CPLUS_ERROR(root, "This is a ERROR message, 这是一个测试消息");
    //        LOG4CPLUS_FATAL(root, "This is a FATAL message, 这是一个测试消息");
    //        LOG4CPLUS_INFO(root, "This is a FATAL message  " << 1 << ", 这是一个测试消息");
    //        nCount--;
    //    }

    //}
    //catch (...) {
    //    //tcout << "Exception..." << endl;
    //    LOG4CPLUS_FATAL(root, "Exception occured...");
    //}

    CLog4cplusEx::Initialize("./log4cplus.properties");
    
        while (1)
        {
            IOLOG;
            LOG_DEBUG("This is a DEBUG message, 这是一个测试消息");
            LOG_ERROR("This is a ERROR message, 这是一个测试消息");
            LOG_WARN("This is a WARN message, 这是一个测试消息");
            LOG_INFO("This is a INFO message, 这是一个测试消息");
            sleep(10);
        }
    
    CLog4cplusEx::UnInitialize();

    //tcout << "Exiting main()..." << endl;
    system("pause");

    return 0;
}