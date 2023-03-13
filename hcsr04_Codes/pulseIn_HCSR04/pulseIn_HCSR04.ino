int echoPin=9;
int triggerPin =10;

//defines varables
long timetofly;
int distance;

void setup()
{
  pinMode(triggerPin,OUTPUT); //Sets trigger to output
  pinMode(echoPin,INPUT); //Sets echo to input
  Serial.begin(9600); //Starts the serial communication 
}

void loop ()
{
  //Clears the trigger pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin on High state for 10 ms
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Reads the echoPin, returns the travel time in ms
  timetofly = pulseIn(echoPin, HIGH);
  //Calculating the distance (time to fly calculation)
  distance = timetofly*0.034/2;
  //Prints the distance on the serial monitor in cm
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm ");
  delay(500);
}
