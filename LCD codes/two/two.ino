//Code 2 - Blinking cursor

#include <LiquidCrystal.h>
short int rs=12,
          en=11,
          d4=5,
          d5=4,
          d6=3,
          d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
lcd.begin(16,2); //set up the LCD number of columns and rows
lcd.print("Hello World"); //print a message on the LCD
}

void loop() {
lcd.noBlink();    //Turn off blinking cursor
delay(500);
lcd.blink();      //Turn on blinking cursor
delay(500);
}
