/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "data.h"
#include "CAM.h"
#include "menu.h"
#include "menu_2.h"
#include "para_flash.h"
#include "ctrl_alter1.h"
/*--------------------------------------------------------------*/
/*							  �궨��							*/
/*==============================================================*/
#define u8 unsigned char                                    //8λ����
#define u16 unsigned short                                  //16λ����
#define u32 unsigned int                                    //32λ����
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*----------------------*/
/*	 	����ͷģ��		*/
/*======================*/
//	��򷨶�ֵ��
float P[256] = {0}, PK[256] = {0}, MK[256] = {0};
unsigned char binary_img[MT9V03X_CSI_H][(MT9V03X_CSI_W-4)/8];
unsigned char img_thrsod;
//	��׼��Ѱ��
unsigned char found_point[4];
unsigned char fop_flag;
unsigned char border_flag = 0;
//	ˮƽ����Ѱ��
unsigned char lefbor[MT9V03X_H], rigbor[MT9V03X_H], mid_point[MT9V03X_H];
unsigned char ltraf_point_row[10], rtraf_point_row[10], ltraf_point_col[10], rtraf_point_col[10];
unsigned char ltraf_flag[10], rtraf_flag[10];
unsigned char ltraf_count, rtraf_count;
unsigned char lcut, rcut;
//	��ֱ����Ѱ��
unsigned char topbor[MT9V03X_W-4], bottombor[MT9V03X_W-4];//���±���
unsigned char lvet_trafpoint_row[5], rvet_trafpoint_row[5], lvet_trafpoint_col[5], rvet_trafpoint_col[5];//ת���
unsigned char lvet_trafcount, rvet_trafcount;//ת������
unsigned char leftop_cut, lefbottom_cut, rigtop_cut, rigbottom_cut;//��ֹ��
unsigned char exti_lefp[4], exti_rigp[4], exti_lefcount, exti_rigcount;//����
//	״̬��
unsigned char act_flag, act_flag_temp, fragile_flag;
unsigned char state, state_temp;
unsigned char state_flag;
unsigned short img_color = 0xAE9C;
//void(*state_pfc[])(void) = {state_machine_enter, state_machine_bend, state_machine_ring, state_machine_cross, state_machine_fork, state_machine_final};
//  ������
unsigned char border_top[MT9V03X_W-4];
unsigned char cnt_left, cnt_right;//��������б
unsigned char total_count_fork = 0;
unsigned char count_fork = 0;//�յ���
short direction_fork = 0, direction_fork_set = 0;//������� | 0�� | 1��
short cut_fork_lef, cut_fork_rig, cut_fork_bottom_col;
short bottom_point_row;
//	�յ����
unsigned char infle_lefcount, infle_rigcount;
unsigned char infle_lefp[90], infle_rigp[90];
/*----------------------*/
/*	 	 ����ģ��		*/
/*======================*/
struct pidpara cam_steering;
short p_target[2];
short spd_set;
short spd, rad;
short rad_temp, rad_min, rad_max;
char folc_flag, cooling_flag = 0, ring_out_flag = 0;
unsigned char folrow_f = 63;
unsigned char ctrl_pointer = 0, dir_run_out;
//	ģ��PID
//float form[7][7];
//float es[7], ecs[7];
//	һ�Ŵ���
short ring_lefbias = -17, ring_rigbias = 0;
short ring_outbias = -17;
short point_folrow;
/*----------------------*/
/*	     flash�洢		*/
/*======================*/
unsigned long flash_memory[255];
//void(*Init_para_pfc[])(void) = {Init_para, Init_para_alter1};
//char(*flash_init_pfc[])(void) = {flash_init, flash_init_alter1};
//void(*first_flash_init_pfc[])(void) = {first_flash_init, first_flash_init_alter1};
//void(*flash_memory_write_pfc[])(unsigned char, unsigned char) = {flash_memory_write, flash_memory_write_alter1};
/*----------------------*/
/*	 	 �˵�ģ��		*/
/*======================*/
//	��������
unsigned char nom[128];
//	һ���˵�
unsigned char menu_level;
unsigned char menu_index = 0;
//	�����˵�
unsigned char menu2_index = 0;
unsigned char menu2_level = 0;
short *monitor_sv[5] = {0};//������
//	��־λ
unsigned char excollflag = 0;//��ż�ֵ�ɼ���־λ
unsigned char fixedflag = 0;//�̶���ʾ
unsigned char monitorflag = 0;//������
unsigned char csimenu_flag[4] = {0};//����ͷ
unsigned char run_flag[4] = {0};//����
unsigned char flash_memory_flag[4] = {0};//���ݴ洢
//	ָ�뺯��
void(*menu_pfc[])(unsigned char) = {menu_select, menu2_select};
/*----------------------*/
/*	 	 ������ȥ		*/
/*======================*/
unsigned char subuff_num = 0;
unsigned char subuff_arr[3];
unsigned short subuff_ranging;
/*----------------------*/
/*	 	 ����ͨ��		*/
/*======================*/
unsigned char yawa_flag, action_flag;
short yawa, pita;
char buff_get6, buff_get7;
/*----------------------*/
/*	 	 ���ģ��		*/
/*======================*/
//	�ṹ�嶨��
struct adcpara adc2;
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*----------------------*/
/*	 	������ʼ��		*/
/*======================*/
void Init_para(void){
//	�ٶȿ���
	spd_set = 150;
//	���ⷽ��
	dir_run_out = 0;
//	�������
	direction_fork_set = 0;
//	CAMת��
	cam_steering.Kp = 2.3;
	cam_steering.Kd = 0.05;
//	ģ��PID����ƫ��
	cam_steering.ei = 10.0;
	cam_steering.e_bias = 2.5;
	cam_steering.eci = 15.0;
//	׷�ٵ�
	point_folrow = 52;
//	����ƫ��
	ring_lefbias = -17;
	ring_rigbias = 0;
	ring_outbias = -68;
//	���ģ��
	adc2.max = 4095, adc2.min = 0;
}
/*----------------------*/
/*	 	������ʼ��1		*/
/*======================*/
void Init_para_alter1(void){
//	�ٶȿ���
	spd_set = 130;
//	���ⷽ��
	dir_run_out = 0;
//	�������
	direction_fork_set = 0;
//	CAMת��
	cam_steering.Kp = 1.2;
	cam_steering.Kd = 0.1;
//	���ģ��
	adc2.max = 4095, adc2.min = 0;
}
