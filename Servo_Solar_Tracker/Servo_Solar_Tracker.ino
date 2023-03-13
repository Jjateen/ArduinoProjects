#include <Servo.h>
Servo sg90;
short int pos=90;
const short int ldr1=A0,ldr2=A1,tol=20; 
void setup() {
  // put your setup code here, to run once:
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  sg90.attach(9);
  sg90.write(pos);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int r1 = analogRead(ldr1);
  int r2 = analogRead(ldr2);
  if(abs(r1-r2)>=tol || abs(r2-r1)>=tol){
    if(r1>r2)
    pos++;
    if(r1<r2)
    pos--;
  }
  sg90.write(pos);
  delay(100);
}
