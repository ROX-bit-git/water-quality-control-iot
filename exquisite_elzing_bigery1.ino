#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}
void loop()
{
  //water temperature
  pinMode(14, INPUT);
  int temp;
  temp=analogRead(14);
  float voltage=temp*5;
  voltage=voltage/24;
  float temperatureC=voltage-0.5;
  temperatureC=temperatureC+100;
  delay(500);
  //temperature end
  
  //turbidity of water
  pinMode(15, INPUT);
  int turbidity;
  int turl;
  turbidity=analogRead(A1);
  turl= map(turbidity,0,471,0,5);
  delay(500);
  //turbidity end
  
  //TDS sensor as potentiometer
  pinMode(16,INPUT);
  int TDS;
  int TDS1;
  TDS=analogRead(2);
  TDS1=map(TDS,0,1023,0,2000);
  delay(500);
  //TDS sensor end
  
  //PH sensor replaced by potentiometer
  pinMode(17,INPUT);
  int PH;
  int PH1;
  PH=analogRead(3);
  PH1=map(PH,0,1023,0,14);
  delay(500);
  //PH sensor end
  
  Serial.print("temperature:"); 
  Serial.println(temperatureC);
  Serial.print("TURBIDITY:"); 
  Serial.println(turl);
  Serial.print("TDS:");
  Serial.println(TDS1);
  Serial.print("PH:");
  Serial.println(PH1);
  //LCD for drinking use
  pinMode(6,INPUT);
  int dis;
  dis=digitalRead(6);
  if (dis==LOW)
  {
    if (turl>=4 && TDS<600 && (PH1>=6.5 && PH1<7))
    {
      
      
      lcd.setCursor(1,0);
      lcd.print("Domestic use");
      Serial.println("Domestic Use");
    }
      else
      {       
      
      lcd.setCursor(1,0);
      lcd.print("Dangerous");
      Serial.println("Dangerous");
        delay(1000);
      }
    
  }
      dis=digitalRead(6);
      if (dis==HIGH)
      {
        //LCD display for temperature
       lcd.setCursor(1,0); lcd.print("TEMP");
       lcd.setCursor(7,0); lcd.print(temperatureC);
        delay(1000);
        lcd.clear();
        //LCD display for Turbidity
   lcd.setCursor(1,0); lcd.print("TURB");
    lcd.setCursor(7,0); lcd.print(turl);
        delay(500);
        lcd.clear();
         //LCD display for pH
         lcd.setCursor(1,0); lcd.print("PH");
         lcd.setCursor(7,0); lcd.print(PH1);
         delay(500);
         lcd.clear();
        
        //LCD display for TDS
    lcd.setCursor(1,0); lcd.print("TDS");
    lcd.setCursor(7,0); lcd.print(TDS1);
       
      }
}
   
  
  
  
  
  