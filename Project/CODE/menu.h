/*------------------------------------------------------*/
/* 					   ͷ�ļ����� 						*/
/*======================================================*/
#ifndef _MENU_H
#define _MENU_H
/*------------------------------------------------------*/
/*						��������						*/
/*======================================================*/
//	һ���˵�
#define ROWS 4//����
//	�˵����Ա��
#define MENU_SWITCH 0
#define PARASET_PID 1
#define PARASET_OPER 2
#define MONITOR_MENU 3
//	��������
extern unsigned char menu[ROWS];
extern unsigned char colimit[ROWS];
/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/
/*----------------------*/
/*	 	 �˵�����		*/
/*======================*/
void menu_display(void);
void menu_select(unsigned char event);
/*----------------------*/
/*	 	 ��������		*/
/*======================*/
void dir(unsigned char dirc);
static unsigned char col_jug(void);
void trig_jug(void);
#endif
