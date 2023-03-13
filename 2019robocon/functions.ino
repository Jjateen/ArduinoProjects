void up (int pin1,int pin2){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
}
void down (int pin1,int pin2){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
}
void left (int pin1,int pin2){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
}
void right (int pin1,int pin2){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
}
void stp(){
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
}      
