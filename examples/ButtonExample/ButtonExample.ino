#include <ButtonLib.h>

Button butt(12);
void setup() {
  // put your setup code here, to run once:
  butt.begin();
  pinMode(13,OUTPUT);
}
uint8_t ledState = LOW;
void loop() {
  // put your main code here, to run repeatedly:
  if(butt.isPressed()){
    toggleLED();
  }

  if(butt.isHeld(3000)){
    blinkLED();
  }
}

void toggleLED(){
  ledState = !ledState;
  digitalWrite(13, ledState);
}

void blinkLED(){
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
}
