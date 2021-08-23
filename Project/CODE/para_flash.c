/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "para_flash.h"
#include "data.h"
#include "pid.h"
#include "menu_2.h"
#include "menu_2init.h"
#include "zf_flash.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/

/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
/*--------------------------------------------------------------*/
/* 							 flash�洢 							*/
/*==============================================================*/
//	��Ҫ�����Ӵ洢������ʱ�򣬼ǵ��޸�data.h�е�FLASH_NUM
//	��Ҫ�����Ӵ洢������ʱ�򣬼ǵ��޸�data.h�е�FLASH_NUM
//	��Ҫ�����Ӵ洢������ʱ�򣬼ǵ��޸�data.h�е�FLASH_NUM
/*----------------------*/
/*	 ����ת�����ʹ洢	*/
/*======================*/
float ex_int2float(long int value){
//	����������
	union{
		float float_value;
		unsigned long int_value;
	}c;
//	�洢����ת��
	c.int_value = value;
	return c.float_value;
}
/*----------------------*/
/*	 ������ת���ʹ洢	*/
/*======================*/
long int ex_float2int(float value){
//	����������
	union{
		float float_value;
		unsigned long int_value;
	}c;
//	�洢����ת��
	c.float_value = value;
	return c.int_value;
}
/*----------------------*/
/*	  �������³�ʼ��	*/
/*======================*/
void para_reset(void){
//	��������
	register short i;
	short lom = sizeof(&amenu2_init_pfc);
//	���³�ʼ������
	for(i = 0; i < lom; i++){
		amenu2_init_pfc[i](0);//�˵���ʼ��
		if(menu2_mode == PARASET_F || menu2_mode == PARASET_S){
			amenu2_init_pfc[i](ORING_VALUE);//��ʼ������ֵ
		//	������д������
			switch(menu2_mode){
				case PARASET_F:
					for(i = 0; i < menu2_limit; i++) flash_memory[flash_index*5+i] = ex_float2int(*floatvalue[i]);
					break;
				case PARASET_S:
					for(i = 0; i < menu2_limit; i++) flash_memory[flash_index*5+i] = ex_float2int(*shortvalue[i]);
					break;
			}
		}
	}
//	���������flash
	flash_erase_sector(FLASH_MEMORY_SLECTION);//�������
	for(i = 0; i < 4; i++) flash_page_program(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//��������
}
/*----------------------*/
/*	 flash������ʼ��	*/
/*======================*/
void paraflash_init(void){
//	��������
	register short i, j;
	unsigned char initflag = 0;
	short lom = sizeof(&amenu2_init_pfc);
//	ȷ���Ƿ�����ǰ����Ĳ���
	if(!flash_check(FLASH_MEMORY_SLECTION, 0)) initflag = 1;
	ips200_showint16(0, 0, initflag);
//	����������
	if(initflag)
		para_reset();
	else{//��ȡ�����ò���
		for(i = 0; i < 4; i++) flash_read_page(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//����ȫ������
		for(i = 0; i < lom; i++){
			amenu2_init_pfc[i](0);//�˵���ʼ��
			if(menu2_mode == PARASET_F || menu2_mode == PARASET_S){
			//	����д�����
				switch(menu2_mode){
					case PARASET_F:
						for(j = 0; j < menu2_limit; j++) *floatvalue[j] = ex_int2float(flash_memory[flash_index*5+j]);
						break;
					case PARASET_S:
						for(j = 0; j < menu2_limit; j++) *shortvalue[j] = ex_int2float(flash_memory[flash_index*5+j]);
						break;
				}
			}
		}
	}
}
/*----------------------*/
/*	  flash����д�� 	*/
/*======================*/
void flash_memory_write(void){
//	��������
	register short i;
//	������д������
	switch(menu2_mode){
		case PARASET_F:
			for(i = 0; i < menu2_limit; i++) flash_memory[flash_index*5+i] = ex_float2int(*floatvalue[i]);
			break;
		case PARASET_S:
			for(i = 0; i < menu2_limit; i++) flash_memory[flash_index*5+i] = ex_float2int(*shortvalue[i]);
			break;
	}
//	���������flash
	flash_erase_sector(FLASH_MEMORY_SLECTION);//�������
	for(i = 0; i < 4; i++) flash_page_program(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//��������
}
