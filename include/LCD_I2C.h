#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "variablesCompartidas.h"

#define I2C_SDA 21
#define I2C_SCL 22

class LCD_I2C{
private:
    void initLCD_I2C();
    void vTaskLCD_I2C();

public:
    LCD_I2C();

    static void vTaskLCD_I2CWrapper(void *pvParameters);
    void mostrarInformacion();
};