#include "vTaskBombaAgua.h"
#include "vTaskSensorEarth.h"

//_____Variables_____

uint8_t flagBombaAgua = 0x00;
/* 
(0x00) - Desactivacion  
(0x01) - Encendido
*/

//____CLK____________


void initBombaAgua(){

    pinMode(PIN_BOMABA_AGUA, OUTPUT);
}

void vTaskBombaAgua(){

    switch (flagBombaAgua)
    {
    case 0x01:

        while(humidityPercent < 50){
            digitalWrite(PIN_BOMABA_AGUA, HIGH);
            delay(TIEMPO_ACTIVACION);
            digitalWrite(PIN_BOMABA_AGUA, LOW);
            delay(10000);
            readSensor();
        }
        flagBombaAgua = 0x00;
        flagLicuidCristalI2C = 0x02;
    
    case 0x00:
        break;
    }
}