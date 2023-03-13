#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
float value=0;
float rev=0;
float wind;
int oldtime=0;
int time;


void isr() //interrupt service routine
{
rev++;
}

void setup()
{
lcd.begin(16,2);                //initialize LCD
attachInterrupt(0,isr,RISING);  //attaching the interrupt
lcd.setCursor(0,0);
lcd.print(" Wind Speed ");
 lcd.setCursor(7,1);
//lcd.print(   wind);
lcd.print("Km/hr");
}

void loop()
{
delay(500);
detachInterrupt(0);           //detaches the interrupt
time=millis()-oldtime;        //finds the time ,
wind=(rev/time)*60000*0.0000157;         //calculates wind speed
   
oldtime=millis();             //saves the current time
rev=0;

//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print(" Wind Speed ");
 lcd.setCursor(0,1);
lcd.print(   wind);
//lcd.print("        Km/hr");

lcd.print("   ");

attachInterrupt(0,isr,RISING);

}

