/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "menu.h"
#include "Init.h"
#include "zf_adc.h"
#include "zf_pwm.h"
#include "zf_gpio.h"
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

/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
/*------------------------------*/
/*		 编码器初始化模块		*/
/*==============================*/
void Init_encoder(void){
//	编码器引脚初始化	
//	tim_encoder_init(TIM_3, TIM_3_ENC1_B04, TIM_3_ENC2_B05);
//	tim_encoder_init(TIM_4, TIM_4_ENC1_B06, TIM_4_ENC2_B07);
}
/*------------------------------*/
/*		  电机初始化模块		*/
/*==============================*/
void Init_motor(void){
//	端口初始化
//	电机引脚初始化 默认频率17kHz 初始占空比 0%
	pwm_init(MOTOR_LS, 17000, 10000);
	gpio_init(MOTOR_LD, GPO, 1, GPIO_PIN_CONFIG);
	pwm_init(MOTOR_RS, 17000, 10000);
	gpio_init(MOTOR_RD, GPO, 1, GPIO_PIN_CONFIG);
//	舵机引脚初始化 默认频率100Hz 初始占空比 15%
	pwm_init(STEER_PIN, 100, 1500);
}
/*------------------------------*/
/*		  按键初始化模块		*/
/*==============================*/
void Init_button(void){
//	按键中断初始化 | 最低优先级
	gpio_interrupt_init(KEY1, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY2, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY3, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY4, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY5, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(KEY6, FALLING, GPIO_INT_CONFIG);
}
