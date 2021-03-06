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
#define PARASET_F 0
#define PARASET_S 1
#define BUTTONSW 2
#define MONITOR 3
//	功能定义
#define FUNCTION 5
#define ORING_VALUE 6
#define MONITOR_ON 6
#define MONITOR_OFF 7
/*------------------------------------------------------*/
/*						变量声明						*/
/*======================================================*/
extern char menu2_limit;
extern short calindex;
extern unsigned char menu2_mode;
extern unsigned char magflag;
extern unsigned char *swflag;
extern short *shortvalue[5];
extern float *floatvalue[5];
extern unsigned char swclearflag;
/*------------------------------------------------------*/ 
/* 						函数声明 						*/
/*======================================================*/
/*------------------------------*/
/*		    菜单基础部分		*/
/*==============================*/
void menu2_init(void);
void menu2_display(void);
void menu2_select(unsigned char event);
/*------------------------------*/
/*		   数值监视模块			*/
/*==============================*/
void menu2value_hl(void);
//	监视器
void monitor(void);
/*------------------------------*/
/*		   按钮状态模块			*/
/*==============================*/
void swdisplay(void);
#endif
