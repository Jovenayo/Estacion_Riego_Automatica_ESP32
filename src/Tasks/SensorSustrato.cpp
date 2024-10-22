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

void SensorSustrato::vTaskSensorSustrato(void *pvParameters){
    #ifdef DEBUG_MODE
    Serial.println("[Tarea_SensroSustrato] {Debug_Mode}---> Funcion ejecutandose: vTaskSensorSustrato()");
    #endif
    SensorSustrato *instance = static_cast<SensorSustrato*>(pvParameters);
    instance->start();
    
    #ifdef DEBUG_MODE
    Serial.println("[Tarea_SensroSustrato] [OK] vTaskSensorSustrato()");
    #endif
}

void SensorSustrato::start(){
  #ifdef DEBUG_MODE
    Serial.println("[OK] Sensor Sustrato\r");
  #endif
  while(1){
    esp_task_wdt_reset();
    readSensor();

    if(humedadPorcentaje == 0){
      #ifdef DEBUG_MODE
      Serial.println("|||Flag 1|||");
      #endif
      delay(5000);
      #ifdef DEBUG_MODE
      Serial.println("|||Flag 2|||");
      #endif
      readSensor();
      #ifdef DEBUG_MODE
      Serial.println("|||Flag 3|||");
      #endif

      
      if(humedadPorcentaje == 0){
        flagLicuidCristal_I2C = 0x00;
        flagBombaAgua = 0x01;
      }
    }

    esp_task_wdt_reset();
    vTaskDelay(pdMS_TO_TICKS(1000));
    
    #ifdef DEBUG_MODE
    Serial.println("[Tarea_SensorSustrato] {Debug_Mode}---> SensroSustrato.start(): Se ha ejecutado un ciclo.");
    #endif 
  }
}

void SensorSustrato::readSensor(){
  humedadSustrato = analogRead(PIN_SENSOR_SUSTRATO); // Leer el valor analógico
  humedadPorcentaje = map(humedadSustrato, 4095, 0, 0, 100);
  
  #ifdef DEBUG_MODE
  Serial.println("[Tarea_SensorSustrato] {Debug_Mode}---> [OK] readSensor()\r");
  #endif
}