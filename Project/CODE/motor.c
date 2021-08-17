/*--------------------------------------------------------------*/
/*							头文件加载							*/
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
/*							  宏定义							*/
/*==============================================================*/
#define u8 unsigned char                                    //8位数据
#define u16 unsigned short                                  //16位数据
#define u32 unsigned int                                    //32位数据
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/
//unsigned char temp[4] = {0, 0, 0, 0};
/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
/*------------------------------*/
/*	     编码器值获取模块		*/
/*==============================*/
void encoder_get(void){

}
/*------------------------------*/
/*		   电机驱动模块			*/
/*==============================*/
void motor_act(void){
////	变量定义、初始化
//	short lefpwm, rigpwm;
//	lefpwm = acw.rs+lefdif.rs;
//	rigpwm = acw.rs+rigdif.rs;
////	限幅
//	if(abs(lefpwm) > 7000){
//		if(lefpwm > 0) lefpwm = 7000;
//		else lefpwm = -7000;
//	}
//	if(abs(rigpwm) > 7000){
//		if(rigpwm > 0) rigpwm = 7000;
//		else rigpwm = -7000;
//	}
////	左电机控制
//	if(lefpwm >= 0){//正转
//		pwm_duty_updata(TIM_5, MOTOR_L1, lefpwm);     		
//		pwm_duty_updata(TIM_5, MOTOR_L0, 0);
//	}
//	else{//反转
//		pwm_duty_updata(TIM_5, MOTOR_L1, 0);                      		
//		pwm_duty_updata(TIM_5, MOTOR_L0, -lefpwm);	
//	}
////	右电机控制
//	if(rigpwm >= 0){
//		pwm_duty_updata(TIM_5, MOTOR_R1, rigpwm);     		
//		pwm_duty_updata(TIM_5, MOTOR_R0, 0);	
//	}
//	else{
//		pwm_duty_updata(TIM_5, MOTOR_R1, 0);                      		
//		pwm_duty_updata(TIM_5, MOTOR_R0, -rigpwm);	
//	}
}
