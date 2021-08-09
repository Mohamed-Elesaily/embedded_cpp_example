#include "main.h"
#include"LED.hpp"
#include"BLE.hpp"

BLE ble;
int main(void)
{

  HAL_Init();

  HAL_RCC_DeInit();
  SystemCoreClockUpdate();

  Led led;


    while (1)
    {
        if(*ble.receiveByte() == 'S')
        {
        	led.led_on();

        }
        else if(*ble.receiveByte()  == 'F')
        {
            led.led_off();
        }
    }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == (*ble.getUartHandler()).Instance)
    {
    HAL_UART_Receive_IT(ble.getUartHandler(), ble.receiveByte(), 1);
    }
}
