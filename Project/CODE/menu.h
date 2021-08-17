/*------------------------------------------------------*/
/* 					   头文件声明 						*/
/*======================================================*/
#ifndef _MENU_H
#define _MENU_H
/*------------------------------------------------------*/ 
/* 						函数声明 						*/
/*======================================================*/
/*----------------------*/
/*	 	 菜单部分		*/
/*======================*/
void menu_display(void);
static char menu_limit(char index, char num);
void menu_select(unsigned char event);
/*----------------------*/
/*	 	 按键部分		*/
/*======================*/
void dir(unsigned char dirc);
static unsigned char col_jug(void);
void trig_jug(void);
#endif
