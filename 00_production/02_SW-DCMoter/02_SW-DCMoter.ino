const int swPin = 32;
const int motorPin = 25;
//4:ConnectorA 9:ConnectorB

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  
  if (digitalRead(swPin) == HIGH) {
    swState = !swState; //0と1を切り替え
  }

  if(swState == 1){
    //Look at the serial monitor
    digitalWrite(motorPin, HIGH);
    Serial.println("ON");
    delay(1000);
  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("OFF");
    delay(1000);
  }

}
