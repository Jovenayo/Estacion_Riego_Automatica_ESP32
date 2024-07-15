#include "vTaskLicuidCristalI2C.h"


LiquidCrystal_I2C lcd(0x27, 2, 6);

//_____Variables_____

int humidityPercent = 0;
String mensaje = "No message";
uint8_t flagLicuidCristalI2C = 0x01; 
/* 
(0x00) - Desactivacion  
(0x01) - Encendido

*/

void initLicuidCristalI2C(){

  Wire.begin(I2C_SDA, I2C_SCL);
  
  Serial.println("Wire: [OK]\r\n");

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void vTaskLicuidCristalI2C(){

lcd.clear();
lcd.setCursor(0, 0);
humidityPercent = map(sensorEarthValue, 4095, 0, 0, 100);
mensaje = "Humedad=> " + String(humidityPercent) + "%";
lcd.print(mensaje);
Serial.println("envio");
lcd.setCursor(0, 1);
lcd.print(" (^ _ ^) ");
delay(200);
}