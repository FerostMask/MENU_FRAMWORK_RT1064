/*------------------------------------------------------*/
/* 					   ͷ�ļ����� 						*/
/*======================================================*/
#ifndef _MENU_H
#define _MENU_H
/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/
/*----------------------*/
/*	 	 �˵�����		*/
/*======================*/
void menu_display(void);
static char menu_limit(char index, char num);
void menu_select(unsigned char event);
/*----------------------*/
/*	 	 ��������		*/
/*======================*/
void dir(unsigned char dirc);
static unsigned char col_jug(void);
void trig_jug(void);
#endif
