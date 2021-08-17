/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "pid.h"
#include "math.h"
#include "pid_fuzzy.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/*							  �궨��							*/
/*==============================================================*/
#define u8 unsigned char                                    //8λ����
#define u16 unsigned short                                  //16λ����
#define u32 unsigned int                                    //32λ����
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*----------------------*/
/*	 	 ģ������		*/
/*======================*/

/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*----------------------*/
/*		����PIDģ��		*/
/*======================*/
void inc_pid(struct pidpara *para, short tar, short act, short thrsod){
//	�����б�-> para:�������� | tar:Ŀ��ֵ | act:ʵ��ֵ | value:������ | thrsod:��ֵ
//	��������
	float yn;
//	����ͼ������
	para->e3 = para->e2;
	para->e2 = para->e1;
	para->e1 = tar - act;
	yn = para->I;
//	PID��ʽ
	para->I = para->Ki*para->e1;
//	һ�׵�ͨ�˲���������
	para->I = para->alpha*para->I + (1-para->alpha)*yn;
	para->rs += para->Kp*(para->e1-para->e2) + para->I + para->Kd*(para->e1 - 2*para->e2 + para->e3);
//	��ֵ�޶�
	if(abs(para->rs) > thrsod){
		if(para->rs >= 0)
			para->rs = thrsod;
		else
			para->rs = -thrsod;
	}
}
/*----------------------*/
/*		λ��PIDģ��		*/
/*======================*/
void pos_pid(struct pidpara *para, short tar, short act, short max, short min){
//	�����б�-> para:�������� | tar:Ŀ��ֵ | act:ʵ��ֵ | max:������ֵ | min:��С����ֵ
//	����ͼ������
	para->e2 = para->e1;
	para->e1 = tar - act;
//	ģ��PID
	PID_realize(para);
//	PID��ʽ
//	if(ring_out_flag == 3) para->detKp = 0;//�����ػ�
	para->rs = (para->Kp+para->detKp)*para->e1 + para->Kd*(para->e1 - para->e2);	
//	��ֵ�޶�	
	if(para->rs > max)
		para->rs = max;
	else if(para->rs < min)
		para->rs = min;
}
