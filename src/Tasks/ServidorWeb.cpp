#include "ServidorWeb.h"

// Constructor de la clase
ServidorWeb::ServidorWeb(const char* ssid, const char* password)
    : ssid(ssid), password(password), server(80) {}

// Implementación del método que arranca el servidor web y el AP
void ServidorWeb::start() {
    // Iniciar el modo Access Point (AP)
    WiFi.softAP(ssid, password);

    // Mostrar la IP del ESP32
    Serial.print("Servidor AP iniciado\r\nIP Estacion: ");
    Serial.println(WiFi.softAPIP());

    // Configurar la ruta raíz "/"
    server.on("/", [this]() { putHtmlRoot(); });

    // Iniciar el servidor web
    server.begin();
    Serial.println("Servidor Web iniciado.");
}

void ServidorWeb::vTaskServidorWeb(void *pvParameters){
  ServidorWeb *instance = static_cast<ServidorWeb*>(pvParameters);
  instance->start();
}

// Método para manejar las solicitudes HTTP
void ServidorWeb::handleClientRequests() {
    server.handleClient();
}

// Implementación del manejo de la ruta raíz "/"
void ServidorWeb::putHtmlRoot() {
    setHtml(PATH_HTML_ROOT);
}

void ServidorWeb::setHtml(const char* path){
    File fichero = SPIFFS.open(path, "r");
    if(!fichero){
        server.send(404, "test/plain", "404 Pagina no encontrada");
        return;
    }

    String htmlContent = fichero.readString();
    server.send(200, "text/html", htmlContent);
}