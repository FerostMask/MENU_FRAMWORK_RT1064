/*------------------------------------------------------*/
/* 					   头文件声明 						*/
/*======================================================*/
#ifndef _PARAFLASH_H
#define _PARAFLASH_H
/*------------------------------------------------------*/ 
/* 						函数声明 						*/
/*======================================================*/
void para_reset(char saveflag);
void para_saveall(void);
void paraflash_init(void);
void flash_memory_write(void);
#endif
