#include <Arduino.h>
#include "variablesCompartidas.h"


#define PIN_SENSOR_SUSTRATO 13 // Pin analógico del ESP32

/*****Sensro de Humedad del suelo*******/

extern int sensorEarthValue;

//_____Funciones_____

void initSensorEarth();
void vTaskSensorEarth();
void readSensor();

/**************************************/