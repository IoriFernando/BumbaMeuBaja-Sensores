const int sensorPin = 3;  // Pino do sensor
//o sensorPin pode ser alterado para qualquer um dos pinos digitais do Arduino Mega que suportem interrupções externas
/*
Pino 2 → digitalPinToInterrupt(2)
Pino 3 → digitalPinToInterrupt(3)
Pino 18 → digitalPinToInterrupt(18)
Pino 19 → digitalPinToInterrupt(19)
Pino 20 → digitalPinToInterrupt(20)
Pino 21 → digitalPinToInterrupt(21)
*/
volatile int pulseCount = 0;  // Contador de pulsos
unsigned long lastTime = 0;  // Último tempo medido
float speed = 0.0;  // Velocidade em m/s

void setup() {
    Serial.begin(9600);  // Inicializa a comunicação serial a 9600 bps
    pinMode(sensorPin, INPUT);  // Configura o pino do sensor como entrada
    attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING);  // Configura interrupção para contar pulsos
}

void loop() {
    unsigned long currentTime = millis();  // Obtém o tempo atual em milissegundos
    
    // A cada 1000 ms (1 segundo), calcule a velocidade
    if (currentTime - lastTime >= 1000) {
        // Cálculo da distância percorrida em metros
        float distance = (pulseCount / 4.0) * (PI * (21 * 0.0254));  // Atualiza para 1.675 metros
        speed = distance;  // Velocidade em m/s
        
        // Conversão de m/s para km/h
        speed = speed * 3.6; // km/h
        
        Serial.print("Velocidade: ");
        Serial.print(speed);
        Serial.println(" km/h");  // Imprime a velocidade no monitor serial

        // Resetar contadores
        pulseCount = 0;  // Reseta o contador de pulsos
        lastTime = currentTime;  // Atualiza o último tempo
    }
}

void countPulse() {
    pulseCount++;  // Incrementa o contador de pulsos
}