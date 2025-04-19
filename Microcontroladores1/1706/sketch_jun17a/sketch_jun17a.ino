#include <LiquidCrystal.h>
// Inclui a biblioteca LiquidCrystal.h, necessária para controlar o display LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Cria um objeto lcd da classe LiquidCrystal, usando os pinos 12, 11, 5, 4, 3 e 2

int tempo;            // Declaração da variável tempo
bool moveToRight = true;    // Declaração da variável moveToRight, inicia verdadeira

void setup() {
  lcd.begin(16, 2);       // Inicializa o display LCD com 16 colunas e 2 linhas
  lcd.print("Boa Tarde!");    // Imprime a mensagem "Boa Tarde!" no display LCD
}

void loop() {
  lcd.setCursor(0, 0);      // Define o cursor do display LCD para a posição (0, 0)

  if (moveToRight) {
    lcd.scrollDisplayRight(); // Realiza um scroll do conteúdo do display para a direita
  } else {
    lcd.scrollDisplayLeft();  // Realiza um scroll do conteúdo do display para a esquerda
  }

  delay(150);         // Aguarda um tempo de 150 ms
  tempo++;            // Incrementa a variável tempo
 
  if (tempo == 17) {      // Verifica se a variável tempo é igual a 17
    tempo = -11;        // Redefine o valor de tempo para -11
    moveToRight = !moveToRight; // Inverte o valor da variável moveToRight
  }
}
