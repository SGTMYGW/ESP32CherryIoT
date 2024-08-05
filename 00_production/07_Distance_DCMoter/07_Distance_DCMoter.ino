const int trigPin = 32; //32  4:ConnectorA 9:ConnectorB　超音波センサーのトリガーピン番号　超音波を発信
const int echoPin = 33; //33  5:ConnectorA 8:ConnectorB　超音波センサーのエコーピンのピン番号　超音波の反射を受信

const int motorPin = 25;//DCモーターのピン番号

float measureDist(){　//超音波センサーから距離を測定するための関数
  float Duration = 0; //Received Interval
  float Calc_Dist = 0; //Calculation results from Duration

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); //トリガーピンをLOWにして2マイクロ秒待ち
  digitalWrite(trigPin, HIGH); //Ultrasonic output        
  delayMicroseconds(10); //HIGHにして10マイクロ秒待ち
  digitalWrite(trigPin, LOW); //再度LOWにして超音波を発信

  Duration = pulseIn(echoPin, HIGH); //Input from sensor      エコーピンからの信号を pulseIn() 関数で受信し、往復時間の半分を計算
  Duration = Duration/2; //Half the round trip time
  Calc_Dist = Duration*340*100/1000000; //Set sonic speed to 340 m/s
  return Calc_Dist; //計算結果から距離を求める
}

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT); ////超音波センサーのエコー受信
  pinMode(trigPin,OUTPUT);  //超音波センサーのトリガー発信
  
  pinMode(motorPin, OUTPUT);//DCモータ
}

void loop() { 
  float result = measureDist(); //
  if (result < 40) {  //40cm内で動く
    digitalWrite(motorPin, HIGH); // DCモータON
    Serial.println(result);
    delay(300);
  } else {  //それ以外の距離でモータが止まる
    digitalWrite(motorPin, LOW); //DCモータOFF
    Serial.println(result);
    delay(300);
  }
}


