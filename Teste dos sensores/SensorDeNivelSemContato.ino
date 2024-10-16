const int sensorPin = 5;  // Pino conectado à saída do sensor
int sensorState = 0;      // Variável para armazenar o estado do sensor

void setup() {
    Serial.begin(9600);          // Inicializa a comunicação serial
    pinMode(sensorPin, INPUT);   // Configura o pino do sensor como entrada
}

void loop() {
    sensorState = digitalRead(sensorPin);  // Lê o estado do sensor

    if (sensorState == HIGH) {
        Serial.println("Liquido detectado!"); // O nível de líquido foi detectado
    } else {
        Serial.println("Liquido não detectado."); // Nenhum líquido detectado
    }

    delay(1000);  // Aguarda meio segundo antes de ler novamente
}