/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "menu_2init.h"
#include "fontlib.h"
#include "menu_2.h"
#include "string.h"
#include "data.h"
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*------------------------------*/
/*		   	 �˵�ģ��			*/
/*==============================*/
char init_model_mode0(char index){//	��ֵ�޸Ĳ˵�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = 0;
			menu2_limit = 0;
		//	�޸���ֵ�ĵ�ַ
			floatvalue0 = &cam_steering.Kp;
			shortvalue0 = &spd;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://��һ������ | ��ĸ����
			strcpy(menustr, "hello");
			return 0;
		case 2://�ڶ������� | ��������
			for(i = 0; i < 32; i++) nom[i] = cai1[i];
			for(i = 0; i < 32; i++) nom[32+i] = se0[i];
			for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
			for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
			return 4;//��������
	}
	return 0;
}
/*------------------------------*/
/*		   	 ͼ����ʾ			*/
/*==============================*/
char menu2_imgdisplay(char index){//	��ֵ�޸Ĳ˵�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
			menu2_mode = PARASET;
			menu2_limit = 3;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://��ɫͼ��
			for(i = 0; i < 32; i++) nom[i] = cai1[i];
			for(i = 0; i < 32; i++) nom[32+i] = se0[i];
			for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
			for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
			return 4;
		case 2://�Ҷ�ͼ��
			for(i = 0; i < 32; i++) nom[i] = hui0[i];
			for(i = 0; i < 32; i++) nom[32+i] = du0[i];
			for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
			for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
			return 4;
		case 3://״̬���
			for(i = 0; i < 32; i++) nom[i] = zhuang0[i];
			for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
			for(i = 0; i < 32; i++) nom[64+i] = qing0[i];
			for(i = 0; i < 32; i++) nom[96+i] = chu0[i];
			return 4;
	}
	return 0;
}
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
//	��ʼ������ָ������
char(*amenu2_init_pfc[])(char) = {menu2_imgdisplay};
//	��������
char dis_str = 0;
char menustr[40];
