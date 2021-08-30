/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "menu_2init.h"
#include "zf_pit.h"
#include "fontlib.h"
#include "menu_2.h"
#include "string.h"
#include "data.h"
#include "para_flash.h"
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
			flash_index = 0;//��ֵ��flash��ַ
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
		case ORING_VALUE://�趨������ʼֵ
			return 0;
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
			menu2_mode = BUTTONSW;
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
/*		  �������˵�ģ��		*/
/*==============================*/
char init_model_mode_monitor(char index){//	��ֵ�޸Ĳ˵�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;//�Ƿ�ʹ����ĸ��ʾ
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = MONITOR;
			menu2_limit = 0;
			magflag = 0;
		//	�޸���ֵ�ĵ�ַ
			monitor_sv[0] = &pita;
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
		case MONITOR_ON://������ʱ��
			pit_interrupt_ms(PIT_CH3, 100);
			return 0;
		case MONITOR_OFF://�رն�ʱ��
			pit_close(PIT_CH3);
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
			menu2_mode = BUTTONSW;
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
/*		   	   ����				*/
/*==============================*/
char menu2_start(char index){//	��ť�л�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;//�Ű����⣬���Ƽ�ʹ����ĸ
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = BUTTONSW;
			menu2_limit = 1;
			magflag = 0;
			swclearflag = 1;//�Ƿ����������ѡ��־λ
		//	��־λ����
			swflag = run_flag;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://��ʱ����
			for(i = 0; i < 32; i++) nom[i] = yan0[i];
			for(i = 0; i < 32; i++) nom[32+i] = shi2[i];
			for(i = 0; i < 32; i++) nom[64+i] = fa0[i];
			for(i = 0; i < 32; i++) nom[96+i] = che0[i];
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
/*		   	 ��������			*/
/*==============================*/
char menu2_flashmemory(char index){
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
			menu2_mode = BUTTONSW;
			menu2_limit = 2;
			magflag = 0;
			swclearflag = 1;
		//	��־λ����
			swflag = &fm_flag[0];
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://��������
			for(i = 0; i < 32; i++) nom[i] = can0[i];
			for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
			for(i = 0; i < 32; i++) nom[64+i] = bao0[i];
			for(i = 0; i < 32; i++) nom[96+i] = cun0[i];
			return 4;
		case 2://������ԭ
			for(i = 0; i < 32; i++) nom[i] = can0[i];
			for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
			for(i = 0; i < 32; i++) nom[64+i] = huan0[i];
			for(i = 0; i < 32; i++) nom[96+i] = yuan0[i];
			return 4;
		case FUNCTION://��������ִ��
			switch(menu2_index){
				case 0:
					para_saveall();
					break;
				case 1:
					para_reset(0);
					break;
			}
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		 	 ģ��PID			*/
/*==============================*/
char menu2_PIDfuzzy(char index){//	��ֵ�޸Ĳ˵�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 1;//�Ƿ�ʹ����ĸ��ʾ
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = PARASET_F;
			menu2_limit = 3;
			magflag = 1;
		//	�޸���ֵ�ĵ�ַ
			floatvalue[0] = &cam_steering.ei;
			floatvalue[1] = &cam_steering.e_bias;
			floatvalue[2] = &cam_steering.eci;
			flash_index = 2;//��ֵ��flash��ַ
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://��һ������ | ��ĸ����
			strcpy(menustr, "ei");
			return 0;
		case 2://��һ������ | ��ĸ����
			strcpy(menustr, "e_bias");
			return 0;
		case 3://��һ������ | ��ĸ����
			strcpy(menustr, "eci");
			return 0;
		case ORING_VALUE://�趨������ʼֵ
			cam_steering.ei = 10.0;
			cam_steering.e_bias = 2.5;
			cam_steering.eci = 15.0;
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
			flash_index = 0;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1:
			strcpy(menustr, "Kp");
			return 0;
		case 2:
			strcpy(menustr, "Kd");
			return 0;
		case ORING_VALUE:
			cam_steering.Kp = 2.3;
			cam_steering.Kd = 0.05;
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
			flash_index = 1;
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
		case ORING_VALUE:
			spd_set = 150;
			point_folrow = 57;
			direction_fork_set = 0;
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		     ��̬����			*/
/*==============================*/
char menu2_spdmonitor(char index){//	��ֵ�޸Ĳ˵�ģ��
//	�������弰��ʼ��
	register unsigned char i;
	dis_str = 0;//�Ƿ�ʹ����ĸ��ʾ
//	��Ϣ����
	switch(index){
	//	�˵����Գ�ʼ��
		case 0:
		//	�˵�����
			menu2_mode = MONITOR;
			menu2_limit = 2;
			magflag = 0;
		//	�޸���ֵ�ĵ�ַ
			monitor_sv[0] = &pita;
			monitor_sv[1] = &yawa;
			return 0;
	//	�˵����Ƴ�ʼ��
		case 1://������
			for(i = 0; i < 32; i++) nom[i] = fu0[i];
			for(i = 0; i < 32; i++) nom[32+i] = yang0[i];
			for(i = 0; i < 32; i++) nom[64+i] = jiao0[i];
			return 3;
		case 2://�����
			for(i = 0; i < 32; i++) nom[i] = hang0[i];
			for(i = 0; i < 32; i++) nom[32+i] = xiang0[i];
			for(i = 0; i < 32; i++) nom[64+i] = jiao0[i];
			return 3;
		case 3://����ת��
			for(i = 0; i < 32; i++) nom[i] = zuo0[i];
			for(i = 0; i < 32; i++) nom[32+i] = lun0[i];
			for(i = 0; i < 32; i++) nom[64+i] = zhuan0[i];
			for(i = 0; i < 32; i++) nom[96+i] = su0[i];
			return 4;
		case 4://����ת��
			for(i = 0; i < 32; i++) nom[i] = you0[i];
			for(i = 0; i < 32; i++) nom[32+i] = lun0[i];
			for(i = 0; i < 32; i++) nom[64+i] = zhuan0[i];
			for(i = 0; i < 32; i++) nom[96+i] = su0[i];
			return 4;
		case MONITOR_ON://������ʱ��
			pit_interrupt_ms(PIT_CH3, 100);
			return 0;
		case MONITOR_OFF://�رն�ʱ��
			pit_close(PIT_CH3);
			return 0;
	}
	return 0;
}
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
//	��ʼ������ָ������
char(*amenu2_init_pfc[])(char) = {	menu2_imgdisplay, menu2_flashmemory, menu2_start, 
									menu2_steeringPID, menu2_PIDfuzzy,
									menu2_spdctrl,
									menu2_spdmonitor	};
//	��������
unsigned char flash_index = 0;
char dis_str = 0;
char menustr[20];
