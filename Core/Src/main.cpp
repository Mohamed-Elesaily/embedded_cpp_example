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

//configure uart
  BLE::uartBaudRate(9600);
  BLE::uartPeripheral((uint8_t)2);
  BLE::uartInit();

  huart2 =  BLE::getUartHandler();
  BLE::uartInit();


  HAL_UART_Receive_IT(&huart2, BLE::recieveByteAddress(), 1);

    while (1)
    {
        if(ble.receiveByte() == 'S')
        {
        	led.led_on();

        }
        else if(ble.receiveByte() == 'F')
        {
            led.led_off();
        }

    }
}


