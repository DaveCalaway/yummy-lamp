#include <SoftwareSerial.h>

/*
 * 3Doodler arduino Hack https://goo.gl/n0tyrK
 * 
 * Version 0.10
 */
 
// set pin numbers:
const int slow = 7;    
const int fast =  8;   
int button = 0;  

// variables will change:
//int buttonState = 0;         // variable for reading the status

void setup() {
  // initialize 
  pinMode(slow, OUTPUT);
  pinMode(fast, OUTPUT);
  Serial.begin(9600);
  Serial.print("0 = STOP -- 1 = SLOW -- 2 = FAST -- 3 = Reverse /n");
}

void loop() {
  if(Serial.available() > 0){
    
      button = Serial.read();
      
      if (button == '0') {     // STOP
        Serial.println("stop");
        digitalWrite(slow, LOW);
        digitalWrite(fast, LOW);
      }
      
      if (button == '1') {              // SLOW
        Serial.println("slow printing");
        digitalWrite(fast, LOW);
        digitalWrite(slow, HIGH);
      }
      
      if (button == '2'){               // FAST
        Serial.println("fast printing");
        digitalWrite(slow, LOW);
        digitalWrite(fast, HIGH);
      }
      
      if (button == '3'){         // Reverse
        Serial.println("Reverse");
        digitalWrite(slow, HIGH);
        digitalWrite(fast, HIGH);
      }
  }
}
