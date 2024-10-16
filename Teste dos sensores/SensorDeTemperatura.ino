#include <OneWire.h>
#include <DallasTemperature.h>

// Definir o pino de dados do DS18B20
#define ONE_WIRE_BUS 2  // Pino de dados conectado ao pino digital 2 do Arduino

// Criar o objeto OneWire para comunicar com o sensor
OneWire oneWire(ONE_WIRE_BUS);

// Passar a referência do OneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

void setup() {
  // Iniciar a comunicação serial para visualização no monitor serial
  Serial.begin(9600);
  
  // Iniciar a biblioteca de sensores
  sensors.begin();
}

void loop() {
  // Solicitar que os sensores façam a leitura de temperatura
  sensors.requestTemperatures();

  // Imprimir a temperatura do sensor (em graus Celsius)
  Serial.print("Temperatura: ");
  Serial.print(sensors.getTempCByIndex(0));  // O '0' indica que estamos lendo o primeiro sensor DS18B20
  Serial.println(" °C");

  delay(1000);  // Aguardar 1 segundo antes de realizar outra leitura
}
