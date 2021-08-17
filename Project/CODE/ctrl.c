/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "ctrl.h"
#include "data.h"
#include "pid.h"
#include "zf_flash.h"
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/

/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
///*--------------------------------------------------------------*/
///* 							 flash存储 							*/
///*==============================================================*/
///*----------------------*/
///*	 flash参数初始化	*/
///*======================*/
////	重要：增加存储个数的时候，记得修改data.h中的FLASH_NUM
////	重要：增加存储个数的时候，记得修改data.h中的FLASH_NUM
////	重要：增加存储个数的时候，记得修改data.h中的FLASH_NUM
///*----------------------*/
///*	 整型转浮点型存储	*/
///*======================*/
//float ex_int2float(long int value){
////	定义联合体
//	union{
//		float float_value;
//		long int int_value;
//	}c;
////	存储数据转换
//	c.int_value = value;
//	return c.float_value;
//}
///*----------------------*/
///*	 浮点型转整型存储	*/
///*======================*/
//long int ex_float2int(float value){
////	定义联合体
//	union{
//		float float_value;
//		long int int_value;
//	}c;
////	存储数据转换
//	c.float_value = value;
//	return c.int_value;
//}
//char flash_init(void){
////	确认是否有提前保存的参数
//	if(!(flash_check(FLASH_MEMORY_SLECTION, FLASH_PAGE_0))) return 1;
////	读取、启用参数
//	flash_page_read(FLASH_MEMORY_SLECTION, FLASH_PAGE_0, flash_memory, FLASH_NUM);
////	CAM转向
//	cam_steering.Kp = ex_int2float(flash_memory[0]);
//	cam_steering.Kd = ex_int2float(flash_memory[1]);
////	速度控制
//	spd_set = ex_int2float(flash_memory[2]);
////	追踪点
//	point_folrow = ex_int2float(flash_memory[3]);
////	模糊PID
//	cam_steering.ei = ex_int2float(flash_memory[4]);
//	cam_steering.e_bias = ex_int2float(flash_memory[5]);
//	cam_steering.eci = ex_int2float(flash_memory[6]);
////	岔道方向
//	direction_fork_set = ex_int2float(flash_memory[7]);
////	环道偏置
//	ring_lefbias = ex_int2float(flash_memory[8]);
//	ring_rigbias = ex_int2float(flash_memory[9]);
//	ring_outbias = ex_int2float(flash_memory[10]);
//	return 0;
//}
///*----------------------*/
///*	  初次参数初始化	*/
///*======================*/
//void first_flash_init(void){
////	CAM转向
//	flash_memory[0] = ex_float2int(cam_steering.Kp);
//	flash_memory[1] = ex_float2int(cam_steering.Kd);
////	速度控制
//	flash_memory[2] = ex_float2int(spd_set);
////	追踪点
//	flash_memory[3] = ex_float2int(point_folrow);
////	模糊PID
//	flash_memory[4] = ex_float2int(cam_steering.ei);
//	flash_memory[5] = ex_float2int(cam_steering.e_bias);
//	flash_memory[6] = ex_float2int(cam_steering.eci);
////	岔道方向
//	flash_memory[7] = ex_float2int(direction_fork_set);
////	环道偏置
//	flash_memory[8] = ex_float2int(ring_lefbias);
//	flash_memory[9] = ex_float2int(ring_rigbias);
//	flash_memory[10] = ex_float2int(ring_outbias);
////	擦除后写入
//	flash_erase_page(FLASH_MEMORY_SLECTION, FLASH_PAGE_0);
//	flash_page_program(FLASH_MEMORY_SLECTION, FLASH_PAGE_0, flash_memory, FLASH_NUM);
//}
///*----------------------*/
///*	  flash参数写入 	*/
///*======================*/
//void flash_memory_write(unsigned char row, unsigned char col){
////	行选择
//	switch(row){
//	//	列选择
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
////	擦除后写入
//	flash_erase_page(FLASH_MEMORY_SLECTION, FLASH_PAGE_0);
//	flash_page_program(FLASH_MEMORY_SLECTION, FLASH_PAGE_0, flash_memory, FLASH_NUM);
//}
