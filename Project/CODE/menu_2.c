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
//	�����˵�
unsigned char menu2_limit = 0;//�˵���ֵ
unsigned char menu2_mode = 0;//�˵�ģʽ
//----------------------------�ָ���----------------------------//
//	�����˵����	
unsigned char menu2flag = 1;//�μ��˵������־λ
unsigned char menu2mode = 0;//�˵���ʾģʽ
unsigned char fixedindex = 0;
//	�޸ı������
unsigned char magflag = 1;
unsigned char magindex = 1;
float mag[] = {10,1,0.1,0.01,0.001};
//	��ֵ�޸����
short *shortvalue0, *shortvalue1, *shortvalue2, *shortvalue3, *shortvalue4;
float *floatvalue0, *floatvalue1, *floatvalue2, *floatvalue3, *floatvalue4;
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
/*		 ������Ϣ��ʾģ��		*/
/*==============================*/
void found_display(void){
	switch(menu2_mode){
		case PARASET:
				ips200_display_chinese(0, 208, 16, nom, info_found(1, 0), 0XFDF8);//������
				ips200_display_chinese(120, 208, 16, nom, info_found(1, 1), 0XFDF8);//����ֵ
			return;
	}
}
/*------------------------------*/
/*		   ������ʾģ��			*/
/*==============================*/
void menu2_display(short index){
//	��������
	register char i;
	if(!dis_str){//��ʾ����
		switch(menu2_mode){
			case PARASET:
				for(i = 0; i < menu2_limit; i++) ips200_display_chinese(0, 240+i*16, 16, nom, amenu2_init_pfc[index](i+1), 0xB6DB); 
				return;
		}
	}
	else{//��ʾ��ĸ
		switch(menu2_mode){
			case PARASET:
				for(i = 0; i < menu2_limit; i++){
					amenu2_init_pfc[index](i+1);
//					ips200_showstr(0, 15+i, menustr);
				} 
				return;
		}
	}
}
/*------------------------------*/
/*		 �����˵���ʼ��ģ��		*/
/*==============================*/
void menu2_init(void){
//	��������            
	register char i;
	short index = 0;
//	����
	ips200_clear(WHITE);
//	���ز˵�����
	for(i = 0; i < menu_index; i++) index += colimit[i];
    index += menu[menu_index];
	ips200_showint16(0, 0, index);
	amenu2_init_pfc[index](0);
//	��ʼ���˵�
	switch(menu2_mode){
		case PARASET://��ֵ�޸Ĳ˵�
			menu2_index = 1;
			found_display();
			menu2_display(index);
			return;
	}
}
//void menu2_init(void){
////	��ʼ����ֵ
//	menu2flag = 1;
//	magflag = 0;
//	menu2_index = 0;
////	��ʼ��ģ��
//	switch(menu_index){
//		case MENU_SWITCH:
//			magflag = 0;
//			menu2flag = 3;//�л�Ϊ����
//			switch(menu[menu_index]){
//				case 0:
//					menu2mode = 0;//��ʾҳ��0
//					menu2_limit = CSIMENU_FLAG-1;//��������
//					break;
//				case 1:
//					menu2mode = 1;//��ʾҳ��1
//					menu2_limit = RUN_FLAG-1;//��������
//					break;
//				case 2:
//					menu2mode = 2;//��ʾҳ��0
//					menu2_limit = FLASH_MEMORY_FLAG-1;//��������
//					break;
//			}
//			break;
//		case PARASET_PID:
//			menu2_index = 1;
//			switch(menu[menu_index]){
//				case 0://ת��
//					floatvalue0 = &cam_steering.Kp;
//					floatvalue1 = &cam_steering.Kd;
//					menu2_limit = 2;
//					menu2mode = 1;
//					magflag = 1;//������ֵ�޸�
//					break;
//				case 1://ģ��
//					floatvalue0 = &cam_steering.ei;
//					floatvalue1 = &cam_steering.e_bias;
//					floatvalue2 = &cam_steering.eci;
//					menu2_limit = 3;
//					menu2mode = 3;
//					magflag = 1;
//					break;
//			}
//			break;
//		case PARASET_OPER://��̬
//			menu2_index = 1;
//			switch(menu[menu_index]){
//				case 0:
//					shortvalue0 = &spd_set;
//					shortvalue1 = &point_folrow;
//					shortvalue2 = &direction_fork_set;
//					menu2_limit = 3;
//					menu2mode = 0;
//					magflag = 1;
//					break;
//				case 1://����ƫ��
//					shortvalue0 = &ring_lefbias;
//					shortvalue1 = &ring_rigbias;
//					shortvalue2 = &ring_outbias;
//					menu2_limit = 3;
//					menu2mode = 0;
//					magflag = 1;
//					break;
//			}
//			break;
//		case MONITOR_MENU://������
//		//	�����ж���ʾ
//			tim_interrupt_init(TIM_6, 40, 0, 3);
//			menu2flag = 2;
//			monitorflag = 1;
//			break;
//	}
//}
///*------------------------------*/
///*		   ��Ϣ���ģ��			*/
///*==============================*/
//static char info(unsigned char index, unsigned char num){
////	��������
//	register unsigned char i;
//	switch(index){
//		case MENU_SWITCH:
//			switch(num){
//				case 0://��ɫͼ��
//					for(i = 0; i < 32; i++) nom[i] = cai1[i];
//					for(i = 0; i < 32; i++) nom[32+i] = se0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
//					return 4;
//				case 1://�Ҷ�ͼ��
//					for(i = 0; i < 32; i++) nom[i] = hui0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = du0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
//					return 4;
//				case 2://״̬���
//					for(i = 0; i < 32; i++) nom[i] = zhuang0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = qing0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = chu0[i];
//					return 4;
//				case 10://��ʱ����
//					for(i = 0; i < 32; i++) nom[i] = yan0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = shi2[i];
//					for(i = 0; i < 32; i++) nom[64+i] = fa0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = che0[i];
//					return 4;
//				case 11://��
//					for(i = 0; i < 32; i++) nom[i] = zuo0[i];
//					return 1;
//				case 12://��
//					for(i = 0; i < 32; i++) nom[i] = you0[i];
//					return 1;
//				case 13://һ�Ŵ���
//					for(i = 0; i < 32; i++) nom[i] = yi1[i];
//					for(i = 0; i < 32; i++) nom[32+i] = hao0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = dai0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = ma0[i];
//					return 4;
//				case 14://���Ŵ���
//					for(i = 0; i < 32; i++) nom[i] = er0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = hao0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = dai0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = ma0[i];
//					return 4;
//				case 20://��������
//					for(i = 0; i < 32; i++) nom[i] = can0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = bao0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = cun0[i];
//					return 4;
//				case 21://������ԭ
//					for(i = 0; i < 32; i++) nom[i] = can0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = huan0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = yuan0[i];
//					return 4;
//			}
//		case PARASET_PID:
//			switch(num){

