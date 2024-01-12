/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  llw
  * @version V0.0.0
  * @date    2023-01-07
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
	* @par 修改历史   														                             	  \n
  * 修改人   :  															  															  \n
  * 修改日期 :	                                                                \n
  *	修定说明 ：	                                                              \n
  *                                                                           \n
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h" 

#include "led.h"

/** @addtogroup Template_Project
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
  * @brief  系统主程序
  * @param  void
  * @return int
	* @note   系统主循环
  */
int main(void)
{
	InitLed();
	
	LedCtrl(LED1,TRUE);
	LedCtrl(LED2,TRUE);
	LedCtrl(LED3,TRUE);
	LedCtrl(LED4,TRUE);

  while (1)
  {
		
  }
}



/**
  * @}
  */


