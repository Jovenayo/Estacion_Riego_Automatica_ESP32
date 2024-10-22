#include "RedInterface.h"

RedInterface::RedInterface(uint8_t mode): mode(mode){

    #ifdef DEBUG_MODE
    Serial.println("Inicilizando Interfaz de Red del sistema...");
    #endif

    switch (mode)
    {
    case INTERFACE_MODE_WIFI_AP:
        setModoWIfiAP();
        break;
    
    default:

        break;
    }

    #ifdef DEBUG_MODE
    Serial.println("[OK] InerfazInicilizada (Mod.: %d)", mode);
    #endif

}

void RedInterface::setModoWIfiAP(){
    WiFi.softAP(SSID, NULL, CHANNEL, MAX_CONNECTIONS, false/*FTM mide distancia entre dispositivos*/);
    WiFi.softAPConfig(IPAddress(LOCAL_IP), IPAddress(GATEWAY), IPAddress(LOCAL_IP), IPAddress(MASK));
    #ifdef DEBUG_MODE
    Serial.println("    -IP: %d", softAPIP(););
    #endif
}