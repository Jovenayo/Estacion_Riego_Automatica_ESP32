#include "variablesCompartidas.h"
#include "SensorSustrato.h"

#define PIN_BOMABA_AGUA 12
#define TIEMPO_ACTIVA (uint8_t)2500
#define TIEMPO_ESPERA (uint8_t)5000
#define HUMEDAD_HUMBRAL (uint8_t)50

class BombaAgua {
private:
    uint8_t tiempoActiva; //Tiempo de pulso para activacion del motor.
    uint8_t tiempoEspera; //Tiempo de intervalo entre pulsos.
    uint8_t humedadHumbral; //Humedad a partir de la cual deja de regar.
    SensorSustrato* sensorSustrato; //Puntero al objeto SensorSustrato.
    
    static void initBombaAgua();
    void regar();
    void vTaskBombaAgua();

public:
    BombaAgua(uint8_t tiempoActiva, uint8_t tiempoEspera, uint8_t humedadHumbral, SensorSustrato* sensorSustrato);
    static void vTaskBombaAguaWrapper(void *pvParameters);

};