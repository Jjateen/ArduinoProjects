#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "ecfd675129e343eea8e25e220436b743"; //Auth code sent via Email
char ssid[] = "JJG"; //Wifi name
char pass[] = "12345678";  //Wifi Password

void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
 pinMode(D2,OUTPUT);
 Serial.println("elsctric pole is leaking");
    Blynk.notify("Your Electric Pole Is Leaking , Repair imidieateley to avoid shock");
      digitalWrite(D2,HIGH);
}
void loop()
{
  Blynk.run();
  timer.run();
}
