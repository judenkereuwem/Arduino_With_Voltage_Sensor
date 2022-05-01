#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int voltgeSensor = A0;

float vOUT = 0.0;
float vIN = 0.0;

float R1 = 30000.0;
float R2 = 7500.0;

int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  lcd.init();                      
  lcd.backlight();
  lcd.home();
}

void loop() {
  value = analogRead(A0);
  
  vOUT = (value * 5.0)/1024.0;
  vIN = vOUT / (R2/(R1+R2));

  //display on serial monitor
  Serial.print("Voltage = ");
  Serial.print(vIN, 2);
  Serial.println(" volts DC");

  //display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(vIN,2);
  lcd.print(" v");
  
  
  delay(1000);
}
