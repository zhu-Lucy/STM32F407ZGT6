/*************************************************************************
��Ȩ����:
��Ŀ���ƣ�STM32F407ZGT6
��Ŀ��ţ�
�� �� ��: led.c
�ļ�����: led����
����˵��: 
�޸���ʷ:  
      ����     ����         �汾     �޸����� 
      XXX     XX/XX/XX      1.0      ����   
**************************************************************************/
#include "stm32f4xx.h"

#include "led.h"

//=========================�ڲ��ӿ�����============================
static void LedGPIOInit(void);

//===========================�ڲ��ӿ�==============================
//=================================================================
static void LedGPIOInit(void)
{
	GPIO_InitTypeDef GPIO_Init_Struct;
	
	//��IOʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	//PF9--LED1��PF10--LED2��PF6--LED3
	GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 |GPIO_Pin_6;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF,&GPIO_Init_Struct);
	
//	GPIO_SetBits(GPIOF, GPIO_Pin_9);
//	GPIO_SetBits(GPIOF, GPIO_Pin_10);
//	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	
	//PC0--LED4
	GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC,&GPIO_Init_Struct);
	
//	GPIO_SetBits(GPIOC, GPIO_Pin_0);
	
}


//========================�ⲿ�ӿ�=================================
//�� �� ������ʼ��LED 1��2��3��4
//������������ʼ��LED���� 
//��    �룺��
//��    ������
//��    �أ���
//��ʷ��¼��
//<����>   <ʱ��>      <�޸ļ�¼>
//         2024/1/10    ��������
//=================================================================
void InitLed(void)
{
  LedGPIOInit();
}


/**=================================================================
 �� �� ����LedCtrl
 ��������������led�ƿ���
 ��    �룺
 					ucLed --LED1��LED2��LED3��LED4
					bStatus��TRUE--����FALSE--��
 ��    ������
 ��    �أ���
 ��ʷ��¼��
 <����>   <ʱ��>      <�޸ļ�¼>
          2024/1/10   ��������
=================================================================**/
void LedCtrl(u8 ucLed, BOOL bStatus)
{
	switch(ucLed)
	{
		case  LED1: //PF6
			if(TRUE == bStatus)
			{
				GPIO_ResetBits(GPIOF, GPIO_Pin_6);
				
			}
			else
			{
				GPIO_SetBits(GPIOF, GPIO_Pin_6);
			}
			break;
		case LED2:  //PF9
			if(TRUE == bStatus)
			{
				GPIO_ResetBits(GPIOF, GPIO_Pin_9);
			}
			else
			{
				GPIO_SetBits(GPIOF, GPIO_Pin_9);
			}
			break;
		case LED3:   //PF10
			if(TRUE == bStatus)
			{
				GPIO_ResetBits(GPIOF, GPIO_Pin_10);
			}
			else
			{
				GPIO_SetBits(GPIOF, GPIO_Pin_10);
			}
			break;
		case LED4:   //PC0
			if(TRUE == bStatus)
			{
				GPIO_ResetBits(GPIOC, GPIO_Pin_0);
			}
			else
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_0);
			}
			break;
		default:
			break;
	}
}

/**=================================================================
 �� �� ����LedCtrl
 ��������������led�ƿ���
 ��    �룺
 					ucLed --LED1��LED2��LED3��LED4
					uFre  --Ƶ�� Hz
 ��    ������
 ��    �أ���
 ��ʷ��¼��
 <����>   <ʱ��>      <�޸ļ�¼>
          2024/1/10   ��������
=================================================================**/
void LedBlink(u8 ucLed, u16 uFre)
{
	
	
}

