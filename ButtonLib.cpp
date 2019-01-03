/*
  ButtonLib - A library for abstracting button management
  Created by Jared Cantilina January 2019
  Released under the MIT license
*/

#include "ButtonLib.h"
#include "Arduino.h"

const int DELAY = 200;
Button::Button(uint8_t pin, uint8_t pull, bool normalState){
  _pin = pin;
  _pull = pull;
  _state = pull;
  _hasChanged = false;
  _ignoreTime = 0;
  PRESSED = !pull;
  if(normalState){
    PRESSED = !PRESSED;
  }
}

Button::Button(uint8_t pin){
  _pin = pin;
  _pull = HIGH;
  _state = HIGH;
  _hasChanged = false;
  _ignoreTime = 0;
  PRESSED = LOW;
}

void Button::begin(){
  if(_pull == HIGH){
    pinMode(_pin, INPUT_PULLUP);
  } else {
    pinMode(_pin, INPUT);
  }
}

bool Button::getState(){
  if(_ignoreTime < millis() && digitalRead(_pin) != _state){
    _hasChanged = true;
    _state = !_state;
    _ignoreTime = millis() + DELAY;
  }
  return _state;
}

bool Button::hasChanged(){
  if(_hasChanged){
    _hasChanged = false;
    return true;
  }
  return false;
}

bool Button::isPressed(){
  if(getState() == PRESSED && hasChanged()){
    return true;
  }
  return false;
}

bool Button::isHeld(int dur){
  if(getState() == PRESSED && millis() > _ignoreTime-DELAY+dur){
    return true;
  }
  return false;
}

bool Button::isReleased(){
  if(getState() == !PRESSED && hasChanged()){
    return true;
  }
  return false;
}

bool Button::stateChanged(){
  getState();
  return hasChanged();
}
