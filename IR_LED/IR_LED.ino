#include <IRremote.h>
/* Connect IR sensor to A1 pin */
//Hello

const int LED1 = 7;
const int LED2 = 8;
const int IR_RECEIVE_PIN = A1;

IRrecv IrReceiver(IR_RECEIVE_PIN);

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  Serial.begin(115200);  
 
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  IrReceiver.enableIRIn();  // Start the receiver

  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);
}

uint32_t lastCmd = 0;

void loop() {
    if (IrReceiver.decode()) {
      uint32_t cmd = IrReceiver.results.value;
      IrReceiver.resume(); // Receive the next value
     
      Serial.println(cmd, HEX);
      if(cmd != 0xFFFFFFFF) {
        lastCmd = cmd;
      }
      cmd = lastCmd;
     
      if(cmd == 0x00FF22DD) {
        digitalWrite(LED1, HIGH);
      }
      if(cmd == 0x00FFC23D) {
        digitalWrite(LED2, !digitalRead(LED2));
      }
    } else {
      digitalWrite(LED1, LOW);
    }
    delay(200);
}
