#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "variablesCompartidas.h"

#define SSID "Estacion de riego"
#define PASSWORD "admin"
#define PATH_HTML_ROOT "/estacionDeRiego.htm"

#define PORT "80"

class ServidorWeb {
public:
    // Constructor de la clase
    ServidorWeb(const char* ssid, const char* password);

    // Método para iniciar el servidor web y el AP
    static void vTaskServidorWeb(void *pvParameters);
    void start();

    // Método para manejar las peticiones HTTP
    void handleClientRequests();

private:
    const char* ssid;
    const char* password;

    WebServer server; // Servidor web

    // Método para manejar la ruta raíz
    void putHtmlRoot();

    void setHtml(const char* path);

};
