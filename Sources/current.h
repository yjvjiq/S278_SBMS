//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : s133
//* File Name          : current.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2011,05,26
//* Description        : 根据ADC得到的值，计算出系统电流
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
extern float  g_systemCurrent; //支路1当前电流值，S278项目有三个支路，SBMS采集两个，BMS采集总电流，三个电流用来判断断路故障。
extern float  g_systemCurrent_2; //支路2当前电流值
/////////////////////////////////////////////////////////////////////////
extern void CurrentCalculation(float *current1, float *current2);
//extern float CurrentCalculation(void);
//**********************************************************************
//***********************************************************************
//***********************************************************************
