#include <Servo.h>
Servo myservo;
int pos = 0;
int ENA = 5;
int IN1 = 6;
int IN2 = 7;
int ENB = 11;
int IN3 = 8;
int IN4 = 9;

bool gDone = false;


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
 
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  myservo.attach(3);
}

void leftStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void leftForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void leftBack() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void rightStop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void rightForward() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void rightBack() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

 
}


void loop() {

    
    rightForward();
    leftForward();
    delay(500);

    rightStop();
    leftStop();
    delay(500); //Goes Foward(1)
 
    rightForward();
    leftBack();
    delay(320);
     
    rightStop();
    leftStop();
    delay(500); //Turns Right

    pos=10;
    myservo.write(pos);
    delay(500);

    pos=180;
    myservo.write(pos);
    delay(500);

    rightForward();
    leftForward();
    delay(500);

    rightStop();
    leftStop();
    delay(500);  //Goes Foward(2)

    rightForward();
    leftBack();
    delay(320);
     
    rightStop();
    leftStop();
    delay(500);  //Turns Right

    pos=10;
    myservo.write(pos);
    delay(500);

    pos=180;
    myservo.write(pos);
    delay(500);


    rightForward();
    leftForward();
    delay(500);

    rightStop();
    leftStop();
    delay(500);  //Goes Foward(3)

    rightForward();
    leftBack();
    delay(320);
     
    rightStop();
    leftStop();
    delay(500);  //Turns Right

    pos=10;
    myservo.write(pos);
    delay(500);

    pos=180;
    myservo.write(pos);
    delay(500);

    rightForward();
    leftForward();
    delay(500);

    rightStop();
    leftStop();
    delay(500);  //Goes Foward(4)

    rightForward();
    leftBack();
    delay(320);
     
    rightStop();
    leftStop();
    delay(500);  //Turns Right

    pos=10;
    myservo.write(pos);
    delay(500);

    pos=180;
    myservo.write(pos);
    delay(500);

}
