/*--------------------------------------------------------------*/
/*							头文件加载							*/
/*==============================================================*/
#include "menu.h"
#include "Init.h"
#include "menu_2.h"
#include "zf_pit.h"
#include "fontlib.h"
#include "menu_2init.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
/*--------------------------------------------------------------*/
/* 							 变量定义 							*/
/*==============================================================*/
//	一级菜单相关
short calindex = 0;//一级菜单一维索引
//	二级菜单
char menu2_limit = 0;//菜单阈值
unsigned char menu2_mode = 0;//菜单模式
unsigned char *swflag;//切换标志位
//	修改倍数相关
unsigned char magflag = 1;
unsigned char magindex = 1;
//	数值修改相关
short *shortvalue[5];
float *floatvalue[5];
float mag[] = {10,1,0.1,0.01,0.001};
//----------------------------分割线----------------------------//
//	二级菜单相关	
unsigned char menu2flag = 1;//次级菜单进入标志位
unsigned char menu2mode = 0;//菜单显示模式
unsigned char fixedindex = 0;
/*--------------------------------------------------------------*/
/* 							 函数定义 							*/
/*==============================================================*/
/*------------------------------*/
/*		   基础信息存放			*/
/*==============================*/
static char info_found(unsigned char index, unsigned char num){
//	变量定义
	register unsigned char i;
	switch(index){
		case 1:
			switch(num){			
				case 0://参数名
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = ming0[i];
					return 3;
				case 1://参数值
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = zhi1[i];
					return 3;
				case 2://参数保存
					for(i = 0; i < 32; i++) nom[i] = can0[i];
					for(i = 0; i < 32; i++) nom[32+i] = shu0[i];
					for(i = 0; i < 32; i++) nom[64+i] = bao0[i];
					for(i = 0; i < 32; i++) nom[96+i] = cun0[i];
					return 4;
				case 3://已保存
					for(i = 0; i < 32; i++) nom[i] = yi0[i];
					for(i = 0; i < 32; i++) nom[32+i] = bao0[i];
					for(i = 0; i < 32; i++) nom[64+i] = cun0[i];
					return 3;
			}
			break;
		case 2:
			switch(num){
				case 0://通道
					for(i = 0; i < 32; i++) nom[i] = tong0[i];
					for(i = 0; i < 32; i++) nom[32+i] = dao0[i];
					return 2;
				case 1://最大值
					for(i = 0; i < 32; i++) nom[i] = zui0[i];
					for(i = 0; i < 32; i++) nom[32+i] = da0[i];
					for(i = 0; i < 32; i++) nom[64+i] = zhi0[i];
					return 3;
				case 2://最小值
					for(i = 0; i < 32; i++) nom[i] = zui0[i];
					for(i = 0; i < 32; i++) nom[32+i] = xiao0[i];
					for(i = 0; i < 32; i++) nom[64+i] = zhi0[i];
					return 3;
			}
		case 3:
			switch(num){
				case 0://开
					for(i = 0; i < 32; i++) nom[i] = kai0[i];
					return 1;
				case 1://关
					for(i = 0; i < 32; i++) nom[i] = guan0[i];
					return 1;
				case 2:
					for(i = 0; i < 32; i++) nom[i] = state1[i];
					return 1;
					break;
				case 3:
					for(i = 0; i < 32; i++) nom[i] = state0[i];
					return 1;
				case 4://功能
					for(i = 0; i < 32; i++) nom[i] = gong0[i];
					for(i = 0; i < 32; i++) nom[32+i] = neng0[i];
					return 2;
				case 5://状态
					for(i = 0; i < 32; i++) nom[i] = zhuang0[i];
					for(i = 0; i < 32; i++) nom[32+i] = tai0[i];
					return 2;
				case 6://启用
					for(i = 0; i < 32; i++) nom[i] = qi1[i];
					for(i = 0; i < 32; i++) nom[32+i] = yong0[i];
					return 2;
				case 7://关闭
					for(i = 0; i < 32; i++) nom[i] = guan0[i];
					for(i = 0; i < 32; i++) nom[32+i] = bi1[i];
					return 2;
			}
	}
	return 0;
}
/*------------------------------*/
/*		 数值显示辅助模块		*/
/*==============================*/
static void menu2value_sup(void){
//	变量定义
	register char i;
//	数值显示
	switch(menu2_mode){
		case PARASET_F:
			ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0XFFFF);//擦除已保存字样
			ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);//擦除保存字样
			for(i = 0; i < menu2_limit; i++) ips200_showfloat(120, 15+i, *floatvalue[i], 3, 3);
			return;
		case PARASET_S:
			ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0XFFFF);//擦除已保存字样
			ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0XFFFF);//擦除保存字样
			for(i = 0; i < menu2_limit; i++) ips200_showint16(120, 15+i, *shortvalue[i]);
			return;
		case SWITCHER:
			for(i = 0; i < menu2_limit; i++){
				if(*(swflag+i)){//开启
					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);
					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);				
				}
				else{//关闭
					ips200_display_chinese(118, 240+18*i, 16, nom, info_found(3, 3), 0xB6DB);
					ips200_display_chinese(198, 240+18*i, 16, nom, info_found(3, 2), 0xB6DB);	
				}
			}
			return;
	}
}
/*------------------------------*/
/*		 菜单高亮显示模块		*/
/*==============================*/
void menu2value_hl(void){
	switch(menu2_mode){
		case PARASET_F:
			if(!menu2_index) ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);//显示保存
			else ips200_showfloat(120, 14+menu2_index, *floatvalue[menu2_index-1], 3, 3); 
			return;
		case PARASET_S:
			if(!menu2_index) ips200_display_chinese(176, 192, 16, nom, info_found(1, 2), 0xAE9C);//显示保存
			else ips200_showint16(120, 14+menu2_index, *shortvalue[menu2_index-1]);
			return;
		case SWITCHER:
			if(*(swflag+menu2_index)) ips200_display_chinese(118, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XB7BD);
			else ips200_display_chinese(198, 240+18*menu2_index, 16, nom, info_found(3, 2), 0XF5BA);
			return;
	}
}
/*------------------------------*/
/*		   数值显示模块			*/
/*==============================*/
static void menu2value(void){
//	显示级别
	if(magflag) ips200_showfloat(180, 14, mag[magindex], 2, 3);
//	显示数值
	menu2value_sup();
//	高亮数值
	if(!menu2_level){
	//	选择
		ips200_pencolor = 0xFFFF;
		ips200_bgcolor = 0xFDF8;
		menu2value_hl();
		ips200_pencolor = 0xB6DB;
		ips200_bgcolor = 0xFFFF;
	}
	else{
	//	修改
		ips200_pencolor = 0xFFFF;
		ips200_bgcolor = 0xAE9C;
		menu2value_hl();
		ips200_pencolor = 0xB6DB;
		ips200_bgcolor = 0xFFFF;
	}
}
/*------------------------------*/
/*		 基础信息显示模块		*/
/*==============================*/
void found_display(void){
	switch(menu2_mode){
		case PARASET_F:
		case PARASET_S:
				ips200_display_chinese(0, 208, 16, nom, info_found(1, 0), 0XFDF8);//参数名
				ips200_display_chinese(120, 208, 16, nom, info_found(1, 1), 0XFDF8);//参数值
			return;
		case SWITCHER:
				ips200_display_chinese(0, 208, 16, nom, info_found(3, 4), 0XFDF8);
				ips200_display_chinese(150, 208, 16, nom, info_found(3, 5), 0XFDF8);
				ips200_display_chinese(110, 224, 16, nom, info_found(3, 6), 0XFDF8);
				ips200_display_chinese(190, 224, 16, nom, info_found(3, 7), 0XFDF8);
			return;
	}
}
/*------------------------------*/
/*		   名称显示模块			*/
/*==============================*/
void menu2_display(void){
//	变量定义
	register char i;
	if(!dis_str){//显示中文
		switch(menu2_mode){
			case PARASET_F:
				for(i = 0; i < menu2_limit; i++) ips200_display_chinese(0, 240+i*16, 16, nom, amenu2_init_pfc[calindex](i+1), 0xB6DB); 
				return;
			case SWITCHER:
				for(i = 0; i < menu2_limit; i++) ips200_display_chinese(0, 240+i*18, 16, nom, amenu2_init_pfc[calindex](i+1), 0xB6DB); 
				return;
		}
	}
	else{//显示字母
		switch(menu2_mode){
			case PARASET_F:
				for(i = 0; i < (menu2_limit+1); i++){
					amenu2_init_pfc[calindex](i+1);
					ips200_showstr(0, 15+i, menustr);
				} 
				return;
			case SWITCHER:
				for(i = 0; i < (menu2_limit+1); i++){
					amenu2_init_pfc[calindex](i+1);
					ips200_showstr(0, 15+i, menustr);
				} 
				return;
		}
	}
}
/*------------------------------*/
/*		 二级菜单初始化模块		*/
/*==============================*/
void menu2_init(void){
//	变量定义及初始化            
	register char i;
	calindex = 0, menu2_index = 0, magflag = 0, magindex = 1;
//	清屏
	ips200_clear(WHITE);
//	加载菜单属性
	for(i = 0; i < menu_index; i++) calindex += colimit[i];
    calindex += menu[menu_index];
//	ips200_showint16(0, 0, index);
	amenu2_init_pfc[calindex](0);
//	初始化菜单
	switch(menu2_mode){
		case PARASET_F://数值修改菜单
		case PARASET_S:
		//	预处理
			menu2_index = 1;
			found_display();
			menu2_display();
			menu2value();
			return;
		case SWITCHER:
			menu2_index = 0;
			menu2_limit -= 1;
			found_display();
			menu2_display();
			menu2value();
			return;
	}
}
/*------------------------------*/
/*		   数值修改模块			*/
/*==============================*/
static void modify(unsigned char event){
	switch(menu2_mode){
		case PARASET_F:
			if(event){
		//	数值增加
				switch(menu2_index){
					case 1:*floatvalue[0]+=mag[magindex];break;
					case 2:*floatvalue[1]+=mag[magindex];break;
					case 3:*floatvalue[2]+=mag[magindex];break;
					case 4:*floatvalue[3]+=mag[magindex];break;
					case 5:*floatvalue[4]+=mag[magindex];break;
				}
			}
		//	数值减少
			else{
				switch(menu2_index){
					case 1:*floatvalue[0]-=mag[magindex];break;
					case 2:*floatvalue[1]-=mag[magindex];break;
					case 3:*floatvalue[2]-=mag[magindex];break;
					case 4:*floatvalue[3]-=mag[magindex];break;
					case 5:*floatvalue[4]-=mag[magindex];break;
				}
			}
			break;
		case PARASET_S:
			if(event){
				switch(menu2_index){
					case 1: *shortvalue[0]+=mag[magindex];break;
					case 2: *shortvalue[1]+=mag[magindex];break;
					case 3: *shortvalue[2]+=mag[magindex];break;
					case 4: *shortvalue[3]+=mag[magindex];break;
					case 5: *shortvalue[4]+=mag[magindex];break;
				}
			}
			else{
				switch(menu2_index){
					case 1: *shortvalue[0]-=mag[magindex];break;
					case 2: *shortvalue[1]-=mag[magindex];break;
					case 3: *shortvalue[2]-=mag[magindex];break;
					case 4: *shortvalue[3]-=mag[magindex];break;
					case 5: *shortvalue[4]-=mag[magindex];break;
				}
			}
	}
}
/*------------------------------*/
/*		 二级菜单选择模块		*/
/*==============================*/
void menu2_select(unsigned char event){
//	变量定义
	register unsigned char i;
//	返回键
	if(event == 3){
	//	重置
		menu_level = 0;
		menu2_level = 0;
		magindex = 1;
		monitorflag = 0;
		menu_display();
		excollflag = 0;
	//	操作定时器
//		tim_interrupt_init_ms(TIM_2, 2, 0, 0);//开启采集通道
//		if(!fixedflag) tim_interrupt_disabnle(TIM_6);//除固定显示外关闭监视通道
		return;
	}
	if(!menu2_level){
		switch(event){
			case 6://右按键
				if(magindex < 4) magindex++;
				break;
			
			case 4://左按键
				if(magindex > 0) magindex--; 
				break;
			
			case 2://上按键
				if(menu2_index > 0) menu2_index--;
				break;
			
			case 5://下按键
				if(menu2_index < menu2_limit) menu2_index++;
				break;
			
			case 1://确定键
				switch(menu2_mode){
					case PARASET_F:
						if(!menu2_index){//参数保存
							ips200_display_chinese(109, 192, 16, nom, info_found(1, 3), 0xAE9C);
							return;
						}
						else menu2_level = 1;
						break;
					case SWITCHER:
						*(swflag+menu2_index) = !(*(swflag+menu2_index));
						amenu2_init_pfc[calindex](FUNCTION);
						break;
				}
				break;
		}
	}
	else{
		switch(event){
			case 6://右按键
				if(magindex < 4) magindex++;
				break;
			
			case 4://左按键
				if(magindex > 0) magindex--; 
				break;
			
			case 2://上按键
				modify(1);
				break;
			
			case 5://下按键
				modify(0);
				break;
			
			case 1://确定键
				menu2_level = 0;
				break;
		}
	}
//	菜单更新
	switch(menu2_mode){
		case PARASET_F:
		case SWITCHER:
			menu2value();
			break;
	}
}

///*------------------------------*/
///*		   数值监视模块			*/
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
///*		   固定监视模块			*/
///*==============================*/
//void fixed_monitor(void){
//	switch(fixedindex){
//		case 0:
//		//	名称显示
//			ips200_showstr(0, 0, "error");
//			ips200_showstr(0, 1, "result");
//		//	数值显示
////			ips200_showint16(120, 0, adc_err.rs);
////			ips200_showint16(120, 1, adc_steering.rs);
//			break;
//		case 1:
//		//	名称显示
//			ips200_showstr(0, 0, "ADC0");
//			ips200_showstr(0, 1, "ADC1");
//			ips200_showstr(0, 2, "ADC2");
//			ips200_showstr(0, 3, "ADC3");
//			ips200_showstr(0, 4, "ADC4");
//		//	数值显示
//			ips200_showuint8(120, 2, adc2.value);
//			break;
//	}
//}
