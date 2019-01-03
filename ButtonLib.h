/*
  ButtonLib - A library for abstracting button management
  Created by Jared Cantilina January 2019
  Released under the MIT license
*/

#ifndef BUTTONLIB_H
#define BUTTONLIB_H
#include "Arduino.h"

class Button{
  public:
    // constructor with pull option and N.C. option
    // pull = HIGH for pullup on pin - DEFAULT
    // pull = LOW for pulldown on pin
    // normalState = true for normally closed buttons
    // normalState = false for normally open buttons - DEFAULT
    Button(uint8_t pin, uint8_t pull, bool normalState);

    Button(uint8_t pin); // constructor with default values
    void begin(); // sets state on pin
    bool isPressed(); // returns true once when button is closed
    bool isReleased(); // returns true once when button is released
    bool isHeld(int dur); // returns true when button has been held for time dur
    bool getState(); // returns current state of button
    bool stateChanged(); // returns true when button changes state

  private:
    uint8_t _pin;
    uint8_t _pull;
    uint8_t _state;
    bool _hasChanged;
    unsigned long _ignoreTime;
    uint8_t PRESSED;

    bool hasChanged(); // used after getState to for toggles and such
};
#endif
