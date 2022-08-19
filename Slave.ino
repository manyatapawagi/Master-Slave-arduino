int lastButtonState = 0;
int buzzerPin = 13;
int buttonPin = 9;
int buttonState = 0;
int state = '0';
int lastState = '0';

//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(0, 1);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  noTone(buzzerPin);
  Serial.begin(38400);
  //  mySerial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    delay(100);
    //Serial.println(state);

  }
  if (state != lastState)
  {
    if (state ==  '1') {
      tone(buzzerPin, 5000);
      delay(500);
      noTone(buzzerPin);
      //state == '0';
    }
    else{
      noTone(buzzerPin);
      //      state == 0;
    }
  }
  lastState = state;

  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      //digitalWrite(ledPin, HIGH);
      Serial.write('1');
      //Serial.println('1');
      delay(50);
      Serial.write('0');
    } else {
      //      digitalWrite(ledPin, LOW);
      Serial.write('0');
    }
    delay(50);
  }
  lastButtonState = buttonState;

}
