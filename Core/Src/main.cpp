#include "main.h"
#include"LED.hpp"
#include"Uartcpp.hpp"
#include"BLE.hpp"
UART_HandleTypeDef huart2;

BLE ble;
int main(void)
{

  HAL_Init();

  HAL_RCC_DeInit();
  SystemCoreClockUpdate();

  Led led;

  ble.uartInit();
  huart2 =  ble.getUartHandler();
  ble.uartInit();
  HAL_UART_Receive_IT(&huart2, ble.recieveByteAddress(), 1);

    while (1)
    {
        if(ble.getRecieveByte() == 'S')
        {
        	led.led_on();

        }
        else if(ble.getRecieveByte()  == 'F')
        {
            led.led_off();
        }

    }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == huart2.Instance)
    {
    	HAL_UART_Receive_IT(&huart2, ble.recieveByteAddress(), 1);

    }
}
