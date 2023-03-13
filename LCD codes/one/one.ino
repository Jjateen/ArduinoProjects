//Code 1- Simple text display with time elapsed in seconds

#include <LiquidCrystal.h>
short int rs=12,
          en=11,
          d4=5,
          d5=4,
          d6=3,
          d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup(){
lcd.begin(16,2);
lcd.print("Hello World!"); //print a message on the LCD
}

void loop(){
lcd.setCursor(0,1);  //set the cursor to column 0, line 1
lcd.print(millis()/1000);   //print the number of seconds since reset
lcd.print(" seconds");
}
