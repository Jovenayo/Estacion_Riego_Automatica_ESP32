#include <Arduino.h>
#include "variablesCompartidas.h"


#define sensorPinEarth 34 // Pin analógico del ESP32

/*****Sensro de Humedad del suelo*******/



//int sensorEarthValue;
extern int sensorEarthValue;

//_____Funciones_____

void initSensorEarth();
void vTaskSensorEarth();

/**************************************/
