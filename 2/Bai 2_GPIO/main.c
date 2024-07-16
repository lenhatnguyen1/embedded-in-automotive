#include "stm32f10x.h"   // Device header
#include "stm32f10x_rcc.h"       // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"       // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

void RCC_Config() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOD, ENABLE); // Supply clock for GPIOA & GPIOD
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); // Supply clock for Timer2
}

void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStruct;

    // Init PA8
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Init PD2
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void TIM2_Config() {
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
		
		// Config Timer2
		TIM_TimeBaseInitStruct.TIM_Period = 1000 - 1; // Count to 1000 (1ms)
    TIM_TimeBaseInitStruct.TIM_Prescaler = (SystemCoreClock / 1000) - 1; // Divide system freq to be 1ms
    TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    TIM_Cmd(TIM2, ENABLE);
}

void delay_ms(uint32_t time) {
    TIM_SetCounter(TIM2, 0);
		while (time--) {
				while (TIM_GetCounter(TIM2) < 1000);
		}
}


int main() {
    RCC_Config();
    GPIO_Config();
		TIM2_Config();
    
		while(1) {
        GPIO_SetBits(GPIOA, GPIO_Pin_8);
        GPIO_ResetBits(GPIOD, GPIO_Pin_2);
        delay_ms(1000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
        GPIO_SetBits(GPIOD, GPIO_Pin_2);
        delay_ms(1000);
    }
}
