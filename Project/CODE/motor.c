/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "motor.h"
#include "pid.h"
#include "Init.h"
#include "zf_pwm.h"
//#include "zf_tim.h"
#include "SEEKFREE_VIRSCO.h"
#include "SEEKFREE_WIRELESS.h"
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
//unsigned char temp[4] = {0, 0, 0, 0};
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*------------------------------*/
/*	     ������ֵ��ȡģ��		*/
/*==============================*/
void encoder_get(void){

}
/*------------------------------*/
/*		   �������ģ��			*/
/*==============================*/
void motor_act(void){
////	�������塢��ʼ��
//	short lefpwm, rigpwm;
//	lefpwm = acw.rs+lefdif.rs;
//	rigpwm = acw.rs+rigdif.rs;
////	�޷�
//	if(abs(lefpwm) > 7000){
//		if(lefpwm > 0) lefpwm = 7000;
//		else lefpwm = -7000;
//	}
//	if(abs(rigpwm) > 7000){
//		if(rigpwm > 0) rigpwm = 7000;
//		else rigpwm = -7000;
//	}
////	��������
//	if(lefpwm >= 0){//��ת
//		pwm_duty_updata(TIM_5, MOTOR_L1, lefpwm);     		
//		pwm_duty_updata(TIM_5, MOTOR_L0, 0);
//	}
//	else{//��ת
//		pwm_duty_updata(TIM_5, MOTOR_L1, 0);                      		
//		pwm_duty_updata(TIM_5, MOTOR_L0, -lefpwm);	
//	}
////	�ҵ������
//	if(rigpwm >= 0){
//		pwm_duty_updata(TIM_5, MOTOR_R1, rigpwm);     		
//		pwm_duty_updata(TIM_5, MOTOR_R0, 0);	
//	}
//	else{
//		pwm_duty_updata(TIM_5, MOTOR_R1, 0);                      		
//		pwm_duty_updata(TIM_5, MOTOR_R0, -rigpwm);	
//	}
}
