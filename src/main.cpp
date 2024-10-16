#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/uart.h>
#include "soc/rtc_wdt.h"


//#include "SensorSustrato.h"
#include "LCD_I2C.h"
#include "BombaAgua.h"
#include <esp_task_wdt.h>




void setup(void){

  esp_task_wdt_init(10, true);  // 10 segundos antes de que el Watchdog dispare un reinicio

  // Inicializacion de objetos del Sistema.
  Serial.begin(115200);
  Serial.println("\n==== Inicializacion de Objetos ====\r");

    Serial.println("[OK] Serial\r");
  SensorSustrato sensorSustrato;
    Serial.println("[OK] Sensor Sustrato\r");
  BombaAgua bombaAgua(TIEMPO_ACTIVA, TIEMPO_ESPERA, HUMEDAD_HUMBRAL, &sensorSustrato);
    Serial.println("[OK] Bomba De Agua\r");
    Serial.println("[  ] Inicilizando LCDisplay  \r");
  LCD_I2C lcd_i2c;
    Serial.println("[OK]\r");

  
  // // Inicialización del UART para la comunicación serial
  //   uart_config_t uart_config = {
  //       .baud_rate = 115200,
  //       .data_bits = UART_DATA_8_BITS,
  //       .parity    = UART_PARITY_DISABLE,
  //       .stop_bits = UART_STOP_BITS_1,
  //       .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
  //   };
  //   uart_param_config(UART_NUM_0, &uart_config);
  //   uart_driver_install(UART_NUM_0, 1024 * 2, 0, 0, NULL, 0);

  //   ESP_LOGI("main.cpp", "System initialized");
  // /*******************************************************/
 
  Serial.println("\n==== Inicializacion de Tareas ====\r");

  xTaskCreate(SensorSustrato::vTaskSensorSustrato, "vtaskSensorSustrato", 2048, &sensorSustrato, 1, NULL);
  // xTaskCreate(LCD_I2C::vTaskLCD_I2CWrapper, "vtaskLCD_I2C", 2048, &lcd_i2c, 1, NULL);
  // xTaskCreate(BombaAgua::vTaskBombaAguaWrapper, "vtaskBomabAgua", 2048, &bombaAgua, 1, NULL);

}

void loop(){
}