//			}
//			break;
//		case PARASET_OPER:
//			switch(num){
//				case 0://����
//					for(i = 0; i < 32; i++) nom[i] = che0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = su0[i];
//					return 2;
//				case 1://׷�ٵ�
//					for(i = 0; i < 32; i++) nom[i] = zhui0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = zong0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = dian1[i];
//					return 3;
//				case 2://ƽ���
//					for(i = 0; i < 32; i++) nom[i] = ping0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = heng0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = dian1[i];
//					return 3;
//				case 10://��ƫ��
//					for(i = 0; i < 32; i++) nom[i] = zuo0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = huan1[i];
//					for(i = 0; i < 32; i++) nom[64+i] = pian0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
//					return 4;
//				case 11://�һ�ƫ��
//					for(i = 0; i < 32; i++) nom[i] = you0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = huan1[i];
//					for(i = 0; i < 32; i++) nom[64+i] = pian0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
//					return 4;
//				case 12://����ƫ��
//					for(i = 0; i < 32; i++) nom[i] = chu1[i];
//					for(i = 0; i < 32; i++) nom[32+i] = huan1[i];
//					for(i = 0; i < 32; i++) nom[64+i] = pian0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
//					return 4;
//			}
//		case MONITOR_MENU:
//			switch(num){
//				case 0://������
//					for(i = 0; i < 32; i++) nom[i] = fu0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = yang0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = jiao0[i];
//					return 3;
//				case 1://�����
//					for(i = 0; i < 32; i++) nom[i] = hang0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = xiang0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = jiao0[i];
//					return 3;
//				case 2://����ת��
//					for(i = 0; i < 32; i++) nom[i] = zuo0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = lun0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = zhuan0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = su0[i];
//					return 4;
//				case 3://����ת��
//					for(i = 0; i < 32; i++) nom[i] = you0[i];
//					for(i = 0; i < 32; i++) nom[32+i] = lun0[i];
//					for(i = 0; i < 32; i++) nom[64+i] = zhuan0[i];
//					for(i = 0; i < 32; i++) nom[96+i] = su0[i];
//					return 4;
//			}
//	}
//	return 0;
//}
///*------------------------------*/
///*		 ��ֵ��ʾ����ģ��		*/
///*==============================*/
//static void menu2value_sup(void){
//	switch(menu_index){
//		case MENU_SWITCH:
//			swdisplay();
//			break;
//		case PARASET_PID:
//			switch(menu2mode){
//				case 0:
//					ips200_showstr(140, 14, "SET ALL");
//					ips200_showint16(100, 17, adc2.max);
//					ips200_showint16(170, 17, adc2.min);
//					break;
//				case 1:
//					ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);
//					ips200_showfloat(120, 15, *floatvalue0, 2, 3);
//					ips200_showfloat(120, 16, *floatvalue1, 2, 3);
//					break;
//				case 2:
//					ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);
//					ips200_showfloat(120, 15, *floatvalue0, 2, 3);
//					ips200_showfloat(120, 16, *floatvalue1, 2, 3);
//					ips200_showfloat(120, 17, *floatvalue2, 2, 3);
//					ips200_showfloat(120, 18, *floatvalue3, 2, 3);
//					break;
//				case 3:
//					ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);
//					ips200_showfloat(120, 15, *floatvalue0, 2, 3);
//					ips200_showfloat(120, 16, *floatvalue1, 2, 3);
//					ips200_showfloat(120, 17, *floatvalue2, 2, 3);
//					break;
//			}
//			break;
//		case PARASET_OPER:
//			switch(menu2mode){
//				case 0:
//					ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);
//					ips200_showint16(120, 15, *shortvalue0);
//					ips200_showint16(120, 16, *shortvalue1);
//					ips200_showint16(120, 17, *shortvalue2);
//					break;
//				case 1:
//					ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);
//					ips200_showint16(120, 15, *shortvalue0);
//					break;
//			}
//	}
//}
///*------------------------------*/
///*		 �˵�������ʾģ��		*/
///*==============================*/
//void menu2value_hl(void){
//	switch(menu_index){//������
//		case PARASET_PID:
//			switch(menu2mode){//ҳ��ѡ��
//				case 0:
//					if(excollflag == 6){
//						ips200_showint16(100, 17, adc2.max);
//						ips200_showint16(170, 17, adc2.min);
//					}
//					switch(menu2_index){
//						case 0:
//							ips200_showstr(140, 14, "SET ALL");
//							break;
//						case 3:
//							ips200_showint16(100, 17, adc2.max);
//							ips200_showint16(170, 17, adc2.min);
//							break;
//						}
//					break;
//				case 1:
//					switch(menu2_index){
//						case 0:ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);break;
//						case 1:ips200_showfloat(120, 15, *floatvalue0, 2, 3);break;
//						case 2:ips200_showfloat(120, 16, *floatvalue1, 2, 3);break;
//					}
//					break;
//				case 2:
//					switch(menu2_index){
//						case 0:ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);break;
//						case 1:ips200_showfloat(120, 15, *floatvalue0, 2, 3);break;
//						case 2:ips200_showfloat(120, 16, *floatvalue1, 2, 3);break;
//						case 3:ips200_showfloat(120, 17, *floatvalue2, 2, 3);break;
//						case 4:ips200_showfloat(120, 18, *floatvalue3, 2, 3);break;
//					}
//					break;
//				case 3:
//					switch(menu2_index){
//						case 0:ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);break;
//						case 1:ips200_showfloat(120, 15, *floatvalue0, 2, 3);break;
//						case 2:ips200_showfloat(120, 16, *floatvalue1, 2, 3);break;
//						case 3:ips200_showfloat(120, 17, *floatvalue2, 2, 3);break;
//					}
//			}
//			break;
//		case PARASET_OPER:
//			switch(menu2_index){
//				case 0:ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);break;
//				case 1:ips200_showint16(120, 15, *shortvalue0);break;
//				case 2:ips200_showint16(120, 16, *shortvalue1);break;
//				case 3:ips200_showint16(120, 17, *shortvalue2);break;
//			}
//			break;
//		}
//}
///*------------------------------*/
///*		   ��ֵ��ʾģ��			*/
///*==============================*/
//static void menu2value(void){
////	��ʾ����
//	if(magflag) ips200_showfloat(180, 14, mag[magindex], 2, 3);
////	��ʾ��ֵ
//	menu2value_sup();
////	������ֵ
//	if(!menu2_level){
//	//	ѡ��
//		ips200_pencolor = 0xFFFF;
//		ips200_bgcolor = 0xFDF8;
//		menu2value_hl();
//		ips200_pencolor = 0xB6DB;
//		ips200_bgcolor = 0xFFFF;
//	}
//	else{
//	//	�޸�
//		ips200_pencolor = 0xFFFF;
//		ips200_bgcolor = 0xAE9C;
//		menu2value_hl();
//		ips200_pencolor = 0xB6DB;
//		ips200_bgcolor = 0xFFFF;
//	}
//}
///*------------------------------*/
///*		   ������ʾģ��			*/
///*==============================*/
//void menu2_display(void){
////	����
//	ips200_clear(WHITE);
////	��ʾ����
//	switch(menu_index){
//		case MENU_SWITCH:
//			switch(menu2mode){
//			//	ҳ��ģ��ѡ��
//				case 0:
//					ips200_display_chinese(0, 208, 16, nom, info_found(3, 4), 0XFDF8);
//					ips200_display_chinese(150, 208, 16, nom, info_found(3, 5), 0XFDF8);
//					ips200_display_chinese(118, 224, 16, nom, info_found(3, 0), 0XFDF8);
//					ips200_display_chinese(198, 224, 16, nom, info_found(3, 1), 0XFDF8);
//					ips200_display_chinese(0, 240, 16, nom, info(menu_index, 0), 0xB6DB);
//					ips200_display_chinese(0, 258, 16, nom, info(menu_index, 1), 0xB6DB);
//					ips200_display_chinese(0, 276, 16, nom, info(menu_index, 2), 0xB6DB);
//					break;
//				case 1:
//					ips200_display_chinese(0, 208, 16, nom, info_found(3, 4), 0XFDF8);
//					ips200_display_chinese(150, 208, 16, nom, info_found(3, 5), 0XFDF8);
//					ips200_display_chinese(110, 224, 16, nom, info_found(3, 6), 0XFDF8);
//					ips200_display_chinese(190, 224, 16, nom, info_found(3, 7), 0XFDF8);
//					ips200_display_chinese(0, 240, 16, nom, info(menu_index, 10), 0xB6DB);
//					ips200_display_chinese(80, 240, 16, nom, info(menu_index, 11), 0xB6DB);
//					ips200_display_chinese(0, 258, 16, nom, info(menu_index, 10), 0xB6DB);
//					ips200_display_chinese(80, 258, 16, nom, info(menu_index, 12), 0xB6DB);
//					ips200_display_chinese(0, 276, 16, nom, info(menu_index, 13), 0xB6DB);
//					ips200_display_chinese(0, 294, 16, nom, info(menu_index, 14), 0xB6DB);
//					break;
//				case 2:
//					ips200_display_chinese(0, 208, 16, nom, info_found(3, 4), 0XFDF8);
//					ips200_display_chinese(150, 208, 16, nom, info_found(3, 5), 0XFDF8);
//					ips200_display_chinese(118, 224, 16, nom, info_found(3, 0), 0XFDF8);
//					ips200_display_chinese(198, 224, 16, nom, info_found(3, 1), 0XFDF8);
//					ips200_display_chinese(0, 240, 16, nom, info(menu_index, 20), 0xB6DB);
//					ips200_display_chinese(0, 258, 16, nom, info(menu_index, 21), 0xB6DB);
//					break;
//			}
//			break;
//		case PARASET_PID:
//			switch(menu2mode){
//				case 0:
//					ips200_display_chinese(0, 208, 16, nom, info_found(2, 0), 0XFDF8);//ͨ��
//					ips200_display_chinese(100, 208, 16, nom, info_found(2, 1), 0XFDF8);//���ֵ
//					ips200_display_chinese(170, 208, 16, nom, info_found(2, 2), 0XFDF8);//��Сֵ
//					ips200_showstr(0, 15, "ADC0");
//					ips200_showstr(0, 16, "ADC1");
//					ips200_showstr(0, 17, "ADC2");
//					ips200_showstr(0, 18, "ADC3");
//					ips200_showstr(0, 19, "ADC4");
//					break;
//				case 1:
//					ips200_display_chinese(0, 208, 16, nom, info_found(menu_index, 0), 0XFDF8);//MM32�ھֲ����鶨�����ʱ�ᵼ�½ṹ����������ǣ����Ե������û�����Ϣģ��
//					ips200_display_chinese(120, 208, 16, nom, info_found(menu_index, 1), 0XFDF8);
//					ips200_showstr(0, 15, "Kp");
//					ips200_showstr(0, 16, "Kd");
//					break;
//				case 2:
//					ips200_display_chinese(0, 208, 16, nom, info_found(menu_index, 0), 0XFDF8);
//					ips200_display_chinese(120, 208, 16, nom, info_found(menu_index, 1), 0XFDF8);
//					ips200_showstr(0, 15, "alpha");
//					ips200_showstr(0, 16, "beta");
//					ips200_showstr(0, 17, "omega");
//					ips200_showstr(0, 18, "P");
//					break;
//				case 3:
//					ips200_display_chinese(0, 208, 16, nom, info_found(menu_index, 0), 0XFDF8);
//					ips200_display_chinese(120, 208, 16, nom, info_found(menu_index, 1), 0XFDF8);
//					ips200_showstr(0, 15, "ei");
//					ips200_showstr(0, 16, "e_bias");
//					ips200_showstr(0, 17, "eci");
//					break;
//			}
//			break;
//		case PARASET_OPER:
//			switch(menu[menu_index]){
//				case 0:
//					ips200_display_chinese(0, 208, 16, nom, info_found(1, 0), 0XFDF8);
//					ips200_display_chinese(120, 208, 16, nom, info_found(1, 1), 0XFDF8);
//					ips200_display_chinese(0, 240, 16, nom, info(menu_index, 0), 0xB6DB);
//					ips200_display_chinese(0, 256, 16, nom, info(menu_index, 1), 0xB6DB);
//					ips200_display_chinese(0, 272, 16, nom, info(menu_index, 2), 0xB6DB);
//					break;
//				case 1:
//					ips200_display_chinese(0, 208, 16, nom, info_found(1, 0), 0XFDF8);
//					ips200_display_chinese(120, 208, 16, nom, info_found(1, 1), 0XFDF8);
//					ips200_display_chinese(0, 240, 16, nom, info(menu_index, 10), 0xB6DB);
//					ips200_display_chinese(0, 256, 16, nom, info(menu_index, 11), 0xB6DB);
//					ips200_display_chinese(0, 272, 16, nom, info(menu_index, 12), 0xB6DB);
//					break;
//			}
//			break;
//		case MONITOR_MENU:
//			switch(menu[menu_index]){
//				case 0:
//					ips200_showstr(0, 15, "error");
//					ips200_showstr(0, 16, "result");
//					break;
//				case 1:
//					ips200_display_chinese(0, 208, 16, nom, info_found(2, 0), 0XFDF8);//ͨ��
//					ips200_display_chinese(120, 208, 16, nom, info_found(1, 1), 0XFDF8);//����ֵ
//					ips200_showstr(0, 15, "ADC0");
//					ips200_showstr(0, 16, "ADC1");
//					ips200_showstr(0, 17, "ADC2");
//					ips200_showstr(0, 18, "ADC3");
//					ips200_showstr(0, 19, "ADC4");
//					break;
//			}
//			break;
//	}
////	��ʾ��ֵ
//	menu2value();
//} 
///*------------------------------*/
///*		   ��ֵ����ģ��			*/
///*==============================*/
//void monitor(void){
//	switch(menu[menu_index]){
//		case 0:
//			break;
//		case 1:
//			ips200_showuint8(120, 17, adc2.value);
//			break;
//	}
//}
///*------------------------------*/
///*		   �̶�����ģ��			*/
///*==============================*/
//void fixed_monitor(void){
//	switch(fixedindex){
//		case 0:
//		//	������ʾ
//			ips200_showstr(0, 0, "error");
//			ips200_showstr(0, 1, "result");
//		//	��ֵ��ʾ
////			ips200_showint16(120, 0, adc_err.rs);
////			ips200_showint16(120, 1, adc_steering.rs);
//			break;
//		case 1:
//		//	������ʾ
//			ips200_showstr(0, 0, "ADC0");
//			ips200_showstr(0, 1, "ADC1");
//			ips200_showstr(0, 2, "ADC2");
//			ips200_showstr(0, 3, "ADC3");
//			ips200_showstr(0, 4, "ADC4");
//		//	��ֵ��ʾ
//			ips200_showuint8(120, 2, adc2.value);
//			break;
//	}
//}
///*------------------------------*/
///*		   ��ť״̬ģ��			*/
///*==============================*/
//void swdisplay(void){
////	��������
//	register unsigned char i;
//	switch(menu[menu_index]){
//	//	��ť״̬
//		case 0:
//			for(i=0; i<CSIMENU_FLAG; i++){
//				if(csimenu_flag[i]){
//					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
//					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
//				}
//				else{
//					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
//					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
//				}
//			}
//			//	����ѡ��
//			if(csimenu_flag[menu2_index]) ips200_display_chinese(118, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XB7BD);
//			else ips200_display_chinese(198, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XF5BA);
//			break;
//		case 1:
//			for(i=0; i<RUN_FLAG; i++){
//				if(run_flag[i]){
//					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
//					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
//				}
//				else{
//					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
//					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
//				}
//			}
//			//	����ѡ��
//			if(run_flag[menu2_index]) ips200_display_chinese(118, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XB7BD);
//			else ips200_display_chinese(198, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XF5BA);
//			break;
//		case 2:
//			for(i=0; i<FLASH_MEMORY_FLAG; i++){
//				if(flash_memory_flag[i]){
//					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
//					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
//				}
//				else{
//					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
//					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
//				}
//			}
//			//	����ѡ��
//			if(flash_memory_flag[menu2_index]) ips200_display_chinese(118, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XB7BD);
//			else ips200_display_chinese(198, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XF5BA);
//			break;
//	}
//}
///*------------------------------*/
///*		   ��ť�л�ģ��			*/
///*==============================*/
//static void swmode(void){
////	��������
//	unsigned char temp, i;
////	���ز���
//	switch(menu[menu_index]){
//		case 0:
//		//	��������ִ��
//			if(menu2_index == 2){//���״̬
//				act_flag = 0, yawa_flag = 0, state_flag = 0, img_color = 0xAE9C;
//				cooling_flag = 1, total_count_fork = 0;
//				action_flag = 1, ring_out_flag = 0;
//				tim_interrupt_init_ms(TIM_3, 100, 0, 0);
//				csimenu_flag[menu2_index] = !csimenu_flag[menu2_index];
//				return;
//			}
//		//	�����˵���־λ
//			fixedflag = 0;
//			tim_interrupt_disabnle(TIM_6);
//			temp = csimenu_flag[menu2_index];
//			for(i=0; i<CSIMENU_FLAG; i++) csimenu_flag[i] = 0;
//			csimenu_flag[menu2_index] = !temp;
//			break;
//		case 1:
//			switch(menu2_index){
//				case 0://�����
//					run_flag[menu2_index] = 1;
//					run_flag[menu2_index+1] = 0;
////					act_flag = 56, state_flag = 5, img_color = 0XFD78;
//					yawa_flag = 1, yawa = 0;
//					action_flag = 0;
//					swdisplay();
//					return;
//				case 1://�ҳ���
//					run_flag[menu2_index-1] = 0;
//					run_flag[menu2_index] = 1;
////					act_flag = 55, state_flag = 5, img_color = 0XFD78;
//					yawa_flag = 1, yawa = 0;
//					action_flag = 0;
//					swdisplay();
//					return;
//				case 2://һ�Ŵ���
//					run_flag[menu2_index] = 1;
//					run_flag[menu2_index+1] = 0;
//					ctrl_pointer = 0;
//					code_select();
//					break;
//				case 3://���Ŵ���
//					run_flag[menu2_index-1] = 0;
//					run_flag[menu2_index] = 1;
//					ctrl_pointer = 1;
//					code_select();
//					break;
//			}
//			break;
//		case 2:
//			fixedflag = 0;
//			temp = flash_memory_flag[menu2_index];
//			for(i=0; i<FLASH_MEMORY_FLAG; i++) flash_memory_flag[i] = 0;
//			flash_memory_flag[menu2_index] = !temp;
//		//	ִ�а�������	
//			switch(menu2_index){
//				case 0:first_flash_init_pfc[ctrl_pointer]();break;
//				case 1:Init_para_pfc[ctrl_pointer]();break;
//			}
//			break;
//	}
//}
/*------------------------------*/
/*		   ��ֵ�޸�ģ��			*/
/*==============================*/
static void modify(unsigned char index, unsigned char event, unsigned char mode){
	switch(mode){
		case 1:
			if(event){
		//	��ֵ����
				switch(index){
					case 1:*floatvalue0+=mag[magindex];break;
					case 2:*floatvalue1+=mag[magindex];break;
					case 3:*floatvalue2+=mag[magindex];break;
					case 4:*floatvalue3+=mag[magindex];break;
					case 5:*floatvalue4+=mag[magindex];break;
				}
			}
		//	��ֵ����
			else{
				switch(index){
					case 1:*floatvalue0-=mag[magindex];break;
					case 2:*floatvalue1-=mag[magindex];break;
					case 3:*floatvalue2-=mag[magindex];break;
					case 4:*floatvalue3-=mag[magindex];break;
					case 5:*floatvalue4-=mag[magindex];break;
				}
			}
			break;
		case 2:
			if(event){
				switch(index){
					case 1: *shortvalue0+=mag[magindex];break;
					case 2: *shortvalue1+=mag[magindex];break;
					case 3: *shortvalue2+=mag[magindex];break;
					case 4: *shortvalue3+=mag[magindex];break;
					case 5: *shortvalue4+=mag[magindex];break;
				}
			}
			else{
				switch(index){
					case 1: *shortvalue0-=mag[magindex];break;
					case 2: *shortvalue1-=mag[magindex];break;
					case 3: *shortvalue2-=mag[magindex];break;
					case 4: *shortvalue3-=mag[magindex];break;
					case 5: *shortvalue4-=mag[magindex];break;
				}
			}
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
		menu2_level = 0;
		magindex = 1;
		monitorflag = 0;
		menu_level = 0;
		menu_display();
		excollflag = 0;
	//	������ʱ��
//		tim_interrupt_init_ms(TIM_2, 2, 0, 0);//�����ɼ�ͨ��
//		if(!fixedflag) tim_interrupt_disabnle(TIM_6);//���̶���ʾ��رռ���ͨ��
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
//				switch(menu2flag){
//					case 1://	��ֵ�޸�
//						if(!menu2_index){
//							flash_memory_write_pfc[ctrl_pointer](menu_index, menu[menu_index]);
//							ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0xAE9C);
//						}
//						else
//							menu2_level = 1;
//						break;
//					case 2://	�������̶���ʾ
//						fixedflag = !fixedflag;
//						fixedindex = menu[menu_index];
//						if(fixedflag) for(i=0; i<CSIMENU_FLAG; i++) csimenu_flag[i] = 0;//�ر�ͼ����ʾ
//						break;
//					case 3://	��ť
//						swmode();
//						swdisplay();
//						break;
//					case 0:break;
//				}
				break;
		}
//		menu2value();
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
				modify(menu2_index, 1, menu_index);
				break;
			
			case 5://�°���
				modify(menu2_index, 0, menu_index);
				break;
			
			case 1://ȷ����
				menu2_level = 0;
				break;
		}
//		menu2value();
	}
}