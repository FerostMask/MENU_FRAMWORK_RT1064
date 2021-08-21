/*------------------------------------------------------*/
/* 					   头文件声明 						*/
/*======================================================*/
#ifndef _SECMENU_H
#define _SECMENU_H
//	加载头文件
#include "data.h"
/*------------------------------------------------------*/
/*						 宏定义							*/
/*======================================================*/
#define PARASET 0
/*------------------------------------------------------*/
/*						变量声明						*/
/*======================================================*/
extern unsigned char menu2_limit;
extern unsigned char menu2_mode;
extern short *shortvalue0, *shortvalue1, *shortvalue2, *shortvalue3, *shortvalue4;
extern float *floatvalue0, *floatvalue1, *floatvalue2, *floatvalue3, *floatvalue4;
/*------------------------------------------------------*/ 
/* 						函数声明 						*/
/*======================================================*/
/*------------------------------*/
/*		    菜单基础部分		*/
/*==============================*/
void menu2_init(void);
void menu2_display(short index);
void menu2_select(unsigned char event);
/*------------------------------*/
/*		   数值监视模块			*/
/*==============================*/
void menu2value_hl(void);
//	监视器
void monitor(void);
void fixed_monitor(void);
/*------------------------------*/
/*		   按钮状态模块			*/
/*==============================*/
void swdisplay(void);
#endif
