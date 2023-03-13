


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN 9
#define CSN_PIN 10


const int BackMotorF = 3;
const int BackMotorB = 4;
const int ForwardMotorR = 5;
const int ForwardMotorL = 6;






const uint64_t pipe = 0xE8E8F0F0E1LL;


RF24 radio(CE_PIN,CSN_PIN);


char data[20];
void setup() 
{
  pinMode(BackMotorF,OUTPUT);
  pinMode(BackMotorB,OUTPUT);
  pinMode(ForwardMotorR,OUTPUT);
  pinMode(ForwardMotorL,OUTPUT);
   Serial.begin(9600);


   
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() 
{
  String msg="";
  if ( radio.available() )
  {
    radio.read( data, sizeof(data) );
    Serial.println(data);
    msg=data;


    if(msg=="up")
    {
      digitalWrite(BackMotorF,HIGH);
      digitalWrite(BackMotorB,LOW);
      digitalWrite(ForwardMotorR,LOW);
      digitalWrite(ForwardMotorL,LOW);
    }
    else if(msg=="down")
    {
      digitalWrite(BackMotorF,LOW);
      digitalWrite(BackMotorB,HIGH);
      digitalWrite(ForwardMotorR,LOW);
      digitalWrite(ForwardMotorL,LOW);
    }
    else if(msg=="left")
    {
      digitalWrite(BackMotorF,HIGH);
      digitalWrite(BackMotorB,LOW);
      digitalWrite(ForwardMotorR,LOW);
      digitalWrite(ForwardMotorL,HIGH);
    }
    else if(msg=="right")
    {
      digitalWrite(BackMotorF,HIGH);
      digitalWrite(BackMotorB,LOW);
      digitalWrite(ForwardMotorR,HIGH);
      digitalWrite(ForwardMotorL,LOW);
    }
    else if(msg=="start")
    {
      digitalWrite(BackMotorF,LOW);
      digitalWrite(BackMotorB,LOW);
      digitalWrite(ForwardMotorR,LOW);
      digitalWrite(ForwardMotorL,LOW);
    }
    
  }


}

