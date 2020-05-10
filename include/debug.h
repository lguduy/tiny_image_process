#ifndef DEBUG_H
#define DEBUG_H

/**
 * 打印程序运行时的信息 四种等级：ERROR WARNING NOTICE INFO
 * 程序异常处理打印
 * 
 * @author: liangyu
 */

// debug信息打印
#define DEBUG_ERROR_PRINT(fmt, arg...) \
    prinf("ERROR. %s(%d)-%s -> " fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
#define DEBUG_WARNING_PRINT(fmt, arg...) \
    prinf("WARNING. %s(%d)-%s -> " fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
#define DEBUG_NOTICE_PRINT(fmt, arg...) \
    prinf("NOTICE. %s(%d)-%s -> " fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
#define DEBUG_INFO_PRINT(fmt, arg...) \
    prinf("INFO. %s(%d)-%s -> " fmt, __FILE__, __LINE__, __FUNCTION__, ##args)

// 异常处理打印
#define RETURN_FAIL_IF_FAIL(expr, ret, msg, args...) \
    do {if (!(expr)) DEBUG_ERROR_PRINT(msg, ##args); return ret;} while(0)
#define RETURN_IF_FAIL(expr, ret, msg, args...) \
    do {if (!(expr)) DEBUG_ERROR_PRINT(msg, ##args); return;} while(0)

#endif // DEBUG_H