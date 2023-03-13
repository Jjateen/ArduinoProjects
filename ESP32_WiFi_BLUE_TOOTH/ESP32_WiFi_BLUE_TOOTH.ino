/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


String res = "";

BluetoothSerial SerialBT;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9b2298995f674f098230de710a51e8db";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JJG";
char pass[] = "12345678";

void setup()
{
  // Debug console 
  //extend these to D8 if you are using a 8 pin relay 
 
 // Make it low if you want everything to go off 
 
    Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27,OUTPUT);
   Blynk.begin(auth, ssid, pass);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(27, LOW);
 
}

void loop()
{
  Blynk.run();
   while (!SerialBT.available()); // Wait Until anything is coming from bluetooth client
  
  while (SerialBT.available()) // Read until the bluetooth client is sending.
  {
    char add = SerialBT.read();
    res = res + add;
    delay(1);
  }

 

  // Assigning Actions on particular conditions
  if (res == "T")
  {
    Serial.println("Connection Established!!!");
  }
  if (res == "1")
  {
    Serial.println("Turning ON 1st led");
    digitalWrite(12, HIGH);
  }
  if (res == "A")
  {
    Serial.println("Turning OFF 1st led");
    digitalWrite(12,LOW);
  }
  if (res == "2")
  {
    Serial.println("Turning ON 2nd led");
    digitalWrite(14, HIGH);
  }
  if (res == "B")
  {
    Serial.println("Turning OFF 2nd led");
    digitalWrite(14,LOW);
  }
  if (res == "3")
  {
    Serial.println("Turning ON 3rd led");
    digitalWrite(27,HIGH);
  }
  if (res == "C")
  {
    Serial.println("Turning OFF 3rd led");
    digitalWrite(27, LOW);
  }
  if (res == "4")
  {
    Serial.println("Turning ON 4th led");
    digitalWrite(13, HIGH);
  }
  if (res == "D")
  {
    Serial.println("Turning OFF 4th led");
    digitalWrite(13,LOW);
  }
  if (res == "9")
  {
    Serial.println("Turning ON all led");
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(27, HIGH);
    
  }
  if (res == "I")
  {
    Serial.println("Turning OFF all led");
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(14, LOW);
    digitalWrite(27, LOW);
    
  }


  res = ""; // clearing the string.

}

