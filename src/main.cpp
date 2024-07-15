#include <Arduino.h>
#include "vTasKSensorEarth.h"
#include "vTaskLicuidCristalI2C.h"

void setup() {

  Serial.begin(115200); // Iniciar comunicación serial

  initSensorEarth();
  initLicuidCristalI2C();
}

void loop() {

  vTaskSensorEarth();
  vTaskLicuidCristalI2C(); 
}

