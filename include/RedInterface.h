#include <WiFi.h>

#define INTERFACE_MODE_WIFI_AP 0

/***** Wifi Macros *****/
#define SSID (const char*)"EstacionCacharro"
#define PASSWD (const char*)"admin"
#define CHANNEL (int) 1 //Canal de la señal Wifi.
#define MAX_CONNECTIONS (int) 2
#define LOCAL_IP 192, 168, 0, 2
#define GATEWAY 192, 168, 0, 1
#define MASK 0, 0, 0, 255
/***********************/


class RedInterface{
public:
    RedInterface(uint8_t mode);
    uint8_t mode;

private:
    void setModoWIfiAP();



};