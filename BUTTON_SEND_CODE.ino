#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
//RF24 library link https://github.com/maniacbug/RF24
//Pin Assingmenet http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
int msg[1];
int button1 = 4;
int button2 = 5;
int button3 = 3-;
int button4 = 2;
RF24 radio(9,10);//check your pin number on RF24 github check you have the right
//pin for the arduino you're using. this pin number is diffrent for diffrent arduino models.

const uint64_t pipe = 0xF0F0F0F0D2L;
int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;


void setup(void)
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  
}

void loop(void)
{
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  button4State = digitalRead(button4);

  
  if (button1State == HIGH)//forward
  {
    msg[0] = 111;
    radio.write(msg, 1);
  }  else if (button2State == HIGH)//back
  {
    msg[0] = 222;
    radio.write(msg, 1);
  }
  else if (button3State == HIGH)//right
  {
    msg[0] = 333;
    radio.write(msg, 1);
  }
  else if (button4State == HIGH)//left
  {
    msg[0] = 444;
    radio.write(msg, 1);
  }
   
  
}
