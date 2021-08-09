#include "main.h"
#include"LED.hpp"
#include"Uartcpp.hpp"
UART_HandleTypeDef* huart2;
Uart uart;
int main(void)
{

  HAL_Init();

  HAL_RCC_DeInit();
  SystemCoreClockUpdate();

  Led led;

  uart.uartBaudRate(9600);
  uart.uartPeripheral(2);

  huart2 = uart.getUartHandler();
    while (1)
    {
        if(uart.getRecieveByte() == 'S')
        {
        	led.led_on();

        }
        else if(uart.getRecieveByte()  == 'F')
        {
            led.led_off();
        }
    }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == huart2->Instance)
    {
    HAL_UART_Receive_IT(huart2, uart.recieveByteAddress(), 1);
    }
}
