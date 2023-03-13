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

int S1 = 0;
int S2 = 0;
int S3 = 0;
int S4 = 0;
int S5 = 0;
int S6 = 0;
int S7 = 0;
int S8 = 0;
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
  lcd.print("Made By -");
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
        windSpeed = (2 * 3.1416 * 0.00014922499901 * 3600) / t ;
        lcd.setCursor(3, 0);
        lcd.print("Wind Speed ");
                lcd.setCursor(0, 1);
        lcd.print(windSpeed);
        lcd.setCursor(11,1);
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
    
//   Serialprint();
    if (S9 == 1)
    {
      state = 0;
    }
    lcd.setCursor(3, 0);
    lcd.print("Wind Speed ");
       lcd.setCursor(0, 1);
    lcd.print("0 ");
  lcd.setCursor(11,1);
        lcd.print("Km/hr");
  }
}

void readSensor()
{
  S1 = digitalRead(Sensor1);
  S2 = digitalRead(Sensor2);
  S3 = digitalRead(Sensor3);
  S4 = digitalRead(Sensor4);
  S5 = digitalRead(Sensor5);
  S6 = digitalRead(Sensor6);
  S7 = digitalRead(Sensor7);
  S8 = digitalRead(Sensor8);
  S9 = digitalRead(Sensor9);
}

void winddirect()
{
  if (S7 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("0");
    lcd.write(223);
    lcd.print("N   ");
  }
  else if (S8 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("45");
    lcd.write(223);
    lcd.print("NE ");
  }
  else if (S1 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("90");
    lcd.write(223);
    lcd.print("E  ");
  }

  else if (S2 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("135");
    lcd.write(223);
    lcd.print("SE");
  }
  else if (S3 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("180");
    lcd.write(223);
    lcd.print("S ");
  }
  else if (S4 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("225");
    lcd.write(223);
    lcd.print("SW");
  }
  else if (S5 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("270");
    lcd.write(223);
    lcd.print("W ");
  }
  else if (S6 == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("315");
    lcd.write(223);
    lcd.print("NW");
  }

}

void Serialprint()
{
  Serial.print(S1);
  lcd.setCursor(0, 0);
  lcd.print(S1);
  Serial.print("\t");
  lcd.setCursor(1, 0);
  Serial.print(S2);
  lcd.print(S2);
  Serial.print("\t");
  lcd.setCursor(2, 0);
  Serial.print(S3);
  lcd.print(S3);
  Serial.print("\t");
  Serial.print(S4);
  lcd.print(S4);
  Serial.print("\t");
  Serial.print(S5);
  lcd.print(S5);
  Serial.print("\t");
  Serial.print(S6);
  lcd.print(S6);
  Serial.print("\t");
  Serial.print(S7);
  lcd.print(S7);
  Serial.print("\t");
  Serial.print(S8);
  lcd.print(S8);
  Serial.print("\t");
  Serial.print(S9);
  lcd.print(S9);
  Serial.println("\t");
}
