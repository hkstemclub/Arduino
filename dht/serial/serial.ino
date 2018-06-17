#include <dht.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 設定 LCD I2C 位址
dht DHT;



// if you require to change the pin number, Edit the pin with your arduino pin.
#define DHT11_PIN 3

void setup() {

  //Initial Serial Monitor
  Serial.begin(9600);
  Serial.println("welcome to TechPonder Humidity and temperature Detector"); }

  //Initial I2C LCD 1602
  lcd.begin(16, 2); // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("HK STEM CLUB");
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("hkstem.club");
  for(int i = 0; i < 1; i++) {
    lcd.backlight(); // 開啟背光
    delay(250);
    lcd.noBacklight(); // 關閉背光
    delay(250);
    }
  lcd.backlight();
  }

void loop() { // READ DATA

int chk = DHT.read11(DHT11_PIN);

//Display Serial Monitor
Serial.println(" Humidity " );
Serial.println(DHT.humidity, 1);
Serial.println(" Temparature ");
Serial.println(DHT.temperature, 1);

//Display LCD
  lcd.clear();
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print(" Humidity ");
  lcd.print(DHT.humidity, 1);
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print(" Temparature ");
  lcd.print(DHT.temperature, 1);

delay(2000);

}
