#include "SensorSustrato.h"

//_____Variables_____
uint8_t humedadSustrato = 0;
uint8_t humedadPorcentaje = 0;
uint8_t flagSensorEarth = 0x01; 
/* 
(0x00) - Desactivacion  
(0x01) - Encendido

*/
SensorSustrato::SensorSustrato(){
  initSensorSustrato();
}

void SensorSustrato::initSensorSustrato(){

  pinMode(PIN_SENSOR_SUSTRATO, INPUT_PULLDOWN);// Iniciar Sensor de humedad de la tierra.
}

void SensorSustrato::vTaskSensorSustratoWrapper(void *pvParameters){
  SensorSustrato *instance = static_cast<SensorSustrato*>(pvParameters);
  instance->vTaskSensorSustrato();
}

void SensorSustrato::vTaskSensorSustrato(){

  readSensor();

  if(humedadPorcentaje == 0){
    delay(5000);
    readSensor();
    
    if(humedadPorcentaje == 0){
      flagLicuidCristal_I2C = 0x00;
      flagBombaAgua = 0x01;
    }
  }
}

void SensorSustrato::readSensor(){
  humedadSustrato = analogRead(PIN_SENSOR_SUSTRATO); // Leer el valor analógico
  humedadPorcentaje = map(humedadPorcentaje, 4095, 0, 0, 100);
}