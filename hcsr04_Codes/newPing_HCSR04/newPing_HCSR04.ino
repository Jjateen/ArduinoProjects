#include <NewPing.h>

//(Library: New Ping by Tim Eckel v 1.9.6)

int triggerpin=10;
int echopin= 9;

//Maximum distance we want to ping for (in centimetera)
#define MAX_DISTANCE 400

//NewPing setup of pins and maximum distance
NewPing sonar(triggerpin, echopin, MAX_DISTANCE);

void setup()
{
  Serial.begin(9600);
}
void loop ()
{
  Serial.print ("Distance= ");
  Serial.print (sonar.ping_cm());
  Serial.println ("cm ");
  delay(1000);
}
