#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
int msg[1];
RF24 radio(9,10);//check your pin number on RF24 github check you have the right
//pin nu2mber for the arduino you're using. this pin is diffrent for diffrent arduino models.

const uint64_t pipe = 0xF0F0F0F0D2L;
int mot1 = 5;
int mot2 = 6;
int mot3 = 7;
int mot4 = 8;


byte addresses[][6] = {"0"};

void setup(void)
{
  pinMode(mot1 , OUTPUT);
  pinMode(mot2 , OUTPUT);
  pinMode(mot3 , OUTPUT);
  pinMode(mot4 , OUTPUT);
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  
 
}

void loop(void)
{
  if(radio.available()){
    bool done = false;
    while (!done) {
      done = radio.read(msg, 1);
      Serial.println(msg[0]);
      if (msg[0] == 111) {
      //delay(10);
      forward();
      
      }
      else if(msg[0] == 222){
        back();
        }
      else if(msg[0] == 333 ){
        right();
        }
      else if(msg[0] == 444){
        left();
        }
      else{
        stopcar();
        }
  }}}
  void forward(){
  digitalWrite(mot1 , HIGH);
  digitalWrite(mot2 , LOW);
  digitalWrite(mot3 , HIGH);
  digitalWrite(mot4 , LOW);
  
}
void back(){
  digitalWrite(mot1 , LOW);
  digitalWrite(mot2 , HIGH);
  digitalWrite(mot3 , LOW);
  digitalWrite(mot4 , HIGH);
}
void right(){
  digitalWrite(mot1 , HIGH);
  digitalWrite(mot2 , LOW);
  digitalWrite(mot3 , LOW);
  digitalWrite(mot4 , HIGH);
}
void left(){
  digitalWrite(mot1 , LOW);
  digitalWrite(mot2 , HIGH);
  digitalWrite(mot3 , HIGH);
  digitalWrite(mot4 , LOW);
}
void stopcar(){
  digitalWrite(mot1 , LOW);
  digitalWrite(mot2 , LOW);
  digitalWrite(mot3 , LOW);
  digitalWrite(mot4 , LOW);
}


