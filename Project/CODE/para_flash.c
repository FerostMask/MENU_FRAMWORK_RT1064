/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "para_flash.h"
#include "data.h"
#include "pid.h"
#include "menu.h"
#include "menu_2.h"
#include "menu_2init.h"
#include "zf_flash.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/

/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
/*--------------------------------------------------------------*/
/* 							 flash存储 							*/
/*==============================================================*/
//	重要：增加存储个数的时候，记得修改data.h中的FLASH_NUM
//	重要：增加存储个数的时候，记得修改data.h中的FLASH_NUM
//	重要：增加存储个数的时候，记得修改data.h中的FLASH_NUM
/*----------------------*/
/*	 整型转浮点型存储	*/
/*======================*/
float ex_int2float(long int value){
//	定义联合体
	union{
		float float_value;
		unsigned long int_value;
	}c;
//	存储数据转换
	c.int_value = value;
	return c.float_value;
}
/*----------------------*/
/*	 浮点型转整型存储	*/
/*======================*/
long int ex_float2int(float value){
//	定义联合体
	union{
		float float_value;
		unsigned long int_value;
	}c;
//	存储数据转换
	c.float_value = value;
	return c.int_value;
}
/*----------------------*/
/*	  参数重新初始化	*/
/*======================*/
void para_reset(char saveflag){//saveflag: 是否存储
//	变量定义
	register short i, j;
	short lom = 0;
	for(i = 0; i < ROWS; i++) lom += colimit[i];
	ips200_showuint16(0, 0, lom);
//	重新初始化参数
	for(i = 0; i < lom; i++){
		ips200_showuint16(0, 1, i);
		amenu2_init_pfc[i](0);//菜单初始化
		if(menu2_mode == PARASET_F || menu2_mode == PARASET_S){
			amenu2_init_pfc[i](ORING_VALUE);//初始化参数值
		//	将参数写入数组
			switch(menu2_mode){
				case PARASET_F:
					for(j = 0; j < menu2_limit; j++) flash_memory[flash_index*5+j] = ex_float2int(*floatvalue[j]);
					break;
				case PARASET_S:
					for(j = 0; j < menu2_limit; j++) flash_memory[flash_index*5+j] = ex_float2int(*shortvalue[j]);
					break;
			}
		}
	}
	if(saveflag){
	//	将数组存入flash
		flash_erase_sector(FLASH_MEMORY_SLECTION);//清除扇区
		for(i = 0; i < 4; i++) flash_page_program(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//存入数据
	}
//	返回二级菜单
	amenu2_init_pfc[calindex](0);
	menu2_limit -= 1;//该函数由按钮切换菜单调用，故索引-1
}
/*----------------------*/
/*	   保存全部参数		*/
/*======================*/
void para_saveall(void){
//	变量定义
	register short i;
	short lom = 0;
	for(i = 0; i < ROWS; i++) lom += colimit[i];
//	重新初始化参数
	for(i = 0; i < lom; i++){
		amenu2_init_pfc[i](0);//菜单初始化
		if(menu2_mode == PARASET_F || menu2_mode == PARASET_S){
		//	将参数写入数组
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
//	将数组存入flash
	flash_erase_sector(FLASH_MEMORY_SLECTION);//清除扇区
	for(i = 0; i < 4; i++) flash_page_program(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//存入数据
//	返回二级菜单
	amenu2_init_pfc[calindex](0);
	menu2_limit -= 1;//该函数由按钮切换菜单调用，故索引-1
}
/*----------------------*/
/*	 flash参数初始化	*/
/*======================*/
void paraflash_init(void){
//	变量定义
	register short i, j;
	unsigned char initflag = 0;
	short lom = 0;
	for(i = 0; i < ROWS; i++) lom += colimit[i];
//	确认是否有提前保存的参数
	if(!flash_check(FLASH_MEMORY_SLECTION, 0)) initflag = 1;
	ips200_showint16(0, 0, lom);
//	检索参数项
	if(initflag)
		para_reset(1);
	else{//读取、启用参数
		for(i = 0; i < 4; i++) flash_read_page(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//读入全部参数
		for(i = 0; i < lom; i++){
			amenu2_init_pfc[i](0);//菜单初始化
			if(menu2_mode == PARASET_F || menu2_mode == PARASET_S){
			//	单个写入参数
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
/*	  flash参数写入 	*/
/*======================*/
void flash_memory_write(void){
//	变量定义
	register short i;
//	将参数写入数组
	switch(menu2_mode){
		case PARASET_F:
			for(i = 0; i < menu2_limit; i++) flash_memory[flash_index*5+i] = ex_float2int(*floatvalue[i]);
			break;
		case PARASET_S:
			for(i = 0; i < menu2_limit; i++) flash_memory[flash_index*5+i] = ex_float2int(*shortvalue[i]);
			break;
	}
//	将数组存入flash
	flash_erase_sector(FLASH_MEMORY_SLECTION);//清除扇区
	for(i = 0; i < 4; i++) flash_page_program(FLASH_MEMORY_SLECTION, i, &flash_memory[64*i], 64);//存入数据
}
