/*------------------------------------------------------*/
/* 					   头文件声明 						*/
/*======================================================*/
#ifndef _MENU_H
#define _MENU_H
/*------------------------------------------------------*/
/*						变量声明						*/
/*======================================================*/
//	一级菜单
#define ROWS 4//行数
//	菜单属性编号
#define MENU_SWITCH 0
#define PARASET_PID 1
#define PARASET_OPER 2
#define MONITOR_MENU 3
//	变量声明
extern unsigned char menu[ROWS];
extern unsigned char colimit[ROWS];
/*------------------------------------------------------*/ 
/* 						函数声明 						*/
/*======================================================*/
/*----------------------*/
/*	 	 菜单部分		*/
/*======================*/
void menu_display(void);
void menu_select(unsigned char event);
/*----------------------*/
/*	 	 按键部分		*/
/*======================*/
void dir(unsigned char dirc);
static unsigned char col_jug(void);
void trig_jug(void);
#endif
