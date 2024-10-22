#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_task_wdt.h>


//Debug flag, para que aparezcan check points de estado de las tareas.
#define DEBUG_MODE

/****** Variables compartidas ******/
extern uint8_t humedadPorcentaje;
/**********************************/

/****** Flag Tascks ***************/
extern uint8_t flagSensorEarth; 
extern uint8_t flagLicuidCristal_I2C;
extern uint8_t flagBombaAgua;
/**********************************/


