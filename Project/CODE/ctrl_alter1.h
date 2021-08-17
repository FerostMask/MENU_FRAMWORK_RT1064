/*------------------------------------------------------*/
/* 					   头文件声明 						*/
/*======================================================*/
#ifndef _CTRLALTER1_H
#define _CTRLALTER1_H
/*------------------------------------------------------*/ 
/* 						函数声明 						*/
/*======================================================*/
void cam_ctrl_final_alter1(void);
void cam_ctrl_fork_alter1(void);
void cam_ctrl_cross_alter1(void);
void cam_ctrl_ring_alter1(void);
void cam_ctrl_bend_alter1(void);
void cam_ctrl_direct_alter1(void);
char flash_init_alter1(void);
void first_flash_init_alter1(void);
void flash_memory_write_alter1(unsigned char row, unsigned char col);
#endif
