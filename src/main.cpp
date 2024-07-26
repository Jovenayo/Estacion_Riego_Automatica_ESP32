#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/uart.h>

//#include "SensorSustrato.h"
#include "LCD_I2C.h"
#include "BombaAgua.h"

SensorSustrato sensorSustrato;
BombaAgua bombaAgua(TIEMPO_ACTIVA, TIEMPO_ESPERA, HUMEDAD_HUMBRAL, &sensorSustrato);
LCD_I2C lcd_i2c;

void setup(void){

  // Inicialización del UART para la comunicación serial
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_NUM_0, &uart_config);
    uart_driver_install(UART_NUM_0, 1024 * 2, 0, 0, NULL, 0);

    ESP_LOGI("main.cpp", "System initialized");
  /*******************************************************/

  xTaskCreate(SensorSustrato::vTaskSensorSustratoWrapper, "vtaskSensorSustrato", 2048, &sensorSustrato, 1, NULL);
  xTaskCreate(LCD_I2C::vTaskLCD_I2CWrapper, "vtaskLCD_I2C", 2048, &lcd_i2c, 1, NULL);
  xTaskCreate(BombaAgua::vTaskBombaAguaWrapper, "vtaskBomabAgua", 2048, &bombaAgua, 1, NULL);

}

void loop(){

}


