#include "variablesCompartidas.h"

#define PIN_SENSOR_SUSTRATO 13 // Pin analógico del ESP32

class SensorSustrato {
private:
    uint8_t humedadSustrato; //Valor del sensor de humedad del sustrato.

    static void initSensorSustrato();
    void vTaskSensorSustrato();

public:
    SensorSustrato();
    
    static void vTaskSensorSustratoWrapper(void *pvParameters);
    void readSensor();
};
