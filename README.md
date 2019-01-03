# ButtonLib
A comprehensive button library for arduino. Easily trigger actions on button press, button release, or both. Can also trigger on a button being held for an arbitrary amount of time. Automatically debounces input.

# Functions
* Button(int pin) - constructor for default button: normally open between the pin and ground. Suitable for most applications.
* Button(int pin, int pull, bool normalState) - non-default constructor with options for pull down pins and normally closed buttons. normalState true for normally closed buttons, normalState false for normally open.
* begin() - initializes the selected pin as either a pullup or pulldown button.
* isPressed() - returns true when the button is pressed.
* isReleased() - returns true when the button is released.
* isHeld(int durration) - returns true if the button has been held for longer than durration
* stateChanged() - returns true when the button is pressed or released.
