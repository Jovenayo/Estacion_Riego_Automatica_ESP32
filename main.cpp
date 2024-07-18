#include <Arduino.h>
#include "vTasKSensorEarth.h"
#include "vTaskLicuidCristalI2C.h"
#include "vTaskBombaAgua.h"

void setup() {

  Serial.begin(115200); // Iniciar comunicación serial

  initSensorEarth();
  initLicuidCristalI2C();
  initBombaAgua();
}

void loop() {

  vTaskSensorEarth();
  vTaskLicuidCristalI2C();
  vTaskBombaAgua(); 
}

