#include "BluetoothSerial.h"
#include "ESP32Servo.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h"
#include "DHT.h"

Servo servo;

#if!defined(CONFIG_BT_ENABLED)||!defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

#define DHTPIN 32  // Pino digital ao qual o DHT11 está conectado
#define DHTTYPE DHT11  // Tipo de sensor DHT (existem vários tipos)
#define SOIL_MOISTURE_PIN 33  // Pino analógico ao qual o sensor de umidade do solo está conectado
int servoPin = 19; // Atribuimos à "servoPin" o pino no qual o servo motor está ligado

DHT dht(DHTPIN, DHTTYPE);

BluetoothSerial SerialBT;
char valorRecebido;
LiquidCrystal_I2C lcd(0x27,16,2); // Inicializando o LCD Display

void setup(){
  Serial.begin(115200);
  SerialBT.begin("micro2");
  Serial.println("Dispositivo");
  lcd.begin(16, 2);
  pinMode(18,OUTPUT); // rele
  dht.begin(); //inicializa o sensor de temperatura DHT11
  servo.attach(servoPin); //Definindo o servo
  servo.write(0); //Ângulo o qual o servo motor se inicia

}

void loop(){

//SENSORES

  //Sensor do solo 
  int valorSensorSolo = analogRead(SOIL_MOISTURE_PIN);
  // Mapeia o valor para um intervalo de 0 a 100 (umidade percentual)
  int umidadeSolo = map(valorSensorSolo, 0, 1023, 0, 100);

  //leitura do DHT11
  float temperatura = dht.readTemperature(); //Lê a temperatura do ambiente

// Exibe a temperatura do DHT11 e a umidade do solo na primeira linha do LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C | Solo: ");
  lcd.print(umidadeSolo);
  lcd.print(" %");

  // Exibe as informações no Monitor Serial para depuração
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.print("Umidade do Solo: ");
  Serial.print(umidadeSolo);
  Serial.println(" %");

  //fim do codigo de sensores no LCD

  //fim da leitura da umidade do solo

  //codigo para ler a umidade do solo e ligar o servo motor 
  if (umidadeSolo <= 25) {
    lcd.setCursor(0, 2);
    lcd.print("  Solo seco   ");
    Serial.println("Precisa irrigar");
    servo.write(90); // Gira o servo motor para abrir a bomba de água
    
   }
  if (umidadeSolo > 25) {
    lcd.setCursor(0, 2);
    lcd.print("  Solo esta umido   ");
    Serial.println("OK");
    servo.write(0); // Gira o servo motor para fechar a bomba de água

   }
   //fim do codigo para ler a umidade do solo e ligar o servo motor 


//FIM DOS SENSORES


  //codigo de ativacao da lampada rele
  valorRecebido = (char)SerialBT.read();
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available()){
    if(valorRecebido == '1'){
      SerialBT.println("relé ligada");
      digitalWrite(18,HIGH);
    }
    if(valorRecebido == '2'){
      SerialBT.println("relé desligada");
      digitalWrite(18,LOW);
    }
  }
  delay(50);
//fim do codigo ativacao lampada rele

}