#include <Wire.h> // Arduino IDE 內建
// LCD I2C Library，從這裡可以下載：
// bitbucket.org/fmalpartida/new-liquidcrystal/downloads
#include <LiquidCrystal_I2C.h>

// Set the pins on the I2C chip used for LCD connections:
// addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 設定 LCD I2C 位址
float sensorValue0 = 0.0;
float sensorValue1 = 0.0;
String title = "Output Voltage";

//#define MIN_VALUE 0;    //INPUT RANGE 0-1023
#define MAX_VALUE 1023.0

//#define DISPLAY_MIN 0;  //DISPLAY RANGE 0V-5V
#define DISPLAY_MAX 5.0



void setup() {
Serial.begin(9600); // 用於手動輸入文字
lcd.begin(16, 2); // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光

// 閃爍一次
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
delay(500);

}

void loop() {
  lcd.clear();
  int analog_value = analogRead(A0);
  sensorValue0 = analog_value / MAX_VALUE; // read the input on analog pin 0:
  
  // print out the sensor:
  lcd.setCursor(0, 0);
  lcd.print(sensorValue0 * DISPLAY_MAX);
  Serial.println(analog_value / 1023.0);

  lcd.setCursor(0,1);
  //lcd.print(sensorValue1);
  lcd.print(title);

  sensorValue1 = sensorValue0;
  
  delay(300);        // delay in between reads for stability


}
