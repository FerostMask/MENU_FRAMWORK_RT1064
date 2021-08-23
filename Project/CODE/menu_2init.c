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
/*		 数值修改菜单模板		*/
/*==============================*/
char init_model_mode_para(char index){//	数值修改菜单模板
//	变量定义及初始化
	register unsigned char i;
	dis_str = 0;//是否使用字母显示
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
		//	菜单属性
			menu2_mode = PARASET_F;
			menu2_limit = 0;
			magflag = 1;
		//	修改数值的地址
			floatvalue[0] = &cam_steering.Kp;
			shortvalue[0] = &spd;
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
/*		   按钮切换模板			*/
/*==============================*/
char init_model_mode_sw(char index){//	按钮切换模板
//	变量定义及初始化
	register unsigned char i;
	dis_str = 0;//排版问题，不推荐使用字母
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
		//	菜单属性
			menu2_mode = SWITCHER;
			menu2_limit = 3;
			magflag = 0;
			swclearflag = 0;//是否清除其他非选标志位
		//	标志位数组
			swflag = csimenu_flag;
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
	//	按键执行功能 | 因为排版问题单页只支持四个按键
		case FUNCTION:
			switch(menu2_index){
				case 0://第一行按键功能
					break;
			}
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		   	 图像显示			*/
/*==============================*/
char menu2_imgdisplay(char index){
//	变量定义及初始化
	register unsigned char i;
	dis_str = 0;
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
			menu2_mode = SWITCHER;
			menu2_limit = 3;
			magflag = 0;
			swclearflag = 1;
		//	标志位数组
			swflag = csimenu_flag;
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
		case FUNCTION://按键功能执行
			switch(menu2_index){
				case 0:
					break;
			}
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		   	 转向PID			*/
/*==============================*/
char menu2_steeringPID(char index){
//	变量定义及初始化
	register unsigned char i;
	dis_str = 1;
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
		//	菜单属性
			menu2_mode = PARASET_F;
			menu2_limit = 2;
			magflag = 1;
		//	修改数值的地址
			floatvalue[0] = &cam_steering.Kp;
			floatvalue[1] = &cam_steering.Kd;
			return 0;
	//	菜单名称初始化
		case 1:
			strcpy(menustr, "Kp");
			return 0;
		case 2:
			strcpy(menustr, "Kd");
			return 0;
	}
	return 0;
}
/*------------------------------*/
/*		   	   姿态				*/
/*==============================*/
char menu2_spdctrl(char index){
//	变量定义及初始化
	register unsigned char i;
	dis_str = 0;
//	信息索引
	switch(index){
	//	菜单属性初始化
		case 0:
		//	菜单属性
			menu2_mode = PARASET_S;
			menu2_limit = 3;
			magflag = 1;
		//	修改数值的地址
			shortvalue[0] = &spd_set;
			shortvalue[1] = &point_folrow;
			shortvalue[2] = &direction_fork_set;
			return 0;
	//	菜单名称初始化
		case 1://车速
			for(i = 0; i < 32; i++) nom[i] = che0[i];
			for(i = 0; i < 32; i++) nom[32+i] = su0[i];
			return 2;
		case 2://追踪点
			for(i = 0; i < 32; i++) nom[i] = zhui0[i];
			for(i = 0; i < 32; i++) nom[32+i] = zong0[i];
			for(i = 0; i < 32; i++) nom[64+i] = dian1[i];
			return 3;
		case 3://平衡点
			for(i = 0; i < 32; i++) nom[i] = ping0[i];
			for(i = 0; i < 32; i++) nom[32+i] = heng0[i];
			for(i = 0; i < 32; i++) nom[64+i] = dian1[i];
			return 3;
	}
	return 0;
}
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/
//	初始化函数指针数组
char(*amenu2_init_pfc[])(char) = {	menu2_imgdisplay, 
									menu2_steeringPID,
									menu2_spdctrl		};
//	变量定义
char dis_str = 0;
char menustr[20];
