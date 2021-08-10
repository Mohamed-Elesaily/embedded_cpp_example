#ifndef UART_CPP
#define UART_CPP
#include<stdint.h>
#include "stm32f1xx_hal.h"
#include "main.h"
class Uart{
    private:
        static UART_HandleTypeDef huart;
        static uint8_t recieveByte;

    public:
        // Uart();
        /**
         * @param rate_HZ:
         * 9600,11520
        */
        static void uartBaudRate(uint16_t rate_HZ);
        /**
         * @param peripheral_num: 
         *      1 -> USART1 ,
         *      2 -> USART2 ,
         *      3 -> USART3 
         * */ 
        static void uartPeripheral(uint8_t peripheral_num);
        /**
         * @return 1->successfully initialized 
         * */ 

        static UART_HandleTypeDef getUartHandler();
        
        static uint8_t uartInit();

        static uint8_t* recieveByteAddress();
        uint8_t  getRecieveByte();

    friend
    void USART2_IRQHandler(void);
};







#endif
