#include"BLE.hpp"


uint8_t BLE::receiveByte(){
    byteData = getRecieveByte();
    return byteData;
}