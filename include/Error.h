#ifndef __ERROR_H__
#define __ERROR_H__
/******************************************************************************


 ******************************************************************************
文 件 名   : error.h
 					
@author Litost_Cheng
@date 2019年1月9日
  最近修改   :
@file error.c 的头文件
  函数列表   :
修改历史   :
@date 2019年1月9日
@author Litost_Cheng
修改内容   : 创建文件

******************************************************************************/

/*----------------------------------------------*
 * 包含头文件                                   *
 *----------------------------------------------*/
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*----------------------------------------------*
 * 宏定义                                 *
 *----------------------------------------------*/
#define	MAXLINE	4096			/* max line length */
/**
*@brief 体检判断，并返回预定值
*
*
*@param bCondition
*@param Res
*@param fmt
*@param arg...
*
* 
*
*@author Litost_Cheng
*@date 2019年4月22日
*@note 新生成函数
*
*/
#define  CondJudgeReturn(bCondition, Res, fmt, arg...) do{\
    if (!bCondition)\
    {\
    	printf(fmt, ##arg);\
		return (Res);\
    }\
\
}while(0);



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
extern void ErrCont(int error, const char *fmt, ...);
extern void ErrDump(const char *fmt, ...);
extern void ErrExit(int error, const char *fmt, ...);
extern void ErrMsg(const char *fmt, ...);
extern void ErrQuit(const char *fmt, ...);
extern void ErrRet(const char *fmt, ...);
extern void ErrSys(const char *fmt, ...);
extern bool CondJudge(bool bCondition, const char *fmt, ...);
extern bool CondJudgeAndErrno(bool bCondition, const char *fmt, ...);




/*----------------------------------------------*
 * 全局变量                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 常量定义                                       *
 *----------------------------------------------*/


#endif /* __ERROR_H__ */
