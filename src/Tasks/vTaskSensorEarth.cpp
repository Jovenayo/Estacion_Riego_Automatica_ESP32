#include "vTaskSensorEarth.h"

int sensorEarthValue = 0;

//_____Variables_____

uint8_t flagSensorEarth = 0x01; 
/* 
(0x00) - Desactivacion  
(0x01) - Encendido

*/

void initSensorEarth(){

  pinMode(sensorPinEarth, INPUT_PULLDOWN);// Iniciar Sensor de humedad de la tierra.
}



void vTaskSensorEarth(){

  sensorEarthValue = analogRead(sensorPinEarth); // Leer el valor analógico

  delay(200); // Esperar 1 segundo
}