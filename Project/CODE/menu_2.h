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
#define BUTTONSW 2
#define MONITOR 3
//	���ܶ���
#define FUNCTION 5
#define ORING_VALUE 6
#define MONITOR_ON 6
#define MONITOR_OFF 7
/*------------------------------------------------------*/
/*						��������						*/
/*======================================================*/
extern char menu2_limit;
extern unsigned char menu2_mode;
extern unsigned char magflag;
extern unsigned char *swflag;
extern short *shortvalue[5];
extern float *floatvalue[5];
extern unsigned char swclearflag;
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
/*------------------------------*/
/*		   ��ť״̬ģ��			*/
/*==============================*/
void swdisplay(void);
#endif
