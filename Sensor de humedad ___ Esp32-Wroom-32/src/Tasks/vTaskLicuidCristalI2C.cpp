#include "vTaskLicuidCristalI2C.h"


LiquidCrystal_I2C lcd(0x27, 2, 6);

//_____Variables_____
String mensaje = "No message";

uint8_t flagLicuidCristalI2C = 0x01; 
/* 
(0x00) - Desactivacion  
(0x01) - Encendido
(0x02) - Reinicio

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

  switch (flagLicuidCristalI2C)
  {
    case 0x00:
      lcd.clear();
      return;

    case 0x01:
      lcd.setCursor(0, 0);
      mensaje = "Humedad=> " + String(humidityPercent) + "%";
      lcd.print(mensaje);
      lcd.setCursor(0, 1);

      if(humidityPercent > 80){
        lcd.print(" (* O *) ");

      } else if(humidityPercent > 25){
        lcd.print(" (^ _ ^) ");

      } else {
        lcd.print(" (* x *) ");
      }

      delay(1000);
      break;
  
  case 0x02:
    lcd.init();
    flagLicuidCristalI2C = 0x01;
    break;
  }
}

