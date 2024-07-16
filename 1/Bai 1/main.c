#include "stm32f10x.h"

void delay(uint32_t time) {
	for (volatile uint32_t i = 0; i < time * 1000; i++);
}

int main() {
	// Turn on clock for APB2
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	// Config PA8 output push-pull
	GPIOA->CRH &= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8); // Clear MODE and CNF bits
	GPIOA->CRH |= GPIO_CRH_MODE8_0 | GPIO_CRH_MODE8_1; // Output mode, max speed 50MHz
	GPIOA->CRH &= ~GPIO_CRH_CNF8; // General purpose output push-pull
	
	while(1){
		// Set PA8
		GPIOA->BSRR = GPIO_BSRR_BS8;
		delay(1000);
		
		// Reset PA8
		GPIOA->BSRR = GPIO_BSRR_BR8;
		delay(1000);
	}
}
