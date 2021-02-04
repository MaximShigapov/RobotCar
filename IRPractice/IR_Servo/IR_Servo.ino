#include <IRremote.h>
#include <Servo.h>
Servo myservo;
int pos = 0;
const int IR_RECEIVE_PIN=A1;
IRrecv IrReceiver(IR_RECEIVE_PIN);

void setup() {
 myservo.attach(3);

  Serial.begin(115200);
  //Serial.println("Enabling IRin");
  IrReceiver.enableIRIn(); 

  //Serial.print(F("Ready to receive IR signals at pin "));
  //Serial.println(IR_RECEIVE_PIN);

}

uint32_t lastCmd = 0;

void loop() {
   if(IrReceiver.decode()) {
    uint32_t cmd = IrReceiver.results.value;
    IrReceiver.resume(); // Receive the next value
   
    //Serial.println(cmd, HEX);
    
    

     if(cmd == 0x00FF629D) {

    pos=180;
    myservo.write(pos);
    delay(500);
    
     
    }

    if(cmd == 0x00FFA857) {

    pos=0;
    myservo.write(pos);
    delay(500);
    
   }
    if(cmd == 0x00FFC23D) {

    pos=pos-10;
    myservo.write(pos);
    delay(300);
    
   }
   if(cmd == 0x00FF22DD) {

    pos=pos+10;
    myservo.write(pos);
    delay(300);
    
   }
   Serial.println(pos);
   }

  }
