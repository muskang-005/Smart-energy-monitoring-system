#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int sensorPin = A0;
int ledPin = 8;
int buzzerPin = 9;

float voltage = 230.0;

float current;
float power;

float energy = 0;
float peakPower = 0;

float cost = 0;
float rate = 6.0;

unsigned long previousTime = 0;

String status;

void setup()
{
  lcd.begin(16,2);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  previousTime = millis();
}

void loop()
{
  int sensorValue = analogRead(sensorPin);  
  current = sensorValue * (5.0 / 1023.0) * 2.0;

  power = voltage * current;

  if(power > peakPower)
    peakPower = power;

  unsigned long currentTime = millis();

  float hours = (currentTime - previousTime)/3600000.0;

  energy = energy + power * hours;

  previousTime = currentTime;

  float energykWh = energy / 1000.0;

  cost = energykWh * rate;

  if(current < 0.05)
    status = "OFF";
  else if(current < 0.5)
    status = "LOW";
  else
    status = "HIGH";
    
    if(power < 150)
  {
    digitalWrite(ledPin,LOW);
    noTone(buzzerPin);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Load: LOW");
    lcd.setCursor(0,1);
    lcd.print("Energy Saving");
  }
  else if(power >=150 && power < 300)
  {
    digitalWrite(ledPin,LOW);
    noTone(buzzerPin);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Load: NORMAL");
    lcd.setCursor(0,1);
    lcd.print("System Stable");
  }
  else if(power >=300 && power <=450)
  {
    digitalWrite(ledPin,LOW);
    noTone(buzzerPin);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Load: HIGH");
    lcd.setCursor(0,1);
    lcd.print("Reduce Usage");
  }
  else
  {
    digitalWrite(ledPin,HIGH);
    tone(buzzerPin,1000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("OVERLOAD!");
    lcd.setCursor(0,1);
    lcd.print("Turn off loads");
  }

  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Power:");
  lcd.print(power,1);
  lcd.print("W ");
  lcd.print(status);

  lcd.setCursor(0,1);
  lcd.print("Energy:");
  lcd.print(energykWh,3);
  lcd.print("kWh");

  delay(1500);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Peak:");
  lcd.print(peakPower,1);
  lcd.print("W");

  lcd.setCursor(0,1);
  lcd.print("Cost Rs:");
  lcd.print(cost,2);

  delay(1500);

  
}
