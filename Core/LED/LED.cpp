#include"LED.hpp"
#include "stm32f1xx_hal.h"

Led::Led(){
    GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
void Led::led_on(){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (GPIO_PinState)1);

}
void Led::led_off(){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0,(GPIO_PinState) 0);
}