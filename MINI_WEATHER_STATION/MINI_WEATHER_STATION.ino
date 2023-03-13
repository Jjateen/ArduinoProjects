  #include<LiquidCrystal.h>
  #include<DHT.h>
  #define DHTTYPE DHT11
  int ldrpin =A0;
  int ldrval=0;
  char *light[]={"Day","Night"};
  int dhtpin=8 ;
  float temp;
  float humi;
  
  DHT dht(dhtpin,DHTTYPE);
  int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
  LiquidCrystal lcd(rs, en,d4,d5, d6,d7);
  
  
  void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16,2);
  dht.begin();
  lcd.print("   Welcome To");
  lcd.setCursor(0,1);
  lcd.print("Weather *Station");
  delay(3500);
  lcd.clear();
  }
  
  void loop() {
   ldrval= analogRead(ldrpin);
  temp=dht.readTemperature();   //to read the temperature from DHT AND TOO STORE IN VARIABLE
  humi=dht.readHumidity();    // to read the humidity dht and to store in the variable
  lcd.clear();       //Clear the lcd
  lcd.setCursor(0,0);   //set the 1 point 0
  lcd.print("  Temp=");
  lcd.print(temp);     //to print temperature value read from the DHT sensor
  lcd.print("\337C");  //to print degree C
  lcd.setCursor(0,1);    //set line 2 pont 0
  if(ldrval>200){
    lcd.print(light[0]);   //printing day
    digitalWrite(LED_BUILTIN, LOW); 
  }
  else{
    lcd.print(light[1]);  //printing night
    digitalWrite(LED_BUILTIN, HIGH); // LIGHT ON
  }
  lcd.print(" | Hum=");    //printing Humidity
  lcd.print(humi);  //to print humidity value read from DHT sensor
  
  lcd.print("%");
  delay(500);  // delay between iterations
  }
