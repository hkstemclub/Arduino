  //defines pin numbers
  
  #include <Servo.h>

  Servo myservo;// 建立Servo物件，控制伺服馬達
  const byte TrigPin = 12; // 超音波模組的觸發腳
  const int EchoPin = 13; // 超音波模組的接收腳
  const int dangerdistance = 20; //設定小車檢測的危險距離 
  const int danger=1;
  long distance1;  // 暫存感應器接收高電位信號的持續時間
   long distance2; 
    long distanceR; 
     long distanceL; 
  
  const byte IN1 = 8;// 馬達A的正轉接腳
  const byte IN2 = 7;// 馬達A的反轉接腳
  const byte IN3 = 10;// 馬達B的正轉接腳
  const byte IN4 = 9;// 馬達B的反轉接腳

  long duration ()
   {// 超音波感測程式
    digitalWrite(TrigPin,HIGH); // 觸發腳設定成高電位
    delayMicroseconds(5); // 持續5微秒f
    digitalWrite(TrigPin,LOW); // 觸發腳設定成低電位

    return pulseIn(EchoPin,HIGH); // 測量高電位的持續時間（µs）
    }
      void stop() // 馬達停止
        {
         digitalWrite(IN1, LOW);
         digitalWrite(IN2, LOW); 
         digitalWrite(IN3, LOW); 
         digitalWrite(IN4, LOW); 
         }

         void forward() // 馬達轉向：前進
         {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW); 
          digitalWrite(IN3, HIGH); 
          digitalWrite(IN4, LOW); 
         }

         
         void backward() // 馬達轉向：後退
         {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH); 
          digitalWrite(IN3, LOW); 
          digitalWrite(IN4, HIGH); 
         }

         
         void turnLeft() // 馬達轉向：左轉
         {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW); 
          digitalWrite(IN3, LOW); 
          digitalWrite(IN4, HIGH);
          delay(300);
          forward(); 
         }

         void turnRight() // 馬達轉向：右轉
         {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH); 
          digitalWrite(IN3, HIGH); 
          digitalWrite(IN4, LOW);
          delay(300);
          forward();  
         }
       int lookRight() //超音波轉右感測程式
      {
        myservo.write(155);
        delay(500);
        int distance = duration();
        delay(100);
        myservo.write(85);
        return distance;
       }

       int lookLeft() //超音波轉左感測程式
       {
        myservo.write(15);
        delay(500);
        int distance = duration();
        myservo.write(85);
        return distance;
       }
void setup() 
{
  Serial.begin(9600);

  pinMode(TrigPin, OUTPUT); // 觸發腳設定成「輸出」
  pinMode(EchoPin, INPUT); // 接收腳設定成「輸入」
  pinMode(IN1, OUTPUT); // 馬達控制板的接腳全都設定成「輸出」
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  myservo.attach(2); //模擬舵機的輸入腳
  myservo.write(170);
  delay(100);
  myservo.write(90); //模擬舵機的置中角度
  delay(100);
  myservo.write(10);
  delay(100);
  myservo.write(90); //模擬舵機的置中角度
  delay(3000);

}

void loop() 
{
  
  myservo.write(170); //模擬舵機的輸入腳
  delay(200);
  distanceR = duration()*0.034/2; // 讀取障礙物的距離
  myservo.write(90); //模擬舵機的輸入腳
  delay(200);
  distance1 = duration()*0.034/2; // 讀取障礙物的距離
  myservo.write(10);//模擬舵機的置中角度
  delay(200);
  distanceL = duration()*0.034/2; // 讀取障礙物的距離
  myservo.write(90);//模擬舵機的輸入腳
  delay(200);
  distance2 = duration()*0.034/2; // 讀取障礙物的距離
  Serial.print("Distance1:");
  Serial.println(distance1);
  Serial.print("Distance2:");
  Serial.println(distance2);
  delay(50);
  if(distance1>dangerdistance|distance2>dangerdistance) // 如果距離大於20cm…
  {
    forward(); //前進
   if (distanceR<=danger)
  { 
      stop(); //暫停馬達0.1秒
      delay(100); 

     
      turnLeft(); //向左轉
      stop();
      delay(100);
    }
            
  
    else if (distanceL<=danger)
  { 
      stop(); //暫停馬達0.1秒
      delay(100); 

     
      turnRight(); //向加轉
      stop(); 
      delay(100);
    
    }
            
   
  }

  else
  {
     if(distance1<=dangerdistance|distance2<=dangerdistance) // 如果距離小於或等於20cm…
   
      stop(); //暫停馬達0.1秒
      delay(100); 
      backward(); //馬達反轉0.3秒
      delay(300);
      stop(); //暫停馬達0.1秒
      delay(100);
      distanceR =lookRight(); 
      delay(200);
      distanceL =lookLeft();

      if(distanceR>distanceL) // 如果右方的距離大於左方的距離
      {
        turnRight(); //向加轉
        stop(); 
        }
      else //如果如果左方的距離大於右方的距離
      {
          turnLeft(); //向左轉
          stop();
      }
            
     } 
  }  
  

