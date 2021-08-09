#include "main.h"
#include "cmsis_os.h"
#include"LED.hpp"
#include"Uartcpp.hpp"
#include"BLE.hpp"
UART_HandleTypeDef huart2;


int main(void)
{

  HAL_Init();

  HAL_RCC_DeInit();
  SystemCoreClockUpdate();

  Led led;
  BLE ble;

  huart2 =  BLE::getUartHandler();
  BLE::uartInit();
  HAL_UART_Receive_IT(&huart2, BLE::recieveByteAddress(), 1);

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
    	HAL_UART_Receive_IT(&huart2, BLE::recieveByteAddress(), 1);

    }
}
