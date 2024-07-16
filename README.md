# Embedded in Automotive
## Lesson 1: Setup Enviroment for STM32

### Prepare: 
- KeilC
- STM32F1 + STLink V2
- Download firmware ARM Keil

### Register Program:
	- Supply clock pulse
    - Config GPIO
    - Set GPIO to on mode
	Ex: PC13 belongs to GPIOC, receiving pulses from bus APB2, port C, pin 13

    - Open KeilC, import firmware which was download above
    - Config RCC.
    - Config GPIO (Port configuration in manual): PC13 -> GPIOx_CRH (High) -> MODE13[1:0], CNF[1:0]
    - Config mode of GPIO (CNF, MODE)

## Lesson 2: GPIO
STM32F10x Standard Peripherals Firmware Library
Peripheral Config:
Supply clock pulses -> Config Peripheral -> Application

Supply clock pulses
```c
void RCC_Config(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
} 
```
Config Peripheral
```c
void GPIO_Config(){
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13| GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

```
Application

```c
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
```

## Lesson 3: Interrupt & Timer
### Interrupt
Interrupt is to exit the main program and handle unexpected events
1. Reset interrupt
2. External interrupt (programmable)
    - LOW
    - HIGH
    - RISING
    - FALLING
3. Timer interrupt (programmable)
4. Communication interrupt (programmable)
    - UART
    - I2C
    - SPI

### Timer
- Programmable: You can set the timer's count value to determine how often it generates an interrupt (signal).
- Timing Tasks: Ideal for creating delays, generating pulse-width modulated (PWM) signals, or blinking LEDs at a specific rate.
- Interrupt Source: When the timer reaches its count value, it triggers an interrupt, alerting the MCU to perform a specific action.

Benefits:
- Enables precise timing control for various applications.
- Frees up the main program to handle other tasks while the timer handles timing.

```c
void delay_ms(uint8_t timedelay)
    {
    TIM_SetCounter(TIM2,0);
      while(TIM_GetCounter(TIM2)<timedelay*10){}
    }
```
