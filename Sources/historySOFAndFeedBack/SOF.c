
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : SOF.c
//* Author             : judy
//* Version            : V1.0.0
//* Start Date         : 2016.2.14
//* Description        : ���ļ����ڲ������SOF��ǰֵ
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 
//******************************************************************************
//* Function name:   linearizationSOF
//* Description:     SOF���Թ�ϵ��ʽ����
//* EntryParameter : �¶�ֵ��SOCֵ��
//* ReturnValue    : ����ó��������������ŵ����
//******************************************************************************
float linearizationSOF(char tem,float soc) 
{
    float curr=0;

    if((tem<=10)||(tem>90))  //<=-30���>55��
    {
        curr=0;
        return curr;
    }
    if( (tem>10)&&(tem<=20) )//(-30��,-20��] 
    {
        if(soc<=0.1)
            curr=6;
        else if(soc<=0.4)
            curr=18;
        else
            curr=36;
    }
    if( (tem>20)&&(tem<=30) )//(-20��,-10��] 
    {
        if(soc<=0.1)
            curr=36;
        else if(soc<=0.4)
            curr=60;
        else
            curr=96;
    }
    if( (tem>30)&&(tem<=50) )//(-10��,10��] 
    {
        if(soc<=0.1)
            curr=60;
        else if(soc<=0.4)
            curr=120;
        else
            curr=180;
    
    }
    if( (tem>50)&&(tem<=60) )//(10,20]
    {
        if(soc<0.1) 
            curr =60;
        else if(soc<=0.4) 
            curr=144;
        else 
            curr=240;
    }
    
    if( (tem>60)&&(tem<=90) ) //(20,50] 
    {
        if(soc<0.1) 
            curr =120;
        else if(soc<=0.4) 
            curr=144;
        else 
            curr=240;
    }    
 
    return curr;
   
}
//******************************************************************************
//* Function name:   BigDischargePowerAdjust
//* Description:     New SOF 
//* EntryParameter : �¶ȣ�SOC����ǰ����������ʻ����ֵ
//* ReturnValue    : bigPowerCurrent��ǰ��������ŵ繦�ʻ����
//******************************************************************************
float BigDischargePowerAdjust(char tem,float soc)
{
    static float power1=0; //�ŵ繦���ݴ�ֵ1
    static float power2=0; //�ŵ繦���ݴ�ֵ2
    static unsigned char counter=0;//2�λ������ʼ���
    static unsigned char changeFlag=0;//�������Ա仯ʱ��־λ
    static unsigned char FirstOn=0;
    float BigDisPower=0; //��������ŵ繦�ʵ��м��������ֹ����õ������ж�ֱ�ӷ���
    static float pc=0;//��������ŵ繦��/���� ����ֵ
    
    BigDisPower =linearizationSOF(tem,soc); 

    if(FirstOn==0) //��һ�ν���
    {
        pc=BigDisPower; 
        power1 = BigDisPower; 
        FirstOn=1;         
    } 
    else//�ٴν���
    {
        if(changeFlag==0)//ԭֵΪ0������power2Ϊ�ڶ��ν���ú���ʱ��ֵ
            power2=BigDisPower;
     
        if(power1!=power2) //������߲��ȣ�˵����һ��ڶ��β���
        {
            changeFlag=1;//���ñ仯��־λ
            if(power1>power2) 
            {
                pc=power1-0.16;// ÿ20ms�仯0.5kw,7ms����һ�Σ�21ms����0.51KW
                power1=pc;
                if(power1<=power2)
                {
                    
                    pc=power2;
                    changeFlag=0; 
                }
            }
            else if(power1<power2) 
            {
                pc=power1+0.16;// ÿ5ms�仯0.05kw
                power1=pc;
                if(power1>=power2) 
                {
                    
                    pc=power2;
                    changeFlag=0;
                }
            }
        } 
        else 
        {
            changeFlag=0; 
        }
    
    } 
    return pc; 
    
}
//***********************************************************************************************
//************************************************************************************************
//************************************the end*****************************************************
//************************************************************************************************
//***********************************************************************************************
//************************************************************************************************