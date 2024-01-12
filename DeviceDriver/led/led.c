/*************************************************************************
版权所有:
项目名称：STM32F407ZGT6
项目编号：
文 件 名: led.c
文件描述: led驱动
其他说明: 
修改历史:  
      作者     日期         版本     修改内容 
      XXX     XX/XX/XX      1.0      创建   
**************************************************************************/
#include "stm32f4xx.h"

#include "led.h"

//=========================内部接口声明============================
static void LedGPIOInit(void);

//===========================内部接口==============================
//=================================================================
static void LedGPIOInit(void)
{
	GPIO_InitTypeDef GPIO_Init_Struct;
	
	//打开IO时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	//PF9--LED1、PF10--LED2、PF6--LED3
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


//========================外部接口=================================
//函 数 名：初始化LED 1、2、3、4
//功能描述：初始化LED引脚 
//输    入：无
//输    出：无
//返    回：无
//历史记录：
//<作者>   <时间>      <修改记录>
//         2024/1/10    创建函数
//=================================================================
void InitLed(void)
{
  LedGPIOInit();
}


/**=================================================================
 函 数 名：LedCtrl
 功能描述：控制led灯开关
 输    入：
 					ucLed --LED1、LED2、LED3、LED4
					bStatus：TRUE--开、FALSE--灭
 输    出：无
 返    回：无
 历史记录：
 <作者>   <时间>      <修改记录>
          2024/1/10   创建函数
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
 函 数 名：LedCtrl
 功能描述：控制led灯开关
 输    入：
 					ucLed --LED1、LED2、LED3、LED4
					uFre  --频率 Hz
 输    出：无
 返    回：无
 历史记录：
 <作者>   <时间>      <修改记录>
          2024/1/10   创建函数
=================================================================**/
void LedBlink(u8 ucLed, u16 uFre)
{
	
	
}

