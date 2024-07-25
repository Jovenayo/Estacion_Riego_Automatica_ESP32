#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "variablesCompartidas.h"

#define I2C_SDA 21
#define I2C_SCL 22

void initLicuidCristalI2C();
void vTaskLicuidCristalI2C();