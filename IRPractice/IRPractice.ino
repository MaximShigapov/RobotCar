#include <IRremote.h>
const int IR_RECEIVE_PIN = A1;
IRrecv IrReceiver(IR_RECEIVE_PIN);
int ENA = 5;
int IN1 = 6;
int IN2 = 7;
int ENB = 11;
int IN3 = 8;
int IN4 = 9;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
 
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  Serial.begin(115200);
  Serial.println("Enabling IRin");
  IrReceiver.enableIRIn(); 

  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);

 
  
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

uint32_t lastCmd = 0;

void loop() {
  if(IrReceiver.decode()) {
    uint32_t cmd = IrReceiver.results.value;
    IrReceiver.resume(); // Receive the next value
     
    Serial.println(cmd, HEX);
    if(cmd != 0xFFFFFFFF) {
      lastCmd = cmd;
    }
    cmd = lastCmd;


     if(cmd == 0x00FF629D) {

      leftForward();
      rightForward();
      delay(500);
      rightStop();
      leftStop();
     
    }

     if(cmd == 0x00FFA857) {

      leftBack();
      rightBack();
      delay(500);
      rightStop();
      leftStop();
     
    }
     
    if(cmd == 0x00FF22DD) {

      leftForward();
      rightBack();
      delay(320);
      rightStop();
      leftStop();
      
     
    }
    if(cmd == 0x00FFC23D) {
      rightForward();
      leftBack();
      delay(320);
      rightStop();
      leftStop();
      
    }
  }
  
  delay(200);
}
      
  
