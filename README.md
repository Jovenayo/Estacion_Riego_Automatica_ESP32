# Sistema de Riego Automático con ESP32

Este proyecto consiste en el diseño y desarrollo de un sistema empotrado utilizando un ESP32 para controlar el riego automático de plantas. El sistema incluye un sensor de humedad de sustrato, una pantalla LCD para mostrar la información del sensor, y un relé que activa una bomba de agua cuando el sensor de humedad detecta un nivel de humedad del 0%.

## Descripción del Proyecto

El objetivo principal del proyecto es mantener el nivel de humedad adecuado en el sustrato de las plantas mediante el control automático de una bomba de agua. El sistema funciona de la siguiente manera:

1. **Sensor de Humedad de Sustrato**: Detecta el nivel de humedad del sustrato y envía los datos al ESP32.
2. **ESP32**: Procesa los datos del sensor y toma decisiones basadas en el nivel de humedad detectado.
3. **LCD**: Muestra la información del sensor de humedad en tiempo real.
4. **Relé y Bomba de Agua**: Se activa la bomba de agua cuando el sensor de humedad detecta un nivel de humedad del 0%.

## Esquemático del Proyecto

![Esquemático del Proyecto](ruta/al/esquematico.png)

## Componentes

- ESP32
- Sensor de humedad de sustrato
- Pantalla LCD
- Relé
- Bomba de agua
- Cables y conectores

## Instrucciones de Instalación

1. **Clonar el repositorio**:
    ```bash
    git clone https://github.com/tu-usuario/nombre-del-repositorio.git
    cd nombre-del-repositorio
    ```

2. **Conectar los componentes** según el esquemático proporcionado.

3. **Instalar las dependencias** necesarias:
    - Instalar las librerías de Arduio ara el ESP32 y la pantalla LCD (LiquidCrystal I2C).

4. **Subir el código al ESP32**:

```        
a)
    - Inicia en el PlatfomIO (extension del VisualStudioCode).
    - Iporta el  proyecto dle repositorio github.
    - Carga el codio en el Esp32 con la funcion dedicada de la interfaz.
``` 
``` 
b)

    - Abre el archivo `main.ino` en el IDE de Arduino.
    - Selecciona la placa `ESP32` y el puerto correcto.
    - Sube el código al ESP32.
```
## Uso

1. Conecta el ESP32 a la fuente de alimentación.
2. El sensor de humedad comenzará a leer los datos del sustrato.
3. La información del sensor se mostrará en la pantalla LCD.
4. Si el sensor detecta un nivel de humedad del 0%, el relé activará la bomba de agua para regar las plantas.

## Contribuciones

Las contribuciones son bienvenidas. Por favor, sigue los pasos a continuación para contribuir al proyecto:

1. Haz un fork del proyecto.
2. Crea una nueva rama con tus cambios:
    ```bash
    git checkout -b mi-rama
    ```
3. Realiza tus cambios y haz commit:
    ```bash
    git commit -m "Descripción de los cambios"
    ```
4. Sube tus cambios a tu repositorio fork:
    ```bash
    git push origin mi-rama
    ```
5. Abre un Pull Request en el repositorio original.

## Licencia
