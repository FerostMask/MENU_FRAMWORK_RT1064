/*--------------------------------------------------------------*/
/*							ͷ�ļ�����							*/
/*==============================================================*/
#include "ctrl.h"
#include "data.h"
#include "pid.h"
#include "zf_flash.h"
/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/

/*--------------------------------------------------------------*/
/* 							 �������� 							*/
/*==============================================================*/
///*--------------------------------------------------------------*/
///* 							 flash�洢 							*/
///*==============================================================*/
///*----------------------*/
///*	 flash������ʼ��	*/
///*======================*/
////	��Ҫ�����Ӵ洢������ʱ�򣬼ǵ��޸�data.h�е�FLASH_NUM
////	��Ҫ�����Ӵ洢������ʱ�򣬼ǵ��޸�data.h�е�FLASH_NUM
////	��Ҫ�����Ӵ洢������ʱ�򣬼ǵ��޸�data.h�е�FLASH_NUM
///*----------------------*/
///*	 ����ת�����ʹ洢	*/
///*======================*/
//float ex_int2float(long int value){
////	����������
//	union{
//		float float_value;
//		long int int_value;
//	}c;
////	�洢����ת��
//	c.int_value = value;
//	return c.float_value;
//}
///*----------------------*/
///*	 ������ת���ʹ洢	*/
///*======================*/
//long int ex_float2int(float value){
////	����������
//	union{
//		float float_value;
//		long int int_value;
//	}c;
////	�洢����ת��
//	c.float_value = value;
//	return c.int_value;
//}
//char flash_init(void){
////	ȷ���Ƿ�����ǰ����Ĳ���
//	if(!(flash_check(FLASH_MEMORY_SLECTION, FLASH_PAGE_0))) return 1;
////	��ȡ�����ò���
//	flash_page_read(FLASH_MEMORY_SLECTION, FLASH_PAGE_0, flash_memory, FLASH_NUM);
////	CAMת��
//	cam_steering.Kp = ex_int2float(flash_memory[0]);
//	cam_steering.Kd = ex_int2float(flash_memory[1]);
////	�ٶȿ���
//	spd_set = ex_int2float(flash_memory[2]);
////	׷�ٵ�
//	point_folrow = ex_int2float(flash_memory[3]);
////	ģ��PID
//	cam_steering.ei = ex_int2float(flash_memory[4]);
//	cam_steering.e_bias = ex_int2float(flash_memory[5]);
//	cam_steering.eci = ex_int2float(flash_memory[6]);
////	�������
//	direction_fork_set = ex_int2float(flash_memory[7]);
////	����ƫ��
//	ring_lefbias = ex_int2float(flash_memory[8]);
//	ring_rigbias = ex_int2float(flash_memory[9]);
//	ring_outbias = ex_int2float(flash_memory[10]);
//	return 0;
//}
///*----------------------*/
///*	  ���β�����ʼ��	*/
///*======================*/
//void first_flash_init(void){
////	CAMת��
//	flash_memory[0] = ex_float2int(cam_steering.Kp);
//	flash_memory[1] = ex_float2int(cam_steering.Kd);
////	�ٶȿ���
//	flash_memory[2] = ex_float2int(spd_set);
////	׷�ٵ�
//	flash_memory[3] = ex_float2int(point_folrow);
////	ģ��PID
//	flash_memory[4] = ex_float2int(cam_steering.ei);
//	flash_memory[5] = ex_float2int(cam_steering.e_bias);
//	flash_memory[6] = ex_float2int(cam_steering.eci);
////	�������
//	flash_memory[7] = ex_float2int(direction_fork_set);
////	����ƫ��
//	flash_memory[8] = ex_float2int(ring_lefbias);
//	flash_memory[9] = ex_float2int(ring_rigbias);
//	flash_memory[10] = ex_float2int(ring_outbias);
////	������д��
//	flash_erase_page(FLASH_MEMORY_SLECTION, FLASH_PAGE_0);
//	flash_page_program(FLASH_MEMORY_SLECTION, FLASH_PAGE_0, flash_memory, FLASH_NUM);
//}
///*----------------------*/
///*	  flash����д�� 	*/
///*======================*/
//void flash_memory_write(unsigned char row, unsigned char col){
////	��ѡ��
//	switch(row){
//	//	��ѡ��
//		case PARASET_PID:
//			switch(col){
//				case 0:
//					flash_memory[0] = ex_float2int(cam_steering.Kp);
//					flash_memory[1] = ex_float2int(cam_steering.Kd);	
//					break;
//				case 1:
//					flash_memory[4] = ex_float2int(cam_steering.ei);
//					flash_memory[5] = ex_float2int(cam_steering.e_bias);
//					flash_memory[6] = ex_float2int(cam_steering.eci);
//					break;
//			}
//			break;
//		case PARASET_OPER:
//			switch(col){
//				case 0:
//					flash_memory[2] = ex_float2int(spd_set);
//					flash_memory[3] = ex_float2int(point_folrow);
//					flash_memory[7] = ex_float2int(direction_fork_set);
//					break;
//				case 1:
//					flash_memory[8] = ex_float2int(ring_lefbias);
//					flash_memory[9] = ex_float2int(ring_rigbias);
//					flash_memory[10] = ex_float2int(ring_outbias);
//					break;
//			}
//			break;
//	}
////	������д��
//	flash_erase_page(FLASH_MEMORY_SLECTION, FLASH_PAGE_0);
//	flash_page_program(FLASH_MEMORY_SLECTION, FLASH_PAGE_0, flash_memory, FLASH_NUM);
//}
