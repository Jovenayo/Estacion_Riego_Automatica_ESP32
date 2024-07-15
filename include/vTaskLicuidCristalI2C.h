#ifndef VTASK_LICUID_CRISTAL_I2C_H
#define VTASK_LICUID_CRISTAL_I2C_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "variablesCompartidas.h"

#define I2C_SDA 21
#define I2C_SCL 22

// Declaración de las funciones
void initLicuidCristalI2C();
void vTaskLicuidCristalI2C();

#endif // VTASK_LICUID_CRISTAL_I2C_H
