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
/*		 ��ֵ�޸Ĳ˵�ģ��		*/
/*==============================*/
char init_model_mode_para(char index){//	��ֵ�޸Ĳ˵�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;//�Ƿ�ʹ����ĸ��ʾ
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = PARASET_F;
			menu2_limit = 0;
			magflag = 1;
		//	�޸���ֵ�ĵ�ַ
			floatvalue[0] = &cam_steering.Kp;
			shortvalue[0] = &spd;
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
/*		   ��ť�л�ģ��			*/
/*==============================*/
char init_model_mode_sw(char index){//	��ť�л�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;//�Ű����⣬���Ƽ�ʹ����ĸ
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = SWITCHER;
			menu2_limit = 3;
			magflag = 0;
			swclearflag = 0;//�Ƿ����������ѡ��־λ
		//	��־λ����
			swflag = csimenu_flag;
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
	//	����ִ�й��� | ��Ϊ�Ű����ⵥҳֻ֧���ĸ�����
		case FUNCTION:
			switch(menu2_index){
				case 0://��һ�а�������
					break;
			}
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		   	 ͼ����ʾ			*/
/*==============================*/
char menu2_imgdisplay(char index){
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
			menu2_mode = SWITCHER;
			menu2_limit = 3;
			magflag = 0;
			swclearflag = 1;
		//	��־λ����
			swflag = csimenu_flag;
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
		case FUNCTION://��������ִ��
			switch(menu2_index){
				case 0:
					break;
			}
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		   	 ת��PID			*/
/*==============================*/
char menu2_steeringPID(char index){
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 1;
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = PARASET_F;
			menu2_limit = 2;
			magflag = 1;
		//	�޸���ֵ�ĵ�ַ
			floatvalue[0] = &cam_steering.Kp;
			floatvalue[1] = &cam_steering.Kd;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1:
			strcpy(menustr, "Kp");
			return 0;
		case 2:
			strcpy(menustr, "Kd");
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		   	   ��̬				*/
/*==============================*/
char menu2_spdctrl(char index){
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = PARASET_S;
			menu2_limit = 3;
			magflag = 1;
		//	�޸���ֵ�ĵ�ַ
			shortvalue[0] = &spd_set;
			shortvalue[1] = &point_folrow;
			shortvalue[2] = &direction_fork_set;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://����
			for(i = 0; i < 32; i++) nom[i] = che0[i];
			for(i = 0; i < 32; i++) nom[32+i] = su0[i];
			return 2;
		case 2://׷�ٵ�
			for(i = 0; i < 32; i++) nom[i] = zhui0[i];
			for(i = 0; i < 32; i++) nom[32+i] = zong0[i];
			for(i = 0; i < 32; i++) nom[64+i] = dian1[i];
			return 3;
		case 3://ƽ���
			for(i = 0; i < 32; i++) nom[i] = ping0[i];
			for(i = 0; i < 32; i++) nom[32+i] = heng0[i];
			for(i = 0; i < 32; i++) nom[64+i] = dian1[i];
			return 3;
	}
	return 0;
}
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
//	��ʼ������ָ������
char(*amenu2_init_pfc[])(char) = {	menu2_imgdisplay, 
									menu2_steeringPID,
									menu2_spdctrl		};
//	��������
char dis_str = 0;
char menustr[20];
