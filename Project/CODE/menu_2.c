/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "menu.h"
#include "Init.h"
#include "menu_2.h"
#include "zf_pit.h"
#include "fontlib.h"
#include "menu_2init.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
//	һ���˵����
short calindex = 0;//һ���˵�һά����
//	�����˵�
char menu2_limit = 0;//�˵���ֵ
unsigned char menu2_mode = 0;//�˵�ģʽ
unsigned char *swflag;//�л���־λ
unsigned char swclearflag, swtemp;
//	��ֵ�޸����
short *shortvalue[5];
float *floatvalue[5];
//	�޸ı������
unsigned char magflag = 1;
unsigned char magindex = 1;
float mag[] = {10,1,0.1,0.01,0.001};
//----------------------------�ָ���----------------------------//
//	�����˵����	
unsigned char menu2flag = 1;//�μ��˵������־λ
unsigned char menu2mode = 0;//�˵���ʾģʽ
unsigned char fixedindex = 0;
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*------------------------------*/
/*		   ������Ϣ���			*/
/*==============================*/
static char info_found(unsigned char index, unsigned char num){
//	��������
	register unsigned char i;
	switch(index){
		case 1:
			switch(num){			
				case 0://������
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = ming0[i];
					return 3;
				case 1://����ֵ
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = zhi1[i];
					return 3;
				case 2://��������
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = bao0[i];
					for(i = 0; i < 32; i++) nom[96+i] = cun0[i];
					return 4;
				case 3://�ѱ���
					for(i = 0; i < 32; i++) nom[i] = yi0[i];
					for(i = 0; i < 32; i++) nom[32+i] = bao0[i];
					for(i = 0; i < 32; i++) nom[64+i] = cun0[i];
					return 3;
			}
			break;
		case 2:
			switch(num){
				case 0://ͨ��
					for(i = 0; i < 32; i++) nom[i] = tong0[i];
					for(i = 0; i < 32; i++) nom[32+i] = dao0[i];
					return 2;
				case 1://���ֵ
					for(i = 0; i < 32; i++) nom[i] = zui0[i];
					for(i = 0; i < 32; i++) nom[32+i] = da0[i];
					for(i = 0; i < 32; i++) nom[64+i] = zhi0[i];
					return 3;
				case 2://��Сֵ
					for(i = 0; i < 32; i++) nom[i] = zui0[i];
					for(i = 0; i < 32; i++) nom[32+i] = xiao0[i];
					for(i = 0; i < 32; i++) nom[64+i] = zhi0[i];
					return 3;
			}
		case 3:
			switch(num){
				case 0://��
					for(i = 0; i < 32; i++) nom[i] = kai0[i];
					return 1;
				case 1://��
					for(i = 0; i < 32; i++) nom[i] = guan0[i];
					return 1;
				case 2:
					for(i = 0; i < 32; i++) nom[i] = state1[i];
					return 1;
					break;
				case 3:
					for(i = 0; i < 32; i++) nom[i] = state0[i];
					return 1;
				case 4://����
					for(i = 0; i < 32; i++) nom[i] = gong0[i];
					for(i = 0; i < 32; i++) nom[32+i] = neng0[i];
					return 2;
				case 5://״̬
					for(i = 0; i < 32; i++) nom[i] = zhuang0[i];
					for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
					return 2;
				case 6://����
					for(i = 0; i < 32; i++) nom[i] = qi1[i];
					for(i = 0; i < 32; i++) nom[32+i] = yong0[i];
					return 2;
				case 7://�ر�
					for(i = 0; i < 32; i++) nom[i] = guan0[i];
					for(i = 0; i < 32; i++) nom[32+i] = bi1[i];
					return 2;
			}
	}
	return 0;
}
/*------------------------------*/
/*		   ��ֵ����ģ��			*/
/*==============================*/
void monitor(void){
//	��������
	register char i;
//	������ֵ
	for(i = 0; i < menu2_limit; i++) ips200_showint16(120, 15+i, *monitor_sv[i]);
}
/*------------------------------*/
/*		 ��ֵ��ʾ����ģ��		*/
/*==============================*/
static void menu2value_sup(void){
//	��������
	register char i;
//	��ֵ��ʾ
	switch(menu2_mode){
		case PARASET_F:
			ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0XFFFF);//�����ѱ�������
			ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);//������������
			for(i = 0; i < menu2_limit; i++) ips200_showfloat(120, 15+i, *floatvalue[i], 3, 3);
			return;
		case PARASET_S:
			ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0XFFFF);//�����ѱ�������
			ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);//������������
			for(i = 0; i < menu2_limit; i++) ips200_showint16(120, 15+i, *shortvalue[i]);
			return;
		case SWITCHER:
			for(i = 0; i < (menu2_limit+1); i++){
				if(*(swflag+i)){//����
					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);				
				}
				else{//�ر�
					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);	
				}
			}
			return;
	}
}
/*------------------------------*/
/*		 �˵�������ʾģ��		*/
/*==============================*/
void menu2value_hl(void){
	switch(menu2_mode){
		case PARASET_F:
			if(!menu2_index) ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);//��ʾ����
			else ips200_showfloat(120, 14+menu2_index, *floatvalue[menu2_index-1], 3, 3); 
			return;
		case PARASET_S:
			if(!menu2_index) ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);//��ʾ����
			else ips200_showint16(120, 14+menu2_index, *shortvalue[menu2_index-1]);
			return;
		case SWITCHER:
			if(*(swflag+menu2_index)) ips200_display_chinese(118, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XB7BD);
			else ips200_display_chinese(198, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XF5BA);
			return;
	}
}
/*------------------------------*/
/*		   ��ֵ��ʾģ��			*/
/*==============================*/
static void menu2value(void){
//	��ʾ����
	if(magflag) ips200_showfloat(180, 14, mag[magindex], 2, 3);
//	��ʾ��ֵ
	menu2value_sup();
//	������ֵ
	if(!menu2_level){
	//	ѡ��
		ips200_pencolor = 0xFFFF;
		ips200_bgcolor = 0xFDF8;
		menu2value_hl();
		ips200_pencolor = 0xB6DB;
		ips200_bgcolor = 0xFFFF;
	}
	else{
	//	�޸�
		ips200_pencolor = 0xFFFF;
		ips200_bgcolor = 0xAE9C;
		menu2value_hl();
		ips200_pencolor = 0xB6DB;
		ips200_bgcolor = 0xFFFF;
	}
}
/*------------------------------*/
/*		 ������Ϣ��ʾģ��		*/
/*==============================*/
void found_display(void){
	switch(menu2_mode){
		case PARASET_F:
		case PARASET_S:
		case MONITOR:
				ips200_display_chinese(0, 208, 16, nom, info_found(1, 0), 0XFDF8);//������
				ips200_display_chinese(120, 208, 16, nom, info_found(1, 1), 0XFDF8);//����ֵ
			return;
		case SWITCHER:
				ips200_display_chinese(0, 208, 16, nom, info_found(3, 4), 0XFDF8);
				ips200_display_chinese(150, 208, 16, nom, info_found(3, 5), 0XFDF8);
				ips200_display_chinese(110, 224, 16, nom, info_found(3, 6), 0XFDF8);
				ips200_display_chinese(190, 224, 16, nom, info_found(3, 7), 0XFDF8);
			return;
	}
}
/*------------------------------*/
/*		   ������ʾģ��			*/
/*==============================*/
void menu2_display(void){
//	��������
	register char i;
	if(!dis_str){//��ʾ����
		switch(menu2_mode){
			case PARASET_F:
			case PARASET_S:
			case MONITOR:
				for(i = 0; i < menu2_limit; i++) ips200_display_chinese(0, 240+i*16, 16, nom, amenu2_init_pfc[calindex](i+1), 0xB6DB); 
				return;
			case SWITCHER:
				for(i = 0; i < (menu2_limit+1); i++) ips200_display_chinese(0, 240+i*18, 16, nom, amenu2_init_pfc[calindex](i+1), 0xB6DB); 
				return;
		}
	}
	else{//��ʾ��ĸ
		switch(menu2_mode){
			case PARASET_F:
			case PARASET_S:
			case MONITOR:
				for(i = 0; i < menu2_limit; i++){
					amenu2_init_pfc[calindex](i+1);
					ips200_showstr(0, 15+i, menustr);
				} 
				return;
			case SWITCHER:
				for(i = 0; i < (menu2_limit+1); i++){
					amenu2_init_pfc[calindex](i+1);
					ips200_showstr(0, 15+i, menustr);
				} 
				return;
		}
	}
}
/*------------------------------*/
/*		 �����˵���ʼ��ģ��		*/
/*==============================*/
void menu2_init(void){
//	�������弰��ʼ��            
	register char i;
	calindex = 0, menu2_index = 0, magflag = 0, magindex = 1;
//	����
	ips200_clear(WHITE);
//	���ز˵�����
	for(i = 0; i < menu_index; i++) calindex += colimit[i];
    calindex += menu[menu_index];
//	ips200_showint16(0, 0, index);
	amenu2_init_pfc[calindex](0);
//	��ʼ���˵�
	switch(menu2_mode){
		case PARASET_F://��ֵ�޸Ĳ˵�
		case PARASET_S:
		//	Ԥ����
			menu2_index = 1;
			found_display();
			menu2_display();
			menu2value();
			return;
		case SWITCHER:
			menu2_index = 0;
			menu2_limit -= 1;
			found_display();
			menu2_display();
			menu2value();
			return;
		case MONITOR:
			menu2_index = 0;
			found_display();
			menu2_display();
			amenu2_init_pfc[calindex](MONITOR_ON);
			return;
	}
}
/*------------------------------*/
/*		   ��ֵ�޸�ģ��			*/
/*==============================*/
static void modify(unsigned char event){
	switch(menu2_mode){
		case PARASET_F:
			if(event) *floatvalue[menu2_index-1] += mag[magindex];//��ֵ����
			else *floatvalue[menu2_index-1] -= mag[magindex];//��ֵ����
			break;
		case PARASET_S:
			if(event) *shortvalue[menu2_index-1] += mag[magindex];
			else *shortvalue[menu2_index-1] -= mag[magindex];
			break;
	}
}
/*------------------------------*/
/*		 �����˵�ѡ��ģ��		*/
/*==============================*/
void menu2_select(unsigned char event){
//	��������
	register unsigned char i;
//	���ؼ�
	if(event == 3){
	//	����
		menu_level = 0;
		menu2_level = 0;
		magindex = 1;
		monitorflag = 0;
		menu_display();
		excollflag = 0;
		amenu2_init_pfc[calindex](MONITOR_OFF);//�رն�ʱ��
		return;
	}
	if(!menu2_level){
		switch(event){
			case 6://�Ұ���
				if(magindex < 4) magindex++;
				break;
			
			case 4://�󰴼�
				if(magindex > 0) magindex--; 
				break;
			
			case 2://�ϰ���
				if(menu2_index > 0) menu2_index--;
				break;
			
			case 5://�°���
				if(menu2_index < menu2_limit) menu2_index++;
				break;
			
			case 1://ȷ����
				switch(menu2_mode){
					case PARASET_F:
					case PARASET_S:
						if(!menu2_index){//��������
							ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0xAE9C);
							return;
						}
						else menu2_level = 1;
						break;
					case SWITCHER:
						if(swclearflag){
							swtemp = *(swflag+menu2_index);
							for(i = 0; i < (menu2_limit+1); i++) *(swflag+i) = 0;
							*(swflag+menu2_index) = !swtemp;
						}
						else *(swflag+menu2_index) = !(*(swflag+menu2_index));
						amenu2_init_pfc[calindex](FUNCTION);
						break;
				}
				break;
		}
	}
	else{
		switch(event){
			case 6://�Ұ���
				if(magindex < 4) magindex++;
				break;
			
			case 4://�󰴼�
				if(magindex > 0) magindex--; 
				break;
			
			case 2://�ϰ���
				modify(1);
				break;
			
			case 5://�°���
				modify(0);
				break;
			
			case 1://ȷ����
				menu2_level = 0;
				break;
		}
	}
//	�˵�����
	menu2value();
}
