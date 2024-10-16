#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Inclui a biblioteca do LCD I2C

// Definir o pino de dados do DS18B20
#define ONE_WIRE_BUS 2  // Pino de dados conectado ao pino digital 2 do Arduino
#define SENSOR_PIN_SPEED 3  // Pino do sensor de velocidade
#define SENSOR_PIN_LIQUID 5  // Pino do sensor de líquido

// Criar o objeto OneWire para comunicar com o sensor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Inicializa o display LCD com o endereço I2C e tamanho 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Altere o endereço se necessário

volatile int pulseCount = 0;  // Contador de pulsos
unsigned long lastTime = 0;    // Último tempo medido
float speed = 0.0;             // Velocidade em m/s
int liquidSensorState = 0;     // Variável para armazenar o estado do sensor de líquido

void setup() {
    Serial.begin(9600);  // Inicializa a comunicação serial a 9600 bps
    pinMode(SENSOR_PIN_SPEED, INPUT);  // Configura o pino do sensor de velocidade como entrada
    pinMode(SENSOR_PIN_LIQUID, INPUT);  // Configura o pino do sensor de líquido como entrada
    attachInterrupt(digitalPinToInterrupt(SENSOR_PIN_SPEED), countPulse, RISING);  // Configura interrupção para contar pulsos
    sensors.begin();  // Inicia a biblioteca de sensores de temperatura
    lcd.begin();      // Inicializa o LCD
    lcd.backlight();  // Ativa o fundo do LCD
}

void loop() {
    // Chama as funções dos sensores
    readSpeedSensor();
    readTemperatureSensor();
    readLiquidSensor();


    delay(500);  // Atraso de 500 ms
}

void readSpeedSensor() {
    unsigned long currentTime = millis();  // Obtém o tempo atual em milissegundos

    // A cada 1000 ms (1 segundo), calcule a velocidade
    if (currentTime - lastTime >= 1000) {
        // Cálculo da distância percorrida em metros
        float distance = (pulseCount / 4.0) * (PI * (21 * 0.0254));  // Atualiza para 1.675 metros
        speed = distance;  // Velocidade em m/s
        
        // Conversão de m/s para km/h
        speed = speed * 3.6; // km/h
        
        // Arredondar a velocidade para um número inteiro
        int speedInt = static_cast<int>(round(speed)); 

        // Exibe a velocidade no LCD
        lcd.setCursor(0, 0);  // Move o cursor para a primeira linha
        lcd.print("V:");
        lcd.print(speedInt);  // Imprime a velocidade como número inteiro
        lcd.print(" km/h");    // Imprime a unidade

        // Resetar contadores
        pulseCount = 0;  // Reseta o contador de pulsos
        lastTime = currentTime;  // Atualiza o último tempo
    }
}

void countPulse() {
    pulseCount++;  // Incrementa o contador de pulsos
}

void readLiquidSensor() {
    liquidSensorState = digitalRead(SENSOR_PIN_LIQUID);  // Lê o estado do sensor de líquido

    // Exibe o estado do sensor no LCD
    lcd.setCursor(0, 1);  // Move o cursor para a segunda linha
    if (liquidSensorState == HIGH) {
        lcd.print("Tanque: Cheio");  // O nível de líquido foi detectado
    } else {
        lcd.print("Tanque: Vazio");  // Nenhum líquido detectado
    }
}

void readTemperatureSensor() {
    // Solicitar que os sensores façam a leitura de temperatura
    sensors.requestTemperatures();

    // Imprimir a temperatura do sensor (em graus Celsius)
    float temperature = sensors.getTempCByIndex(0);  // O '0' indica que estamos lendo o primeiro sensor DS18B20
    
    Serial.print("");
    Serial.print(temperature);  // Imprime a temperatura
    Serial.println(" C");
    
    // Aqui você pode decidir se deseja exibir a temperatura no LCD ou apenas no Serial
    // Se quiser exibir no LCD, adicione o seguinte:
    lcd.print("T: ");   // Imprime "Temp:"
    lcd.print(temperature); // Exibe a temperatura
    lcd.print(" C ");      // Imprime a unidade
}