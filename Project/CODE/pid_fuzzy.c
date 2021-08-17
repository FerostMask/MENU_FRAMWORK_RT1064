#include <string.h>     
#include <stdio.h> 
#include <math.h>
#include "pid_fuzzy.h"

//ע1������Ӧģ��pid����Ҫ�ľ��������ѡ��Ҫ����Ӧ�ÿ��ƵĶ������к�
//ע2�����¸���ֵ���޷�ֵ�����ֵ����Ҫ���ݾ����ʹ��������и���
//ע3����Ϊ�ҵĿ��ƶ�����ԱȽϴ��������¸�����ȡֵ��С
//����e:[-5,5]  ec:[-0.5,0.5]

//���ķ�ֵ��С�������ֵ��ʱ�򣬲���PID��������������СʱƵ������������
#define Emax 5

#define NB 0
#define NM 1
#define NS 2
#define ZO 3
#define PS 4
#define PM 5
#define PB 6

int kp[7][7]={	{PB,PB,PM,PM,PS,ZO,ZO},
				{PB,PB,PM,PS,PS,ZO,ZO},
				{PM,PM,PM,PS,ZO,NS,NS},
				{PM,PM,PS,ZO,NS,NM,NM},
				{PS,PS,ZO,NS,NS,NM,NM},
				{PS,ZO,NS,NM,NM,NM,NB},
				{ZO,ZO,NM,NM,NM,NB,NB}    };

int kd[7][7]={	{PS,NS,NB,NB,NB,NM,PS},
				{PS,NS,NB,NM,NM,NS,ZO},
				{ZO,NS,NM,NM,NS,NS,ZO},
				{ZO,NS,NS,NS,NS,NS,ZO},
				{ZO,ZO,ZO,ZO,ZO,ZO,ZO},
				{PB,NS,PS,PS,PS,PS,PB},
				{PB,PM,PM,PM,PS,PS,PB}    };

int ki[7][7]={	{NB,NB,NM,NM,NS,ZO,ZO},
				{NB,NB,NM,NS,NS,ZO,ZO},
				{NB,NM,NS,NS,ZO,PS,PS},
				{NM,NM,NS,ZO,PS,PM,PM},
				{NM,NS,ZO,PS,PS,PM,PB},
				{ZO,ZO,PS,PS,PM,PB,PB},
				{ZO,ZO,PS,PM,PM,PB,PB}    };

/**************�������ȣ������Σ�***************/
float FTri(float x,float a,float b,float c)//FuzzyTriangle
{
	if(x<=a)
		return 0;
	else if((a<x)&&(x<=b))
		return (x-a)/(b-a);
	else if((b<x)&&(x<=c))
		return (c-x)/(c-b);
	else if(x>c)
		return 0;
	else
		return 0;
}
/*****************�������ȣ�������*******************/
float FTraL(float x,float a,float b)//FuzzyTrapezoidLeft
{
	if(x<=a)  
		return 1;
	else if((a<x)&&(x<=b))
		return (b-x)/(b-a);
	else if(x>b)
		return 0;
	else
		return 0;
}
/*****************�������ȣ������ң�*******************/
float FTraR(float x,float a,float b)//FuzzyTrapezoidRight
{
	if(x<=a)
		return 0;
	if((a<x)&&(x<b))
		return (x-a)/(b-a);
	if(x>=b)
		return 1;
	else
		return 1;
}
/****************�����η�ģ��������**********************/
float uFTri(float x,float a,float b,float c)
{ 
	float y,z;
	z=(b-a)*x+a;
	y=c-(c-b)*x;
	return (y+z)/2;
}
/*******************���Σ��󣩷�ģ����***********************/
float uFTraL(float x,float a,float b)
{
	return b-(b-a)*x;
}
/*******************���Σ��ң���ģ����***********************/
float uFTraR(float x,float a,float b)
{
	return (b-a)*x +a;
}
/**************************�󽻼�****************************/
float fand(float a,float b)
{
	return (a<b)?a:b;
}
/**************************�󲢼�****************************/
float forr(float a,float b)
{
	return (a<b)?b:a;
}
/*===================   PID���㲿��   ======================*/   
void PID_realize(struct pidpara *para){
	//���������ȱ�
	float e, ec;
	register unsigned char i=0, j=0;
	unsigned char MaxX=0, MaxY=0;
	
	//��¼������������Ӧ������p��i��dֵ
	float lsd;
	int temp_p;
	
	e = -(fabs(para->e1/para->ei)-para->e_bias);
	ec = (para->e1 - para->e2)/para->eci;	
//���¶Ȳ�ľ���ֵС��Emaxʱ����pid�Ĳ������е���
	//����iError��es��ecs�и����������
	es[NB]=FTraL(e,-3,-1);  //e 
	es[NM]=FTri(e,-3,-2,0);
	es[NS]=FTri(e,-3,-1,1);
	es[ZO]=FTri(e,-2,0,2);
	es[PS]=FTri(e,-1,1,3);
	es[PM]=FTri(e,0,2,3);
	es[PB]=FTraR(e,1,3);

	ecs[NB]=FTraL(ec,-3,-1);//ec
	ecs[NM]=FTri(ec,-3,-2,0);
	ecs[NS]=FTri(ec,-3,-1,1);
	ecs[ZO]=FTri(ec,-2,0,2);
	ecs[PS]=FTri(ec,-1,1,3);
	ecs[PM]=FTri(ec,0,2,3);
	ecs[PB]=FTraR(ec,1,3);
	
	//���������ȱ�ȷ��e��ec�����������������ȵ�ֵ
	for(i=0;i<7;i++)
		for(j=0;j<7;j++)
			form[i][j]=fand(es[i],ecs[j]);
//	ȡ��������������ȵ���һ��
	for(i=0;i<7;i++)
		for(j=0;j<7;j++)
			if(form[MaxX][MaxY]<form[i][j])
				MaxX=i, MaxY=j;
//	����ģ��������ȥģ��
	lsd=form[MaxX][MaxY];
	temp_p=kp[MaxX][MaxY];
	
	if(temp_p==NB)
		para->detKp = uFTraL(lsd,-0.3,-0.1);
	else if(temp_p==NM)
		para->detKp = uFTri(lsd,-0.3,-0.2,0);
	else if(temp_p==NS)
		para->detKp = uFTri(lsd,-0.3,-0.1,0.1);
	else if(temp_p==ZO)
		para->detKp = uFTri(lsd,-0.2,0,0.2);
	else if(temp_p==PS)
		para->detKp = uFTri(lsd,-0.1,0.1,0.3);
	else if(temp_p==PM)
		para->detKp = uFTri(lsd,0,0.2,0.3);
	else if(temp_p==PB)
		para->detKp = uFTraR(lsd,0.1,0.3);
		
//	��detKp�����޷�
	if(para->detKp < -0.5) para->detKp = -0.5;
	if(para->detKp >  0.5) para->detKp = 0.5;
}
