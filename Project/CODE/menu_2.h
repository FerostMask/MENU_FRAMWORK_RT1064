/*------------------------------------------------------*/
/* 					   ͷ�ļ����� 						*/
/*======================================================*/
#ifndef _SECMENU_H
#define _SECMENU_H
//	����ͷ�ļ�
#include "data.h"
/*------------------------------------------------------*/
/*						 �궨��							*/
/*======================================================*/
#define PARASET_F 0
#define PARASET_S 1
#define SWITCHER 2
//	���ܶ���
#define FUNCTION 5
/*------------------------------------------------------*/
/*						��������						*/
/*======================================================*/
extern char menu2_limit;
extern unsigned char menu2_mode;
extern unsigned char magflag;
extern unsigned char *swflag;
extern short *shortvalue[5];
extern float *floatvalue[5];
/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/
/*------------------------------*/
/*		    �˵���������		*/
/*==============================*/
void menu2_init(void);
void menu2_display(void);
void menu2_select(unsigned char event);
/*------------------------------*/
/*		   ��ֵ����ģ��			*/
/*==============================*/
void menu2value_hl(void);
//	������
void monitor(void);
void fixed_monitor(void);
/*------------------------------*/
/*		   ��ť״̬ģ��			*/
/*==============================*/
void swdisplay(void);
#endif
