//Code 4- Parse the print data from serial monitor

#include <LiquidCrystal.h>
int rs=12,
    en=11,
    d4=5,
    d5=4,
    d6=3,
    d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
lcd.begin(16,2); //set up the LCD number of columns and rows
Serial.begin(9600);  //Initialize the serial communication
}

void loop() {
//if the character arrives on serial port
if(Serial.available()){
  delay(100);   //Wait for complete mesaage to arrive
  lcd.clear();    // Clear the display
  //Read the characters and print on LCD
  while(Serial.available()>0){
    lcd.write(Serial.read());  //display each character to the LCD
  }
}
}
