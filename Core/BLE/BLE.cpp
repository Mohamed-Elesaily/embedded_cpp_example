#include"BLE.hpp"

BLE::BLE(){
    uartBaudRate(9600);
    uartPeripheral(2);
    uartInit();

}

uint8_t * BLE::receiveByte(){
    return byteData;
}