#include "main.h"
#include "cmsis_os.h"
#include"LED.hpp"
#include"Uartcpp.hpp"
#include"BLE.hpp"
#include"FreeRTOS.h"
#include"task.h"

uint8_t ON = 1;
UART_HandleTypeDef huart2;

// task handlers
TaskHandle_t BLE_Handler = NULL;
TaskHandle_t LED_Handler = NULL;

// tasks
void ble_Task(void *param);
void led_Task(void *param);

int main(void)
{
// system configuration
  HAL_Init();
  HAL_RCC_DeInit();
  SystemCoreClockUpdate();
//configure uart2
  BLE::uartBaudRate(9600);
  BLE::uartPeripheral((uint8_t)2);
  	  /////////////////////////////////////////////////

//  non blocking receive
  BLE::uartInit();
  huart2 =  BLE::getUartHandler();

  HAL_UART_Receive_IT(&huart2, BLE::recieveByteAddress(), 1);
  	  ////////////////////////////////////////////////

  xTaskCreate(ble_Task, "ble", configMINIMAL_STACK_SIZE, NULL, 1, &BLE_Handler);
  xTaskCreate(led_Task, "led", configMINIMAL_STACK_SIZE, NULL, 1, &LED_Handler);
  vTaskStartScheduler();
    while (1);
}

void ble_Task(void *param){
	BLE ble;
	while(1){
		if(ble.receiveByte() == 'F'){
			ON = 0;
		}else if(ble.receiveByte() == 'B'){
			ON = 1;
		}
	}
}
void led_Task(void *param){
	Led led;
	while(1){
		if(ON) led.led_on();
		else led.led_off();
	}
}



