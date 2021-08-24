/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "menu.h"
#include "Init.h"
#include "zf_adc.h"
#include "zf_pwm.h"
#include "zf_gpio.h"
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

/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*------------------------------*/
/*		 ��������ʼ��ģ��		*/
/*==============================*/
void Init_encoder(void){
//	���������ų�ʼ��	
//	tim_encoder_init(TIM_3, TIM_3_ENC1_B04, TIM_3_ENC2_B05);
//	tim_encoder_init(TIM_4, TIM_4_ENC1_B06, TIM_4_ENC2_B07);
}
/*------------------------------*/
/*		  �����ʼ��ģ��		*/
/*==============================*/
void Init_motor(void){
//	�˿ڳ�ʼ��
//	������ų�ʼ�� Ĭ��Ƶ��17kHz ��ʼռ�ձ� 0%
	pwm_init(MOTOR_LS, 17000, 10000);
	gpio_init(MOTOR_LD, GPO, 1, GPIO_PIN_CONFIG);
	pwm_init(MOTOR_RS, 17000, 10000);
	gpio_init(MOTOR_RD, GPO, 1, GPIO_PIN_CONFIG);
//	������ų�ʼ�� Ĭ��Ƶ��100Hz ��ʼռ�ձ� 15%
	pwm_init(STEER_PIN, 100, 1500);
}
/*------------------------------*/
/*		  ������ʼ��ģ��		*/
/*==============================*/
void Init_button(void){
//	�����жϳ�ʼ�� | ������ȼ�
	gpio_interrupt_init(KEY1, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY2, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY3, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY4, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY5, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY6, FALLING, GPIO_INT_CONFIG);
}
