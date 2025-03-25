/*
 * bsp_led.h
 *
 *  Created on: Mar 25, 2025
 *      Author: compro
 */

#ifndef BSP_INC_BSP_LED_H_
#define BSP_INC_BSP_LED_H_

void bsp_InitLed(void);             // led 제어 드라이버 초기화
void bsp_LedOn(uint8_t _no);        // led on 함수
void bsp_LedOff(uint8_t _no);       // led off 함수  

#endif /* BSP_INC_BSP_LED_H_ */
