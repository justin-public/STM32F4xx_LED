/*
 * bsp_led.c
 *
 *  Created on: Mar 25, 2025
 *      Author: compro
 */
#include "bsp.h"

// 포트 정보를 전처리 합니다
#define GPIO_PORT_LED1  GPIOI
#define GPIO_PIN_LED1	GPIO_PIN_10

#define GPIO_PORT_LED2  GPIOF
#define GPIO_PIN_LED2	GPIO_PIN_7

#define GPIO_PORT_LED3  GPIOF
#define GPIO_PIN_LED3	GPIO_PIN_8

#define GPIO_PORT_LED4  GPIOC
#define GPIO_PIN_LED4	GPIO_PIN_2

/*
*********************************************************************************************************
*   함수 이름: bsp_InitLed
*   함수 설명: 회로에 구성된 LED를 제어하는 포트를 초기화
*   파라미터: None
*   반환값: None
*********************************************************************************************************
*/
void bsp_InitLed(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    __HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

    bsp_LedOff(1);
	bsp_LedOff(2);
	bsp_LedOff(3);
	bsp_LedOff(4);

    GPIO_InitStructure.Pin = GPIO_PIN_LED1;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIO_PORT_LED1, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_LED2|GPIO_PIN_LED3;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_PORT_LED2, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_LED4;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_PORT_LED4, &GPIO_InitStructure);
}

/*
*********************************************************************************************************
*   함수 이름: bsp_LedOn
*   함수 설명: LED 켬 동작을 진행 합니다.
*   파라미터: None
*   반환값: None
*********************************************************************************************************
*/
void bsp_LedOn(uint8_t _no)
{
    _no--;
    if(_no == 0)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED1,GPIO_PIN_LED1,GPIO_PIN_RESET);
    }
    else if(_no == 1)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED2,GPIO_PIN_LED2,GPIO_PIN_RESET);
    }
    else if(_no == 2)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED2,GPIO_PIN_LED3,GPIO_PIN_RESET);
    }
    else if(_no == 3)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED4,GPIO_PIN_LED4,GPIO_PIN_RESET);
    }
}

/*
*********************************************************************************************************
*   함수 이름: bsp_LedOff
*   함수 설명: LED 끔 동작을 진행 합니다.
*   파라미터: None
*   반환값: None
*********************************************************************************************************
*/
void bsp_LedOff(uint8_t _no)
{
    _no--;
    if(_no == 0)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED1,GPIO_PIN_LED1,GPIO_PIN_SET);
    }
    else if(_no == 1)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED2,GPIO_PIN_LED2,GPIO_PIN_SET);
    }
    else if(_no == 2)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED2,GPIO_PIN_LED3,GPIO_PIN_SET);
    }
    else if(_no == 3)
    {
        HAL_GPIO_WritePin(GPIO_PORT_LED4,GPIO_PIN_LED4,GPIO_PIN_SET);
    }
}






















