#include <LiquidCrystal.h>
short int rs=12,
          en=11,
          d4=5,
          d5=4,
          d6=3,
          d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int numRows = 2;
int numCols = 16;

void setup()
{
  lcd.begin(numCols, numRows);  
  lcd.print("Lab EvaL");
  lcd.setCursor(0,1);
  lcd.print("By Jj & Anuj");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
}
void loop()
{
  marquee("This message is too long to fit ! so we scroll it");
  delay(1000);
  lcd.clear();  
}
void marquee(char *text)
{
  int length = strlen(text);
  if(length < numCols)
    lcd.print(text);
  else
  {
    int pos;
    for(pos = 0; pos < numCols; pos++)
      lcd.print(text[pos]);
    delay(1000);
    while(pos < length)
    {
      lcd.scrollDisplayLeft();
      lcd.print(text[pos]);
      pos = pos + 1;
      delay(300);  
    }  
  }
}
