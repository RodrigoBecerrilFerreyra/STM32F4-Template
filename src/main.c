#include "stm32f4xx.h"

void setup(void);
void delay(void);

void main(void)
{
    setup();
    while(1)
    {
        GPIOC->ODR |= GPIO_ODR_OD13;
        delay();
        GPIOC->ODR &= ~GPIO_ODR_OD13;
        delay();
    }
}

void setup(void)
{
    // enable GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    // set GPIOC Pin 13 as output
    GPIOC->MODER &= ~GPIO_MODER_MODER13_Msk;
    GPIOC->MODER |= GPIO_MODER_MODER13_0;
}

void delay(void)
{
    for(unsigned int i = 0; i < 1000000; ++i)
    {

    }
}
