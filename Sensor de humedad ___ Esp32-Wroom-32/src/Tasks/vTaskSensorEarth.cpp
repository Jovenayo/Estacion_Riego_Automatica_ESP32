#include "vTaskSensorEarth.h"

//_____Variables_____
int sensorEarthValue = 0;
int humidityPercent = 0;

uint8_t flagSensorEarth = 0x01; 
/* 
(0x00) - Desactivacion  
(0x01) - Encendido
*/

void initSensorEarth(){

  pinMode(PIN_SENSOR_SUSTRATO, INPUT_PULLDOWN);// Iniciar Sensor de humedad de la tierra.
}

void vTaskSensorEarth(){

  readSensor();

  if(humidityPercent == 0){
    delay(5000);
    readSensor();
    
    if(humidityPercent == 0){
      flagLicuidCristalI2C = 0x00;
      flagBombaAgua = 0x01;
    }
  }
}

void readSensor(){
  sensorEarthValue = analogRead(PIN_SENSOR_SUSTRATO); // Leer el valor analógico
  humidityPercent = map(sensorEarthValue, 4095, 0, 0, 100);
}