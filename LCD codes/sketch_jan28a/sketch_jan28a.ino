/*
//Code 1- Simple text display with time elapsed in seconds

#include <LiquidCrystal.h>
int rs =12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
lcd.begin(16,2); //set up the LCD number of columns and rows
lcd.print("Hello, world!"); //print a message on the LCD
}

void loop() {
lcd.setCursor(0,1);  //set the cursor to column o, line 1
lcd.print(millis()/1000);      //print the number of seconds since reset
}
*/



/*
//Code 2 - Blinking cursor


#include <LiquidCrystal.h>
int rs =12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
lcd.begin(16,2); //set up the LCD number of columns and rows
lcd.print("Hello, world!"); //print a message on the LCD
}

void loop() {
lcd.noBlink();    //Turn off blinking cursor
delay(500);
lcd.blink();      //Turn on blinking cursor
delay(500);
}
*/



/*
//Code 3- Blinking cursor (underscore)

#include <LiquidCrystal.h>
int rs =12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
lcd.begin(16,2); //set up the LCD number of columns and rows
lcd.print("Hello, world!"); //print a message on the LCD
}

void loop() {
lcd.noCursor();    //Turn off blinking cursor
delay(500);
lcd.cursor();      //Turn on blinking cursor
delay(500);
}
*/



/*
//Code 4- Parse the print data from serial monitor

#include <LiquidCrystal.h>
int rs =12,en=11,d4=5,d5=4,d6=3,d7=2;
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
*/
