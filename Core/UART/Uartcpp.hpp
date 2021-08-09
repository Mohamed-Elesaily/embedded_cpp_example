#ifndef UART_CPP
#define UART_CPP
#include<stdint.h>
#include "stm32f1xx_hal.h"

class Uart{
    private:
        UART_HandleTypeDef* huart;
        
    public:
        Uart();
        /**
         * @param rate_HZ:
         * 9600,11520
        */
        void uartBaudRate(uint16_t rate_HZ);
        /**
         * @param peripheral_num: 
         *      1 -> USART1 ,
         *      2 -> USART2 ,
         *      3 -> USART3 
         * */ 
        void uartPeripheral(uint8_t peripheral_num);
        /**
         * @return 1->successfully initialized 
         * */ 

        UART_HandleTypeDef* getUartHandler();

        uint8_t uartInit();

};







#endif