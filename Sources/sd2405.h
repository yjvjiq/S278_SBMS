
 //----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : C50ES_FP
//* File Name          : sd2405.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : ͷ�ļ�
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//*******************************************
//***************sd2405.c*******************
extern unsigned char CurrentTime[7];//
extern unsigned int g_oldTime[7];
extern void I2CWriteDate(unsigned char *pSecDa);
extern void I2CReadDate(void);
extern void delay_1us(void);        	       //11.0592M, 1us��ʱ����
//***************************************************************************
//***************************************************************************
//***************************************************************************