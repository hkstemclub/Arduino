/* Testing MQ GAS sensor with serial monitor
   Suitable for detecting of LPG, i-butane, propane, methane ,alcohol, Hydrogen or smoke
   More info: http://www.ardumotive.com/how-to-use-mq2-gas-sensor-en.html
   Dev: Michalis Vasilakis // Date: 11/6/2015 // www.ardumotive.com                     */
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 設定 LCD I2C 位址


const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin


void setup()
{
  Serial.begin(9600); //Initialize serial port - 9600 bps

  //initial display
  lcd.begin(16, 2); // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
  for(int i = 0; i < 1; i++) {
    lcd.backlight(); // 開啟背光
    delay(250);
    lcd.noBacklight(); // 關閉背光
    delay(250);
    }
  lcd.backlight();

  // 輸出初始化文字
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("HK STEM CLUB");
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("hkstem.club");
  delay(1000);

}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(analogRead(gasPin));
  
  Serial.println(analogRead(gasPin));
  lcd.setCursor(0, 0);
  delay(500); // Print value every 1 sec.
}

