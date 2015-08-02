#include <SoftwareSerial.h>

/*
 * 3Doodler arduino
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
}

void loop() {
  if(Serial.available() > 0){
    
    button = Serial.read();
    
    if (button == '0') {
      Serial.println("stop");
      digitalWrite(slow, LOW);
      digitalWrite(fast, LOW);
    }
    
    if (button == '1') {
      Serial.println("slow printing");
      digitalWrite(fast, LOW);
      digitalWrite(slow, HIGH);
    }
    
    if (button == '2'){
      Serial.println("fast printing");
      digitalWrite(slow, LOW);
      digitalWrite(fast, HIGH);
    }
  }
}
