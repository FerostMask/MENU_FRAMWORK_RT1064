/*------------------------------------------------------*/
/* 					   ͷ�ļ����� 						*/
/*======================================================*/
#ifndef _PID_H
#define _PID_H
/*------------------------------------------------------*/
/* 					   ͷ�ļ����� 						*/
/*======================================================*/
#include "data.h"
/*------------------------------------------------------*/
/* 					  �ⲿ�������� 						*/
/*======================================================*/

/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/
void inc_pid(struct pidpara *para, short tar, short act, short thrsod);
void pos_pid(struct pidpara *para, short tar, short act, short max, short min);
#endif