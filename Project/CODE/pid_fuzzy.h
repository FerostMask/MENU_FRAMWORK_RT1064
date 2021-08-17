#ifndef PID_H_
#define PID_H_
#include "data.h"
typedef struct PID 
{
	float Kp; // 增量式积分系数
	float Ki; 
	float Kd;
	float T;
	
	float K1; // 增量式积分系数
	float K2; 
	float K3; 
	float LastError; //Error[-1]
	float PrevError; // Error[-2]
	float pwm_out;
	
	unsigned short flag;//温度状态标志位
}PID;

void PID_realize(struct pidpara *para);
#endif /* PID_H_ */
