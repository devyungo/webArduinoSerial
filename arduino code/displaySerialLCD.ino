#include <LiquidCrystal.h>

LiquidCrystal lcd_1(0, 1, 2, 3, 4, 5);

const int maxStringLength = 20; // ajuste conforme necessário
char incomingString[maxStringLength + 1]; // +1 para o caractere nulo

void setup()
{
  lcd_1.begin(16, 2); 
  Serial.begin(9600);
}

void loop()
{
  // Limpar a string definindo todos os caracteres para nulo
  memset(incomingString, 0, sizeof(incomingString));

  if (Serial.available() > 0) {
    // ler a string completa até encontrar um caractere de nova linha ('\n')
    int bytesRead = Serial.readBytesUntil('\n', incomingString, maxStringLength);

    // adicionar o caractere nulo ao final da string
    incomingString[bytesRead] = '\0';

    // set cursor position and print on LCD
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Received: ");
    lcd_1.setCursor(0, 1);
    lcd_1.print(incomingString);
  }
}
