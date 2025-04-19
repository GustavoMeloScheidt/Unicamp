#include "ESP32Servo.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <WiFi.h> //Inclui a biblioteca

const char* ssid = "estudinhos"; //Define o nome do ponto de acesso
const char* pass = "12345678"; //Define a senha
 
WiFiServer sv(80); //Cria um servidor na porta 80

Servo servo;



#define DHTPIN 32  // Pino digital ao qual o DHT11 está conectado
#define DHTTYPE DHT11  // Tipo de sensor DHT (existem vários tipos)
#define SOIL_MOISTURE_PIN 33  // Pino analógico ao qual o sensor de umidade do solo está conectado
int servoPin = 19; // Atribuimos à "servoPin" o pino no qual o servo motor está ligado

DHT dht(DHTPIN, DHTTYPE);


LiquidCrystal_I2C lcd(0x27, 16, 2); // Inicializando o LCD Display

void setup(){
  Serial.begin(115200);
  lcd.begin();
  pinMode(18,OUTPUT); // rele
  dht.begin(); //inicializa o sensor de temperatura DHT11
  servo.attach(servoPin); //Definindo o servo
  servo.write(0); //Ângulo o qual o servo motor se inicia

 //wifi 
  Serial.println("\n"); //Pula uma linha
  WiFi.softAP(ssid, pass); //Inicia o ponto de acesso
  Serial.print("Se conectando a: "); //Imprime mensagem sobre o nome do ponto de acesso
  Serial.println(ssid);

  IPAddress ip = WiFi.softAPIP(); //Endereço de IP
  
  Serial.print("Endereço de IP: "); //Imprime o endereço de IP
  Serial.println(ip);

  sv.begin(); //Inicia o servidor 
  Serial.println("Servidor online"); //Imprime a mensagem de início
}

void loop(){

//SENSORES

  //Sensor do solo 

  int valorSensorSolo = analogRead(SOIL_MOISTURE_PIN);
  // Mapeia o valor para um intervalo de 0 a 100 (umidade percentual)
  int umidadeSolo = (100 - valorSensorSolo/40.9);

  //leitura do DHT11
  float temperatura = dht.readTemperature(); //Lê a temperatura do ambiente

// Exibe a temperatura do DHT11 e a umidade do solo na primeira linha do LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.setCursor(8, 0);
  lcd.print("S:");
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
    lcd.setCursor(0, 1);
    lcd.print("Solo seco");
    Serial.println("Precisa irrigar");
    servo.write(90); // Gira o servo motor para abrir a bomba de água

   } else {
    lcd.setCursor(0, 1);
    lcd.print("Solo esta umido");
    Serial.println("OK");
    servo.write(0); // Gira o servo motor para fechar a bomba de água

   }
   //fim do codigo para ler a umidade do solo e ligar o servo motor 


//FIM DOS SENSORES


  //codigo de ativacao da lampada rele wifi 
  WiFiClient client = sv.available(); //Cria o objeto cliente

  if (client) { //Se este objeto estiver disponível
    String line = ""; //Variável para armazenar os dados recebidos

    while (client.connected()) { //Enquanto estiver conectado
      if (client.available()) { //Se estiver disponível
        char c = client.read(); //Lê os caracteres recebidos
        if (c == '\n') { //Se houver uma quebra de linha
          if (line.length() == 0) { //Se a nova linha tiver 0 de tamanho
            client.println("HTTP/1.1 200 OK"); //Envio padrão de início de comunicação
            client.println("Content-type:text/html");
            client.println();

            client.print("Ligue a lampada clicando <a href=\"/ligar\">aqui</a><br>"); //Linha para ligar o led
            client.print("Desligue a lampada clicando <a href=\"/desligar\">aqui</a><br>"); //Linha para desligar o led

            client.println();
            break;
          } else {   
            line = "";
          }
        } else if (c != '\r') { 
          line += c; //Adiciona o caractere recebido à linha de leitura
        }

        if (line.endsWith("GET /ligar")) { //Se a linha terminar com "/ligar", liga o led
          digitalWrite(18,HIGH);    
          Serial.println("relé ligada");           
        }
        if (line.endsWith("GET /desligar")) { //Se a linha terminar com "/desligar", desliga o led
          digitalWrite(18,LOW);  
          Serial.println("relé desligada");             
        }
      }
    }

    client.stop(); //Para o cliente
  }

//fim do codigo ativacao lampada rele

}