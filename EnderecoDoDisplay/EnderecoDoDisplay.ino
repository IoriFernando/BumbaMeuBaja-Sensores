#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço padrão do LCD (geralmente 0x27 ou 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Altere 0x27 se necessário

void setup() {
  Wire.begin();
  lcd.begin();
  lcd.backlight();
  
  lcd.print("Teste LCD I2C");
}

void loop() {
  // Nessa parte, você pode usar o código para detectar o endereço do LCD
  lcd.setCursor(0, 1); // Move o cursor para a segunda linha
  lcd.print("Scan I2C...");
  
  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("I2C Addr: ");
      lcd.print(address, HEX); // Mostra o endereço em hexadecimal
      delay(1000); // Espera um segundo para ver o endereço
    }
  }
  
  delay(1000); // Espera um segundo antes de começar novamente
}
