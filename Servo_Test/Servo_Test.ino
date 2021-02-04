#include <Servo.h>
Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(3);
}

void loop() {
    pos=10;
    myservo.write(pos);
    delay(500);

    pos=180;
    myservo.write(pos);
    delay(500);
   
}
