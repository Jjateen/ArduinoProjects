#include<SoftwareSerial.h>
SoftwareSerial BT(10,11); // Connect Tx to pin 10 and Rx to pin 11 of HC05

#define TSpin 12
char c;
int s;// setting up touch sensor
int fl=0; //setting up a flag


void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);


  pinMode(TSpin,INPUT);

}
void loop() 
{
  if (BT.available())
    {
      fl=1;
      c=BT.read();
      Serial.println(c);
      delay(500);
    }
  s=digitalRead(TSpin);
  Serial.println(s);
  if (fl==1){
    if (s==1){
      if(c=='A'){
        Serial.println("A pressed");
        up(2,3);
        left(5,4);
        delay(2500);
        stp();delay(5000);
        down(2,3);
        right(5,4);
        delay(2500);
        stp();
        }
    else if(c=='B'){
      Serial.println("B pressed");
      up(6,7);
      right(8,9);
      delay(2500);  
      stp();
      delay(5000);
      down(6,7);
      left(8,9);
      delay(2500);
      stp();
      }
    else if(c=='C'){
      Serial.println("C pressed");
      up(6,7);
      up(2,3);
      delay(2500);
      stp();
      delay(5000);
      down(6,7);
      down(2,3);
      delay(2500);
      stp();
      }
    else{
      Serial.println("D pressed");
      up(2,3);
      up(6,7);
      left(5,5);
      right(8,9);
      delay(2500);
      stp();                                                                
      delay(5000);
      down(2,3);
      down(6,7);
      right(5,5);
      left(8,9);
      delay(2500);
      stp();  
      }
     fl=0;
    }  
  }  
}