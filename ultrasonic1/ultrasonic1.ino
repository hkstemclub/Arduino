const byte TrigPin = 13; // 超音波模組的觸發腳
const int EchoPin = 12; // 超音波模組的接收腳
const int dangerThresh = 580;   // 10cm × 58
const byte speed = 100; // 馬達的PWM輸出值
 
long distance;      // 暫存接收訊號的高電位持續時間
 
const byte ENA = 5;   // 馬達A的致能接腳
const byte ENB = 6; // 馬達B的致能接腳
const byte IN1 = 10; // 馬達A的正反轉接腳
const byte IN2 = 9; // 馬達B的正反轉接腳
const byte IN3 = 8; // 馬達A的正反轉接腳
const byte IN4 = 7; // 馬達B的正反轉接腳
 
byte dir = 0;     // 記錄行進狀態，0代表「前進」，1代表「右轉」。
 
void stop() {   // 馬達停止
 analogWrite(ENA, 0); // 馬達A的PWM輸出
 analogWrite(ENB, 0); // 馬達B的PWM輸出
}
 
void forward() {     // 馬達轉向：前進（兩個馬達都正轉）
 analogWrite(ENA, speed);  // 馬達A的PWM輸出
 digitalWrite(IN1, HIGH);  // 請參閱表10-5的設定
 digitalWrite(IN2, LOW);
 analogWrite(ENB, speed);  // 馬達B的PWM輸出
 digitalWrite(IN3, HIGH);  // 請參閱表10-5的設定
 digitalWrite(IN4, LOW);
}
 
void backward() {    // 馬達轉向：後退（兩個馬達都反轉）
 analogWrite(ENA, speed);  // 馬達A的PWM輸出
 digitalWrite(IN1, LOW);   // 請參閱表10-5的設定
 digitalWrite(IN2, HIGH);
 analogWrite(ENB, speed);  // 馬達B的PWM輸出
 digitalWrite(IN3, LOW);   // 請參閱表10-5的設定
 digitalWrite(IN4, HIGH);
}
 
void turnLeft() {    // 馬達轉向：左轉（馬達A反轉、馬達B正轉）
 analogWrite(ENA, speed);  // 馬達A的PWM輸出
 digitalWrite(IN1, LOW);   // 請參閱表10-5的設定
 digitalWrite(IN2, HIGH);
 analogWrite(ENB, speed);  // 馬達B的PWM輸出
 digitalWrite(IN3, HIGH);  // 請參閱表10-5的設定
 digitalWrite(IN4, LOW);
}
 
void turnRight() {     // 馬達轉向：右轉（馬達A正轉、馬達B反轉）
 analogWrite(ENA, speed);  // 馬達A的PWM輸出
 digitalWrite(IN1, LOW);   // 請參閱表10-5的設定
 digitalWrite(IN2, HIGH);
 analogWrite(ENB, speed);  // 馬達B的PWM輸出
 digitalWrite(IN3, HIGH);  // 請參閱表10-5的設定
 digitalWrite(IN4, LOW);
}
 
long ping() { // 超音波感測程式
  digitalWrite(TrigPin, HIGH);  // 觸發腳設定成高電位
  delayMicroseconds(5); // 持續5微秒
  digitalWrite(TrigPin, LOW); // 觸發腳設定成低電位
  
  return pulseIn(EchoPin, HIGH);  // 測量高電位的持續時間（µs）
}
void setup(){
   pinMode(TrigPin, OUTPUT);  // 觸發腳設定成「輸出」
   pinMode(EchoPin, INPUT);   // 接收腳設定成「輸入」
   // 馬達控制板的接腳全都設定成「輸出」
   pinMode(IN1, OUTPUT); 
   pinMode(IN2, OUTPUT);
   pinMode(IN3, OUTPUT); 
   pinMode(IN4, OUTPUT);
}
 
