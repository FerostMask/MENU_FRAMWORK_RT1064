/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "menu.h"
#include "Init.h"
#include "menu_2.h"
#include "string.h"
#include "fontlib.h"
#include "zf_gpio.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/
//	菜单数组
unsigned char menu[ROWS] = {0};
//	阈值数组
unsigned char colimit[ROWS] = { 3,
								2,
								1,
								1 };
/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/

//----------------------------分割线----------------------------//
/*--------------------------------------------------------------*/
/* 							 一级菜单 							*/
/*==============================================================*/
/*------------------------------*/
/*		 菜单信息存储模块		*/
/*==============================*/
static char info(char index, char num){
//	变量定义
	register unsigned char i;
//	行索引
	switch(index){
		case 0:
		//	列索引
			switch(num){
				case 0://图像显示
					for(i = 0; i < 32; i++) nom[i] = tu0[i];
					for(i = 0; i < 32; i++) nom[32+i] = xiang1[i];
					for(i = 0; i < 32; i++) nom[64+i] = xian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = shi1[i];
					return 4;
				case 1://参数设置
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = she0[i];
					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
					return 4;
				case 2://发车
					for(i = 0; i < 32; i++) nom[i] = fa0[i];
					for(i = 0; i < 32; i++) nom[32+i] = che0[i];
					return 2;
			}
			break;
		case 1:
			switch(num){
				case 0://转向
					for(i = 0; i < 32; i++) nom[i] = zhuan0[i];
					for(i = 0; i < 32; i++) nom[32+i] = xiang0[i];
					return 2;
				case 1://模糊
					for(i = 0; i < 32; i++) nom[i] = mo0[i];
					for(i = 0; i < 32; i++) nom[32+i] = hu0[i];
					return 2;
				case 2://差比和差
					for(i = 0; i < 32; i++) nom[i] = cha0[i];
					for(i = 0; i < 32; i++) nom[32+i] = bi0[i];
					for(i = 0; i < 32; i++) nom[64+i] = he0[i];
					for(i = 0; i < 32; i++) nom[96+i] = cha0[i];
					return 4;
			}
			break;
		case 2:
			switch(num){
				case 0://姿态
					for(i = 0; i < 32; i++) nom[i] = zi0[i];
					for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
					return 2;
				case 1://环道偏置
					for(i = 0; i < 32; i++) nom[i] = huan1[i];
					for(i = 0; i < 32; i++) nom[32+i] = dao0[i];
					for(i = 0; i < 32; i++) nom[64+i] = pian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = zhi0[i];
					return 4;
			}
			break;
		case 3:
			switch(num){
				case 0://误差监视
					for(i = 0; i < 32; i++) nom[i] = wu0[i];
					for(i = 0; i < 32; i++) nom[32+i] = cha0[i];
					for(i = 0; i < 32; i++) nom[64+i] = jian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = shi0[i];
					return 4;
				case 1://电磁监视
					for(i = 0; i < 32; i++) nom[i] = dian0[i];
					for(i = 0; i < 32; i++) nom[32+i] = ci0[i];
					for(i = 0; i < 32; i++) nom[64+i] = jian0[i];
					for(i = 0; i < 32; i++) nom[96+i] = shi0[i];
					return 4;
			}
			break; 
		case 100://菜单
			for(i = 0; i < 32; i++) nom[i] = cai0[i];
			for(i = 0; i < 32; i++) nom[32+i] = dan0[i];
			return 2;
	}
	return 0;
}
/*------------------------------*/
/*		   菜单显示模块			*/
/*==============================*/
void menu_display(void){
//	变量定义
	char show_index[ROWS];
//	清屏
	ips200_clear(WHITE);
//	计算显示索引
	if(menu_index-1<0) show_index[0] = ROWS-1;
	else show_index[0] = menu_index - 1;

	show_index[1] = menu_index;

	if(menu_index+1>ROWS-1) show_index[2] = 0,show_index[3] = 1;
	else if(menu_index+2>ROWS-1) show_index[2] = menu_index+1,show_index[3] = 0;
	else show_index[2] = menu_index+1,show_index[3] = menu_index+2;
//	菜单显示
	ips200_display_chinese(0, 208, 16, nom, info(100, menu[show_index[0]]), 0XFDF8);
	ips200_display_chinese(30, 224, 16, nom, info(show_index[0], menu[show_index[0]]), 0xB6DB);
	
	ips200_display_chinese(40, 256, 16, nom, info(show_index[1], menu[show_index[1]]), 0xB6DB);
	ips200_showint32(120, 16, menu_index, 1);
	
	ips200_display_chinese(20, 288, 16, nom, info(show_index[2], menu[show_index[2]]), 0xB6DB);
	ips200_display_chinese(0, 304, 16, nom, info(show_index[3], menu[show_index[3]]), 0xB6DB);
}
/*------------------------------*/
/*		 一级菜单事件模块		*/
/*==============================*/
void menu_select(unsigned char event){
//	一级菜单
	if(!menu_level){
	//	菜单事件分支
		switch(event){
			case 6://右按键
				if(menu[menu_index] < (colimit[menu_index]-1)) menu[menu_index]++;
				else return;
				break;
			
			case 4://左按键
				if(menu[menu_index] > 0) menu[menu_index]--;
				else return;
				break;
			
			case 2://上按键
				if(menu_index>0) menu_index--;
				else menu_index = ROWS-1;
				break;
			
			case 5://下按键
				if(menu_index<ROWS-1) menu_index++;
				else menu_index = 0;
				break;
			
			case 1://确定键
			//	初始化二级菜单
				menu2_init();
				menu_level = 1;
				return;
			case 3://返回键
				menu[menu_index] = 0;
				break;
		}
		menu_display();
	}
}
