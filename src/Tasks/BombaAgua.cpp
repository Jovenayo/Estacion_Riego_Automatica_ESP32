#include "BombaAgua.h"

//_____Variables_____
uint8_t flagBombaAgua = 0x00;
/* 
(0x00) - Desactivacion  
(0x01) - Encendido
*/

//____CLK____________

BombaAgua::BombaAgua(uint8_t tiempoActiva, uint8_t tiempoEspera, uint8_t humedadHumbral, SensorSustrato* sensorSustrato): tiempoActiva(tiempoActiva), tiempoEspera(tiempoEspera), humedadHumbral(humedadHumbral),sensorSustrato(sensorSustrato){
    
    initBombaAgua();
}
    
void BombaAgua::initBombaAgua(){
    
    pinMode(PIN_BOMABA_AGUA, OUTPUT);
    #ifdef DEBUG_MODE
        Serial.println("[OK] Bomba De Agua\r");
    #endif
}

void BombaAgua::vTaskBombaAguaWrapper(void *pvParameters){
  BombaAgua *instance = static_cast<BombaAgua*>(pvParameters);
  instance->vTaskBombaAgua();
}

void BombaAgua::vTaskBombaAgua(){

    while(1){

        switch (flagBombaAgua)
        {
        case 0x01:
            regar();
            flagBombaAgua = 0x00;
            flagLicuidCristal_I2C = 0x02;
        
        case 0x00:
            break;
        }
    }
}

void BombaAgua::regar(){
    while(humedadPorcentaje < humedadHumbral){
    digitalWrite(PIN_BOMABA_AGUA, HIGH);
    delay(tiempoActiva);
    digitalWrite(PIN_BOMABA_AGUA, LOW);
    delay(tiempoEspera);
    sensorSustrato->readSensor();
    }
}