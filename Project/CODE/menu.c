/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "menu.h"
#include "Init.h"
#include "menu_2.h"
#include "string.h"
#include "fontlib.h"
#include "zf_gpio.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
//	�˵�����
unsigned char menu[ROWS] = {0};
//	��ֵ����
unsigned char colimit[ROWS] = { 3,
								2,
								1,
								1 };
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/

//----------------------------�ָ���----------------------------//
/*--------------------------------------------------------------*/
/* 							 һ���˵� 							*/
/*==============================================================*/
/*------------------------------*/
/*		 �˵���Ϣ�洢ģ��		*/
/*==============================*/
static char info(char index, char num){
//	��������
	register unsigned char i;
//	������
	switch(index){
		case 0:
		//	������
			switch(num){
				case 0://ͼ����ʾ
					for(i = 0; i < 32; i++) nom[i] = tu0[i];
					for(i = 0; i < 32; i++) nom[32+i] = xiang1[i];
					for(i = 0; i < 32; i++) nom[64+i] = xian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = shi1[i];
					return 4;
				case 1://��������
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = she0[i];
					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
					return 4;
				case 2://����
					for(i = 0; i < 32; i++) nom[i] = fa0[i];
					for(i = 0; i < 32; i++) nom[32+i] = che0[i];
					return 2;
			}
			break;
		case 1:
			switch(num){
				case 0://ת��
					for(i = 0; i < 32; i++) nom[i] = zhuan0[i];
					for(i = 0; i < 32; i++) nom[32+i] = xiang0[i];
					return 2;
				case 1://ģ��
					for(i = 0; i < 32; i++) nom[i] = mo0[i];
					for(i = 0; i < 32; i++) nom[32+i] = hu0[i];
					return 2;
				case 2://��ȺͲ�
					for(i = 0; i < 32; i++) nom[i] = cha0[i];
					for(i = 0; i < 32; i++) nom[32+i] = bi0[i];
					for(i = 0; i < 32; i++) nom[64+i] = he0[i];
					for(i = 0; i < 32; i++) nom[96+i] = cha0[i];
					return 4;
			}
			break;
		case 2:
			switch(num){
				case 0://��̬
					for(i = 0; i < 32; i++) nom[i] = zi0[i];
					for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
					return 2;
				case 1://����ƫ��
					for(i = 0; i < 32; i++) nom[i] = huan1[i];
					for(i = 0; i < 32; i++) nom[32+i] = dao0[i];
					for(i = 0; i < 32; i++) nom[64+i] = pian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
					return 4;
			}
			break;
		case 3:
			switch(num){
				case 0://������
					for(i = 0; i < 32; i++) nom[i] = wu0[i];
					for(i = 0; i < 32; i++) nom[32+i] = cha0[i];
					for(i = 0; i < 32; i++) nom[64+i] = jian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = shi0[i];
					return 4;
				case 1://��ż���
					for(i = 0; i < 32; i++) nom[i] = dian0[i];
					for(i = 0; i < 32; i++) nom[32+i] = ci0[i];
					for(i = 0; i < 32; i++) nom[64+i] = jian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = shi0[i];
					return 4;
			}
			break; 
		case 100://�˵�
			for(i = 0; i < 32; i++) nom[i] = cai0[i];
			for(i = 0; i < 32; i++) nom[32+i] = dan0[i];
			return 2;
	}
	return 0;
}
/*------------------------------*/
/*		   �˵���ʾģ��			*/
/*==============================*/
void menu_display(void){
//	��������
	char show_index[ROWS];
//	����
	ips200_clear(WHITE);
//	������ʾ����
	if(menu_index-1<0) show_index[0] = ROWS-1;
	else show_index[0] = menu_index - 1;

	show_index[1] = menu_index;

	if(menu_index+1>ROWS-1) show_index[2] = 0,show_index[3] = 1;
	else if(menu_index+2>ROWS-1) show_index[2] = menu_index+1,show_index[3] = 0;
	else show_index[2] = menu_index+1,show_index[3] = menu_index+2;
//	�˵���ʾ
	ips200_display_chinese(0, 208, 16, nom, info(100, menu[show_index[0]]), 0XFDF8);
	ips200_display_chinese(30, 224, 16, nom, info(show_index[0], menu[show_index[0]]), 0xB6DB);
	
	ips200_display_chinese(40, 256, 16, nom, info(show_index[1], menu[show_index[1]]), 0xB6DB);
	ips200_showint32(120, 16, menu_index, 1);
	
	ips200_display_chinese(20, 288, 16, nom, info(show_index[2], menu[show_index[2]]), 0xB6DB);
	ips200_display_chinese(0, 304, 16, nom, info(show_index[3], menu[show_index[3]]), 0xB6DB);
}
/*------------------------------*/
/*		 һ���˵��¼�ģ��		*/
/*==============================*/
void menu_select(unsigned char event){
//	һ���˵�
	if(!menu_level){
	//	�˵��¼���֧
		switch(event){
			case 6://�Ұ���
				if(menu[menu_index] < (colimit[menu_index]-1)) menu[menu_index]++;
				else return;
				break;
			
			case 4://�󰴼�
				if(menu[menu_index] > 0) menu[menu_index]--;
				else return;
				break;
			
			case 2://�ϰ���
				if(menu_index>0) menu_index--;
				else menu_index = ROWS-1;
				break;
			
			case 5://�°���
				if(menu_index<ROWS-1) menu_index++;
				else menu_index = 0;
				break;
			
			case 1://ȷ����
			//	��ʼ�������˵�
				menu2_init();
				menu_level = 1;
				return;
			case 3://���ؼ�
				menu[menu_index] = 0;
				break;
		}
		menu_display();
	}
}
