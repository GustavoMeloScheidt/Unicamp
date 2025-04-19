#include "BluetoothSerial.h"
#include "ESP32Servo.h"         // Inclui a biblioteca para o controle de servos na ESP32
#include "LiquidCrystal_I2C.h"  // Inclui a biblioteca para o controle do display LCD com I2C
#include "Wire.h"               // Inclui a biblioteca para a comunicação I2C
#include "DHT.h"                // Inclui a biblioteca para o sensor de temperatura e umidade DHT

#if!defined(CONFIG_BT_ENABLED)||!defined(CONFIG_BLUEDROID_ENABLED)
// Verifica se CONFIG_BT_ENABLED e CONFIG_BLUEDROID_ENABLED estão definidos
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif
//Se algum deles não estiver definido, o código produzirá um erro de compilação 
//com a mensagem "Bluetooth is not enabled!" 
// e sugere a execução de 'make menuconfig' para habilitá-lo.

#define DHTPIN 32  // Define o pino digital ao qual o DHT11 está conectado
#define DHTTYPE DHT11  // Define o tipo de sensor DHT
#define SOIL_MOISTURE_PIN 33  // Define o pino analógico onde o sensor de umidade do solo está conectado

Servo servo; // Cria um objeto para controlar o servo motor
DHT dht(DHTPIN, DHTTYPE); // Cria um objeto para o sensor DHT
BluetoothSerial SerialBT; // Cria uma instância da classe BluetoothSerial

int servoPin = 19; // Atribui a "servoPin" o pino no qual o servo motor está ligado
char valorRecebido;  //Declaração da variavel que recebe a mensagem via bluetooth
LiquidCrystal_I2C lcd(0x27,16,2); // Inicializa o LCD com endereço I2C 0x27, 16 colunas e 2 linhas

void setup(){
  Serial.begin(115200); // Inicializa a comunicação serial 
  SerialBT.begin("micro2"); // Inicializa a comunicação Bluetooth com o dispositivo micro2
  Serial.println("Dispositivo"); // Imprime "Dispositivo" na porta serial
  lcd.begin(); // Inicializa o LCD  
  pinMode(18,OUTPUT); // Configura o pino 18 como saída para a relé
  dht.begin(); // Inicializa o sensor de temperatura DHT11          
  servo.attach(servoPin); // Conecta o servo ao pino definido
  servo.write(0); // Define o ângulo inicial do servo motor

}

void loop(){

//SENSORES
  // Faz a leitura analógica do sensor do solo 
  int valorSensorSolo = analogRead(SOIL_MOISTURE_PIN);
  // Mapeia o valor para um intervalo de 0 a 100 (umidade percentual)
  int umidadeSolo = (100 - valorSensorSolo/40.9);
  // Fim da leitura da umidade do solo
  // Faz a leitura do sensor DHT11
  float temperatura = dht.readTemperature(); //Lê a temperatura do ambiente
// Exibe a temperatura do DHT11 e a umidade do solo na primeira linha do LCD
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.setCursor(8, 0);
  lcd.print("S: ");
  lcd.print(umidadeSolo);
  lcd.print(" %");
  // Exibe as informações no Monitor Serial 
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.print("Umidade do Solo: ");
  Serial.print(umidadeSolo);
  Serial.println(" %");
// Fim do codigo de sensores no LCD

// Código para ler a umidade do solo e ligar o servo motor 
  if (umidadeSolo <= 25) {
    lcd.setCursor(0, 1); // Configura o cursor do LCD
    lcd.print("Solo seco"); // Exibe a mensagem "Solo seco" no LCD
    Serial.println("Precisa irrigar"); // Imprime "Precisa irrigar" no monitor serial 
    servo.write(90); // Gira o servo motor para abrir a bomba de água    
   }
  if (umidadeSolo > 25) {
    lcd.setCursor(0, 1); // Configura o cursor do LCD
    lcd.print("Solo esta umido"); // Exibe a mensagem "Solo umido" no LCD
    Serial.println("OK"); // Imprime "OK" no monitor serial 
    servo.write(0); // Gira o servo motor para fechar a bomba de água
   }
   //fim do codigo para ler a umidade do solo e ligar o servo motor 

//FIM DOS SENSORES

  // Código para ativacao da lampada pela rele
  valorRecebido = (char)SerialBT.read(); // Lê o caractere da comunicação Bluetooth e armazena em valorRecebido
  if(Serial.available()){ // Verifica se há dados disponíveis na porta serial
    SerialBT.write(Serial.read()); // Lê e escreve da porta serial para a comunicação Bluetooth
  }
  if(SerialBT.available()){ // Verifica se há dados disponíveis na comunicação Bluetooth
    if(valorRecebido == '1'){ // Verifica se o valorRecebido é igual a '1'
      SerialBT.println("relé ligada"); // Imprime que a relé foi ativada no monitor serial 
      digitalWrite(18,HIGH); // Liga a lâmpada pela relé
    }
    if(valorRecebido == '2'){ // Verifica se o valorRecebido é igual a '2'
      SerialBT.println("relé desligada"); // Imprime que a relé foi desligada no monitor serial
      digitalWrite(18,LOW); // Desliga a lâmpada pela relé
    }
  }
  delay(50); // Delay de 50 milissegundos 
//fim do codigo ativacao lampada rele
}