/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "menu_2init.h"
#include "fontlib.h"
#include "menu_2.h"
#include "string.h"
#include "data.h"
/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
/*------------------------------*/
/*		   	 菜单模板			*/
/*==============================*/
char init_model_mode0(char index){//	数值修改菜单模板
//	变量定义及初始化
	register unsigned char i;
	dis_str = 0;
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
		//	菜单属性
			menu2_mode = 0;
			menu2_limit = 0;
		//	修改数值的地址
			floatvalue0 = &cam_steering.Kp;
			shortvalue0 = &spd;
			return 0;
	//	菜单名称初始化
		case 1://第一个参数 | 字母样例
			strcpy(menustr, "hello");
			return 0;
		case 2://第二个参数 | 中文样例
			for(i = 0; i < 32; i++) nom[i] = cai1[i];
			for(i = 0; i < 32; i++) nom[32+i] = se0[i];
			for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
			for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
			return 4;//返回字数
	}
	return 0;
}
/*------------------------------*/
/*		   	 图像显示			*/
/*==============================*/
char menu2_imgdisplay(char index){//	数值修改菜单模板
//	变量定义及初始化
	register unsigned char i;
	dis_str = 0;
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
			menu2_mode = PARASET;
			menu2_limit = 3;
			return 0;
	//	菜单名称初始化
		case 1://彩色图像
			for(i = 0; i < 32; i++) nom[i] = cai1[i];
			for(i = 0; i < 32; i++) nom[32+i] = se0[i];
			for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
			for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
			return 4;
		case 2://灰度图像
			for(i = 0; i < 32; i++) nom[i] = hui0[i];
			for(i = 0; i < 32; i++) nom[32+i] = du0[i];
			for(i = 0; i < 32; i++) nom[64+i] = tu0[i];
			for(i = 0; i < 32; i++) nom[96+i] = xiang1[i];
			return 4;
		case 3://状态清除
			for(i = 0; i < 32; i++) nom[i] = zhuang0[i];
			for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
			for(i = 0; i < 32; i++) nom[64+i] = qing0[i];
			for(i = 0; i < 32; i++) nom[96+i] = chu0[i];
			return 4;
	}
	return 0;
}
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/
//	初始化函数指针数组
char(*amenu2_init_pfc[])(char) = {menu2_imgdisplay};
//	变量定义
char dis_str = 0;
char menustr[40];
