/*------------------------------------------------------*/
/* 					   ͷ�ļ����� 						*/
/*======================================================*/
#ifndef _CTRL_H
#define _CTRL_H
/*------------------------------------------------------*/ 
/* 						�������� 						*/
/*======================================================*/
void cam_ctrl_final(void);
void cam_ctrl_fork(void);
void cam_ctrl_cross(void);
void cam_ctrl_ring(void);
void cam_ctrl_bend(void);
void cam_ctrl_direct(void);
//char flash_init(void);
void first_flash_init(void);
void flash_memory_write(unsigned char row, unsigned char col);
#endif
