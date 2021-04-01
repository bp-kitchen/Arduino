// Reference: https://www.instructables.com/How-to-Connect-I2C-Lcd-Display-to-Arduino-Uno/
// GND <-> GDN
// VCC <-> 5V
// SDA <-> A4
// SCL <-> A5

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//uint8_t degree[8]  = {140,146,146,140,128,128,128,128};

void setup() 
{
  lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light
  //lcd.backlight();// To Power OFF the back light

  //lcd.createChar(0, degree); fail to display

}

void loop() 
{
  //Write your code
  lcd.clear();//Clean the screen
  lcd.setCursor(0,0); //Defining positon to write from first row,first column .
  lcd.print("Cha-In "); //You can write 16 Characters per line .
  delay(1000);//Delay used to give a dynamic effect
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print("Dine In, Takeout");
  delay(4000); 
  
  lcd.clear();//Clean the screen
  lcd.setCursor(0,0); 
  lcd.print("Patronize");
  lcd.setCursor(0,1);
  lcd.print("Cha-In");
  delay(4000); 
}
