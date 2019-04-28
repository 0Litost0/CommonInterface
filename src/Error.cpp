#include "Error.h"
/*----------------------------------------------*
 * 宏定义                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 枚举定义                            *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 结构体定义                              *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 外部函数原型说明                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 内部函数原型说明                                   *
 *----------------------------------------------*/

static void	ErrDoit(int, int, const char *, va_list ap);

/*----------------------------------------------*
 * 宏定义                                 *
 *----------------------------------------------*/
#define FALSE_BREAK(bCondition, fmt, arg...) \
do{\
	if(!(bCondition))\
	{\
		va_list		ap;\
		va_start(ap, fmt);\
		ErrDoit(0, 0, (fmt), ap);\
		break;\
	}\
while(0)


/**
*@brief 针对系统调用产生的一个非致命性错误，打印错误信息 errno 并返回
*
*
*@param const char *fmt
*@param ...
*
*@return void
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrRet(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(1, errno, fmt, ap);
	va_end(ap);
}

/**
*@brief 针对系统调用产生的一个致命性性错误，打印错误信息 errno，终止程序执行
*
*
*@param const char *fmt
*@param ...
*
*@return 
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrSys(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

/**
*@brief 输入相应的错误编码 errno，打印相关错误信息，并返回
*
*
*@param int error
*@param const char *fmt
*@param ...
*
*@return 
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrCont(int error, const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(1, error, fmt, ap);
	va_end(ap);
}

/**
*@brief 输入相应的错误编码 errno，打印相关错误信息，并终止程序执行
*
*
*@param int error
*@param const char *fmt
*@param ...
*
*@return 
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrExit(int error, const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(1, error, fmt, ap);
	va_end(ap);
	exit(1);
}

/*
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */
/**
*@brief 针对系统调用的致命错误，打印相关错误信息 errno，产生core dump，并终止程序执行
*
*
*@param const char *fmt
*@param ...
*
*@return 
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrDump(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(1, errno, fmt, ap);
	va_end(ap);
	abort();		/* dump core and terminate */
	exit(1);		/* shouldn't get here */
}

/**
*@brief 输出错误信息，并返回
*
*
*@param const char *fmt
*@param ...
*
*@return 
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrMsg(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(0, 0, fmt, ap);
	va_end(ap);
}

/**
*@brief 作用类似于assert,返回错误结果，同时判断条件为false的情况，输出相应错误信息
*
*
*@param bool bCondition
*@param const char *fmt
*@param ...
*
*@return bool
*
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
bool CondJudge(bool bCondition, const char *fmt, ...)
{
    if (!bCondition)
    {
        va_list		ap;
        va_start(ap, fmt);
		ErrDoit(0, 0, fmt, ap);
		va_end(ap);
    }
    return bCondition;
}

/**
*@brief 作用类似于assert,返回错误结果，同时判断条件为false的情况，输出相应错误信息,以及errno相关的信息
*
*
*@param bool bCondition
*@param const char *fmt
*@param ...
*
*@return bool
*
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
bool CondJudgeAndErrno(bool bCondition, const char *fmt, ...)
{
	if (!bCondition)
	{
		va_list ap;

		va_start(ap, fmt);
		ErrDoit(1, errno, fmt, ap);
		va_end(ap);

	}
	return bCondition;
}

/**
*@brief 输出相应错误信息，并终止程序执行
*
*
*@param const char *fmt
*@param ...
*
*@return 
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
void ErrQuit(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ErrDoit(0, 0, fmt, ap);
	va_end(ap);
	exit(1);
}

/**
*@brief 格式化错误信息
*
*
*@param int errnoflag
*@param int error
*@param const char *fmt
*@param va_list ap
*
*@return
* 
*
*@author Litost_Cheng
*@date 2019年1月21日
*@note 新生成函数
*/
static void ErrDoit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char	buf[MAXLINE];

	vsnprintf(buf, MAXLINE-1, fmt, ap);
	if (errnoflag)
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": errno[%d] %s",
				 error, strerror(error));
	strcat(buf, "\n");
	fflush(stdout);		/* in case stdout and stderr are the same */
	fputs(buf, stderr);
	fflush(NULL);		/* flushes all stdio output streams */
}


	
