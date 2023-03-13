#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, 3);

#define Sensor1 11
#define Sensor2 10
#define Sensor3 9
#define Sensor4 2
#define Sensor5 4
#define Sensor6 5
#define Sensor7 12
#define Sensor8 A5
#define Sensor9 13

float t, t1, t2;
float windSpeed;

bool state = true;
bool count = true;

int S9 = 0;

void setup() {
  Serial.begin(9600);  // start serial for output
  lcd.begin(16, 2);
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor5, INPUT);
  pinMode(Sensor6, INPUT);
  pinMode(Sensor7, INPUT);
  pinMode(Sensor8, INPUT);
  pinMode(Sensor9, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Made by - ");
  lcd.setCursor(0, 1);
  lcd.print("Jjateen Gundesha");
  delay(3000);
  lcd.clear();
}

void loop() {

  if (state == 0)
  {
    if (count == 0)
    {
      readSensor();
      
      if (S9 == 1)
      {
        t2 = millis();
        t = t2 - t1;
        t = t / 1000;
        windSpeed = (2 * 3.1416 * 0.0001 * 3600) / t ;
        lcd.setCursor(0, 0);
        lcd.print("Wind Speed ");
        lcd.setCursor(0, 1);
        lcd.print(windSpeed);
        lcd.setCursor(9, 1);
        lcd.print("Km/hr");
        count = true;
      }
    }

    else {
      readSensor();
    
      if (S9 == 0)
      {
        t1 = millis();
        count = false;
      }
    }
  }
  else
  {
    readSensor();
    if (S9 == 1)
    {
      state = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("Wind Speed ");
    lcd.setCursor(0, 1);
    lcd.print("0 ");
    lcd.setCursor(9, 1);
    lcd.print("Km/hr");
    
    
  }
}

void readSensor()
{
  S9 = digitalRead(Sensor9);
}



