#ifndef _DATA_H
#define _DATA_H
//#include "menu.h"
//#include "menu_2.h"
#include "SEEKFREE_MT9V03X.h"
#include "SEEKFREE_MT9V03X_CSI.h"
/*--------------------------------------------------------------*/
/*							  �궨��							*/
/*==============================================================*/
//	����ͷ
#define EFF_ROW 54
//	flash�����洢
#define FLASH_NUM 11
#define FLASH_NUM1 11
#define FLASH_MEMORY_SLECTION FLASH_SECTION_112
#define FLASH_MEMORY_SLECTION1 FLASH_SECTION_122
/*------------------------------------------------------*/
/* 					  �ⲿ�������� 						*/
/*======================================================*/
/*----------------------*/
/*	 	����ͷģ��		*/
/*======================*/
//	��򷨶�ֵ��
extern float P[256], PK[256], MK[256];
extern unsigned char binary_img[MT9V03X_H][(MT9V03X_W-4)/8];
extern unsigned char img_thrsod;
//	��׼��Ѱ��
extern unsigned char found_point[4];
extern unsigned char fop_flag;
extern unsigned char border_flag;
//	ˮƽ����Ѱ��
extern unsigned char lefbor[MT9V03X_H], rigbor[MT9V03X_H], mid_point[MT9V03X_H];
extern unsigned char ltraf_point_row[10], rtraf_point_row[10], ltraf_point_col[10], rtraf_point_col[10];
extern unsigned char ltraf_flag[10], rtraf_flag[10];
extern unsigned char lcut, rcut;
extern unsigned char ltraf_count, rtraf_count;
//	��ֱ����Ѱ��
extern unsigned char topbor[MT9V03X_W-4], bottombor[MT9V03X_W-4];//���±���
extern unsigned char lvet_trafpoint_row[5], rvet_trafpoint_row[5], lvet_trafpoint_col[5], rvet_trafpoint_col[5];
extern unsigned char lvet_trafcount, rvet_trafcount;
extern unsigned char leftop_cut, lefbottom_cut, rigtop_cut, rigbottom_cut;//��ֹ��
extern unsigned char exti_lefp[4], exti_rigp[4], exti_lefcount, exti_rigcount;
//	״̬��
extern unsigned char act_flag, act_flag_temp, fragile_flag;
extern unsigned short img_color;
extern unsigned char state, state_temp;
extern unsigned char state_flag;
extern void(*state_pfc[])(void);
//  ������
extern short bias_fork;
extern unsigned char border_top[MT9V03X_W-4];
extern unsigned char direction_fork, direction_fork_set;
extern unsigned char cnt_left, cnt_right;//��������б
extern unsigned char total_count_fork;
extern unsigned char count_fork;
extern short cut_fork_lef, cut_fork_rig, cut_fork_bottom_col;
extern short bottom_point_row;
//	�յ����
extern unsigned char infle_lefcount, infle_rigcount;
extern unsigned char infle_lefp[90], infle_rigp[90];
/*----------------------*/
/*	 	 ����ģ��		*/
/*======================*/
extern short p_target[2];
extern short spd_set;
extern short spd, rad;
extern short rad_temp, rad_min, rad_max;
extern unsigned char folrow_f;
extern unsigned char ctrl_bias[];
extern char folc_flag, cooling_flag, ring_out_flag;
extern unsigned char ctrl_pointer, dir_run_out;
extern unsigned char bend_bias[];
extern void(*ctrl_pfc[])(void);
extern void(*ctrl_pfc_alter1[])(void);
//	ģ��PID
//extern float form[7][7];
//extern float es[7], ecs[7];
//	һ�Ŵ���
extern short ring_lefbias, ring_rigbias;
extern short ring_outbias;
extern unsigned short point_folrow;
/*----------------------*/
/*	 	  PIDģ��		*/
/*======================*/
//	�ṹ������
typedef struct pidpara{
	float alpha;
	float Kp;
	float Ki;
	float Kd;
	float I;
	float ei, e_bias, eci;
	float detKp;
	int e1;
	int e2;
	int e3;
	short rs;
}pidpara;
extern struct pidpara cam_steering;
/*----------------------*/
/*	 	 ������ȥ		*/
/*======================*/
extern unsigned char subuff_num;
extern unsigned char subuff_arr[3];
extern unsigned short subuff_ranging;
/*----------------------*/
/*	 	 ����ͨ��		*/
/*======================*/
extern unsigned char yawa_flag, action_flag;
extern short yawa, pita;
extern char buff_get6, buff_get7;
/*----------------------*/
/*	     flash�洢		*/
/*======================*/
extern int flash_memory[256];
extern void(*Init_para_pfc[])(void);
extern char(*flash_init_pfc[])(void);
extern void(*first_flash_init_pfc[])(void);
extern void(*flash_memory_write_pfc[])(unsigned char, unsigned char);
/*----------------------*/
/*	 	 �˵�ģ��		*/
/*======================*/
//	һ���˵�
extern unsigned char menu_index;
extern unsigned char nom[128];
//	��־λ
extern unsigned char fixedflag;
extern unsigned char monitorflag;
extern unsigned char csimenu_flag[4];
extern unsigned char run_flag[4];
extern unsigned char flash_memory_flag[4];
extern unsigned char excollflag;
extern unsigned char menu_level;
//	�����˵�
extern unsigned char menu2_index;
extern unsigned char menu2_level;
//	����ָ��
extern void(*menu_pfc[])(unsigned char);
/*----------------------*/
/*	 	 ���ģ��		*/
/*======================*/
//	�ṹ������
typedef struct adcpara{//��Ż�������
	unsigned short value;
	unsigned short max;
	unsigned short min;
	unsigned short pin;
}adcpara;
//	ȫ�ֽṹ������
extern struct adcpara adc2;
/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/
void Init_para(void);
void Init_para_alter1(void);
#endif
