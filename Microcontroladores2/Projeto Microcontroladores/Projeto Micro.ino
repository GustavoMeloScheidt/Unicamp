#include "BluetoothSerial.h"
#include "ESP32Servo.h"
#if!defined(CONFIG_BT_ENABLED)||!defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

BluetoothSerial SerialBT;
char valorRecebido;
void setup(){
  Serial.begin(115200);
  SerialBT.begin("cvu");
  Serial.println("Dispositivo");
  pinMode(relay,OUTPUT); // rel? 
}

void loop(){
//cedigo de ativacao da lampada rele
  valorRecebido = (char)SerialBT.read();
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available()){
    if(valorRecebido == 'Come?ar'){
      SerialBT.println("led aceso");
      digitalWrite(27,HIGH);
    }
    if(valorRecebido == 'Parar'){
      SerialBT.println("led apagado");
      digitalWrite(27,LOW);
    }
  }
  delay(50);
//fim do codigo ativacao lampada rele
}