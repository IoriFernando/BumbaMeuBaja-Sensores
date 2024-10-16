# BumbaMeuBaja-RedeDeSensores
Desenvolvimento de um nó sensor para o Baja para obter as informações sobre: velocidade, nível de combustível e temperatura no motor. Exibindo as informações em um display lcd.

## Materiais utilizados:
- Arduíno MEGA
- LJ12A3-4-Z/BY (Sensor de indução)
- D18B20 (Sensor de temperatura)
- XKC-Y25-V PNP (Sensor de nível sem contato)
- Resistores: 4k7 e 10k ohms
- Display LCD 16x2 C/ BlackLight AZUL

## Implementação:

### Bibliotecas usadas
 - `OneWire`: Utilizada para comunicação com sensores que operam no protocolo OneWire, como o DS18B20.
- `DallasTemperature`: Uma biblioteca específica para gerenciar sensores de temperatura da série Dallas (DS18B20).
- `Wire`: Biblioteca padrão do Arduino para comunicação I2C.
- `LiquidCrystal_I2C`: Para controlar displays LCD via I2C.

### Definições de Pinos
`ONE_WIRE_BUS`: Define o pino onde o sensor DS18B20 está conectado. (Pino 2)<br>
`SENSOR_PIN_SPEED`: Define o pino do sensor de velocidade. (Pino 3)<br>
`SENSOR_PIN_LIQUID`: Define o pino do sensor de líquido. (Pino 5)<br>
`Pino do display SDA`: Pino SDA (Pino 20), Pino 21 (Pino SCL).

## Agradecimentos:
Agradeço a toda equipe do Bumba meu Baja pela confiança da implementa e desenvolvimento do projeto em especial a Luana de Souza pela paciência e apoio durante todo o processo.