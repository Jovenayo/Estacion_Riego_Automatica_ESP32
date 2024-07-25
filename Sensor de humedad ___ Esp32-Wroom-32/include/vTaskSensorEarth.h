#include <Arduino.h>
#include "variablesCompartidas.h"

#define PIN_SENSOR_SUSTRATO 13

extern int sensorEarthValue;

void initSensorEarth();
void vTaskSensorEarth();
void readSensor();