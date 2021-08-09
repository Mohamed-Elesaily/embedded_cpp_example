#ifndef BLEhpp
#define BLEhpp
#include<stdint.h>
#include "stm32f1xx_hal.h"
#include"Uartcpp.hpp"
class BLE: public Uart{

    private:
        uint8_t * byteData;
        
    public:
        BLE();
        uint8_t * receiveByte();

};





#endif