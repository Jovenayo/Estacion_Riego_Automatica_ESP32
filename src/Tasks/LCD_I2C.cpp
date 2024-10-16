#include "LCD_I2C.h"


LiquidCrystal_I2C lcd(0x27, 2, 6);

//_____Variables_____

String mensaje = "No message";
uint8_t flagLicuidCristal_I2C = 0x01; 
/* 
(0x00) - Desactivacion  
(0x01) - Encendido
(0x02) - Reinicio

*/

LCD_I2C::LCD_I2C(){

  initLCD_I2C();
}

void LCD_I2C::initLCD_I2C(){

  Wire.begin(I2C_SDA, I2C_SCL);

  #ifdef DEBUG_MODE
  Serial.println(" |---> {Wire}: begin()\r");
  #endif
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  #ifdef DEBUG_MODE
  Serial.println(" |---> {ldc}: init()\r");
  #endif
}

void LCD_I2C::vTaskLCD_I2CWrapper(void *pvParameters){
  LCD_I2C *instance = static_cast<LCD_I2C*>(pvParameters);
  instance->vTaskLCD_I2C();
}

void LCD_I2C::vTaskLCD_I2C(){
  lcd.clear();

  switch (flagLicuidCristal_I2C)
  {
    case 0x00:
      lcd.clear();
      return;

    case 0x01:
      mostrarInformacion();
      break;

  case 0x02:
    lcd.init();//solucion al bug de forma ineficiente.
    flagLicuidCristal_I2C = 0x01;
    break;
  }
}

void LCD_I2C::mostrarInformacion(){
  lcd.setCursor(0, 0);
  mensaje = "Humedad=> " + String(humedadPorcentaje) + "%";
  lcd.print(mensaje);
  lcd.setCursor(0, 1);

  if(humedadPorcentaje > 80){
    lcd.print(" (* O *) ");

  } else if(humedadPorcentaje > 25){
    lcd.print(" (^ _ ^) ");

  } else {
    lcd.print(" (* x *) ");
  }
  delay(1000);
}