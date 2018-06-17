#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 設定 LCD I2C 位址


const int analogPin = A0; //sensor output pin to Arduino analog A0 pin
const bool digitalPin = 1; //sensor output pin to Arduino analog D0 pin
float maxValue = 100.0; // To display percentage maxValue = 100, use other value such as 5.0 to represent 5V


void setup()
{
  Serial.begin(9600); //Initialize serial port - 9600 bps
  pinMode (analogPin, INPUT);
  pinMode (digitalPin, INPUT);  

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

int value_A0;
bool value_D0;

void loop()
{
  value_A0=analogRead(analogPin);
  value_D0=digitalRead(digitalPin);

  float percent = value_A0 * (maxValue/1023.0);  // use 100.0, 1023.0 instead of 100 / 1023 to prevent Arduino IDE treat as integer
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A0:");
  lcd.print(value_A0);
  lcd.print(", ");
  lcd.print(percent);
  Serial.print(percent);
  Serial.println(value_A0);

  lcd.setCursor(0, 1);
  lcd.print("D0:");
  lcd.print(value_D0);
  Serial.println(value_D0);

  
  delay(500); // Print value interval.
} 

