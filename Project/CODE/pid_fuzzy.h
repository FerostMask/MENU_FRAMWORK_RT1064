#ifndef PID_H_
#define PID_H_
#include "data.h"
typedef struct PID 
{
	float Kp; // ����ʽ����ϵ��
	float Ki; 
	float Kd;
	float T;
	
	float K1; // ����ʽ����ϵ��
	float K2; 
	float K3; 
	float LastError; //Error[-1]
	float PrevError; // Error[-2]
	float pwm_out;
	
	unsigned short flag;//�¶�״̬��־λ
}PID;

void PID_realize(struct pidpara *para);
#endif /* PID_H_ */
