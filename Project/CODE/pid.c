/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "pid.h"
#include "math.h"
#include "pid_fuzzy.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/*							  宏定义							*/
/*==============================================================*/
#define u8 unsigned char                                    //8位数据
#define u16 unsigned short                                  //16位数据
#define u32 unsigned int                                    //32位数据
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/
/*----------------------*/
/*	 	 模块名称		*/
/*======================*/

/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
/*----------------------*/
/*		增量PID模块		*/
/*======================*/
void inc_pid(struct pidpara *para, short tar, short act, short thrsod){
//	参数列表-> para:调定参数 | tar:目标值 | act:实际值 | value:控制量 | thrsod:阈值
//	变量定义
	float yn;
//	保存和计算误差
	para->e3 = para->e2;
	para->e2 = para->e1;
	para->e1 = tar - act;
	yn = para->I;
//	PID公式
	para->I = para->Ki*para->e1;
//	一阶低通滤波（积分项
	para->I = para->alpha*para->I + (1-para->alpha)*yn;
	para->rs += para->Kp*(para->e1-para->e2) + para->I + para->Kd*(para->e1 - 2*para->e2 + para->e3);
//	阈值限定
	if(abs(para->rs) > thrsod){
		if(para->rs >= 0)
			para->rs = thrsod;
		else
			para->rs = -thrsod;
	}
}
/*----------------------*/
/*		位置PID模块		*/
/*======================*/
void pos_pid(struct pidpara *para, short tar, short act, short max, short min){
//	参数列表-> para:调定参数 | tar:目标值 | act:实际值 | max:最大控制值 | min:最小控制值
//	保存和计算误差
	para->e2 = para->e1;
	para->e1 = tar - act;
//	模糊PID
	PID_realize(para);
//	PID公式
//	if(ring_out_flag == 3) para->detKp = 0;//环道特化
	para->rs = (para->Kp+para->detKp)*para->e1 + para->Kd*(para->e1 - para->e2);	
//	阈值限定	
	if(para->rs > max)
		para->rs = max;
	else if(para->rs < min)
		para->rs = min;
}
