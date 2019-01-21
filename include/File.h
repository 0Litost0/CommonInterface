#ifndef __FILE_H__
#define __FILE_H__
/******************************************************************************


 ******************************************************************************
文 件 名   : File.h
 					
@author Litost_Cheng
@date 2019年1月21日
  最近修改   :
@file File.c 的头文件
  函数列表   :
修改历史   :
@date 2019年1月21日
@author Litost_Cheng
修改内容   : 创建文件

******************************************************************************/

/*----------------------------------------------*
 * 包含头文件                                   *
 *----------------------------------------------*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

/*----------------------------------------------*
 * 全局变量                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 常量定义                                       *
 *----------------------------------------------*/



extern int GetBestFileBuf(const char *pPath);

#endif /* __FILE_H__ */