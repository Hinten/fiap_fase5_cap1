#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "painel_lcd/painel.h"
#include "sensores/sensor_dht22/sensor_dht22.h"
#include <DHT.h>
#include <sensores/sensor_ldr/sensor_ldr.h>
#include <sensores/sensor_umidade_solo/sensor_umidade_solo.h>

SensorDHT22 sensor_dht22 = {5, DHT22}; // Pino 5, Tipo DHT22

PainelLCD painel_lcd = {0x27, 16, 2, 21, 22};

SensorLDR sensor_ldr = {4, 3.3, 10000}; // Pino 34, VCC 3.3V, Resistor 10k ohms

SensorUmidadeSolo sensor_umidade_solo = {2, 4095, 0}; // Pino 34, valor seco 4095, valor úmido 0


void setup() {
    Serial.begin(115200);
    painel_lcd.setup();
    sensor_dht22.setup();
    sensor_ldr.setup();
    sensor_umidade_solo.setup();
}


void primaryTask()
{
    const auto temperature = sensor_dht22.getTemperature();
    const auto humidity = sensor_dht22.getHumidity();
    const auto lux = sensor_ldr.read_lux();
    const auto solo_humidity = sensor_umidade_solo.read_humidity();

    painel_lcd.printFloatLcdSerial(0, 0, "Temp: ", temperature, " C");
    painel_lcd.printFloatLcdSerial(0, 1, "Umid: ", humidity, " %");
    delay(1000);

    painel_lcd.printFloatLcdSerial(0, 0, "LUX: ", lux);
    painel_lcd.printFloatLcdSerial(0, 1, "Solo: ", solo_humidity, " %");
}

unsigned long ultimoMillis = 0;
const unsigned long intervalo = 2000; // 2 segundos

void loop() {
    unsigned long agora = millis();
    if (agora - ultimoMillis >= intervalo) {
        ultimoMillis = agora;
        primaryTask();
    }
}



