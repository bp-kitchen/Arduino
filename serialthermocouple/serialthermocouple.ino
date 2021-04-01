// this example is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/

// GND <-> GND
// VCC <-> 5V
// CLK <-> D6 
// CS <-> D5
// DO <-> D4

#include "max6675.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

int thermoCLK = 6; //SCLK
int thermoCS = 5; //CS
int thermoDO = 4; //SO,MISO

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);

  lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light

}

void loop() {
  // basic readout test, just print the current temp
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MAX6675 test");
  
  lcd.setCursor(0,1); // go to lcd line #1
  lcd.print(thermocouple.readCelsius());
  lcd.print("C ");
  lcd.print(thermocouple.readFahrenheit());
  lcd.print('F');
  
  Serial.print("C = "); 
  Serial.println(thermocouple.readCelsius());
  Serial.print("F = ");
  Serial.println(thermocouple.readFahrenheit());
 
  // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
  delay(1000);
}
