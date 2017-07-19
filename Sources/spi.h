//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : C50ES_FP
//* File Name          : spi.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2011,05,26
//* Description        : 该程序针对9s12xep100的SPI模块定义和声明
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include <hidef.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////////////

//LTC6802 SPI 引脚定义
#define CSBI PTED_PTED2  //使能端
#define SCK  PTED_PTED3  //SPI时钟
#define MOSI PTED_PTED4  //SPI输入 CPU输出采集模块输入
#define MISO PTED_PTED5  //SPI输出MISO CPU输入采集模块输出


/////////////////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////////////////

void SPI_Init(void);
void SPI_Write_Byte(byte val);
byte SPI_Read_Byte(void);


