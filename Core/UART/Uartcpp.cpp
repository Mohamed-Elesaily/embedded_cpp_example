#include"Uartcpp.hpp"
UART_HandleTypeDef Uart::huart;
uint8_t Uart::recieveByte;
Uart::Uart(){
  __HAL_RCC_GPIOA_CLK_ENABLE();
	huart.Init.BaudRate = 9600;
    huart.Instance = USART2;
	huart.Init.WordLength = UART_WORDLENGTH_8B;
    huart.Init.StopBits = UART_STOPBITS_1;
    huart.Init.Parity = UART_PARITY_NONE;
    huart.Init.Mode = UART_MODE_TX_RX;
    huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart.Init.OverSampling = UART_OVERSAMPLING_16;
    // HAL_UART_Init(&huart);
      if (HAL_UART_Init(&huart) != HAL_OK)
  {
   
  }
}

void Uart::uartBaudRate(uint16_t rate_HZ){
    huart.Init.BaudRate = 9600;
}
void Uart::uartPeripheral(uint8_t peripheral_num){
    switch (peripheral_num)
    {
    case '1':
        huart.Instance = USART1;
        __HAL_RCC_GPIOA_CLK_ENABLE();
        break;
    case '2':
        huart.Instance = USART2;
        __HAL_RCC_GPIOB_CLK_ENABLE();
    default:
       huart.Instance = USART3;
        __HAL_RCC_GPIOA_CLK_ENABLE();
        break;
    }
    
}
UART_HandleTypeDef Uart::getUartHandler(){
    return huart;
}


uint8_t Uart::uartInit(){
    if(HAL_UART_Init(&huart) != HAL_OK)
        return 0;
    return 1;
}

uint8_t* Uart::recieveByteAddress(){
    return &recieveByte;
}
uint8_t  Uart::getRecieveByte(){
    return recieveByte;
}

