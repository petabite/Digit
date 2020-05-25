<h1>Digit</h1>

**Arduino library for controlling seven-segment displays**

# Contents
- [Contents](#contents)
- [Features](#features)
- [Changelog](#changelog)
- [Installation](#installation)
- [Quick Start](#quick-start)
- [Documentation](#documentation)
    - [`Digit(byte a_pin, byte b_pin, byte c_pin, byte d_pin, byte e_pin, byte f_pin, byte g_pin, byte dp_pin)`](#digitbyte-a_pin-byte-b_pin-byte-c_pin-byte-d_pin-byte-e_pin-byte-f_pin-byte-g_pin-byte-dp_pin)
          - [Description](#description)
          - [Parameters](#parameters)
    - [`Digit.displayMessage(String str, unsigned int delay_ms)`](#digitdisplaymessagestring-str-unsigned-int-delay_ms)
          - [Description](#description-1)
          - [Parameters](#parameters-1)
    - [`Digit.display(int num, boolean decimal = false)`](#digitdisplayint-num-boolean-decimal--false)
          - [Description](#description-2)
          - [Parameters](#parameters-2)
    - [`Digit.display(char c, boolean period = false)`](#digitdisplaychar-c-boolean-period--false)
          - [Description](#description-3)
          - [Parameters](#parameters-3)
    - [`Digit.clear()`](#digitclear)
          - [Description](#description-4)

# Features
- display representations of numbers, letters, and punctuation on a seven-segment display
- control multiple displays for more complex arrangements
- compatible with Arduino

# Changelog

**v1.0 - 5/24/20**
- first release

# Installation
copy `Digit.h` and `Digit.cpp` into a folder called `Digit` to the Arduino `libraries` folder and it should appear in the libraries list.

# Quick Start

**Digit can display the following characters:**

  **Numbers**
  - 0123456789

  **Letters**
  -  AabCcdEeFGHhIiJLlnOoPpqrSstUuYy

  **Punctuation**
  -  ‎ ‎‎ (space)
  -  " (double quote)
  -  ' (single quote)
  -  = (equals)
  -  . (period)
  -  \- (dash)
  -  _ (underscore)

**Example Setup**

Segment names

![segments](https://raw.githubusercontent.com/petabite/Digit/master/docs/segs.png)

Setup on breadboard

![breadboard layout](https://raw.githubusercontent.com/petabite/Digit/master/docs/digit.png)

**Example Code**
```cpp
#include "Digit.h"

Digit digit(2,3,4,5,6,7,8,9); // init Digit object

void setup()
{

}

void loop()
{
  // hello!
  digit.displayMessage("HELLO.", 500);
  // count to nine
  for (int i = 0; i < 10; i++) {
    digit.display(i);
    delay(1000);
    digit.clear();
  }
  // loop thru all possible chars
  digit.displayMessage("0123456789 AabCcdEeFGHhIiJLlnOoPpqrSstUuYy \"'=.-_", 300);
}


```

# Documentation

<h2>Constructor</h2>

### `Digit(byte a_pin, byte b_pin, byte c_pin, byte d_pin, byte e_pin, byte f_pin, byte g_pin, byte dp_pin)`
    
  ###### Description
  - initialize Digit object
  ###### Parameters
  - a_pin - (byte) pin number for the a segment
  - b_pin - (byte) pin number for the b segment
  - c_pin - (byte) pin number for the c segment
  - d_pin - (byte) pin number for the d segment
  - e_pin - (byte) pin number for the e segment
  - f_pin - (byte) pin number for the f segment
  - g_pin - (byte) pin number for the g segment
  - dp_pin - (byte) pin number for the decimal point segment


<h2>Members</h2>
        
### `Digit.displayMessage(String str, unsigned int delay_ms)`

  ###### Description
  - displays message one char at a time separated by the delay
  ###### Parameters
  - str - (String) message to display
  - delay_ms (unsigned int) delay in ms

### `Digit.display(int num, boolean decimal = false)`

  ###### Description
  - display a single number with optional decimal point
  ###### Parameters
  - num - (int) number to display
  - decimal = (boolean) show the decimal point or not. Default: `false`

### `Digit.display(char c, boolean period = false)`

  ###### Description
  - display a single char with optional period
  ###### Parameters
  - c - (char) char to display
  - period - (boolean) show the period or not. Default: `false`

### `Digit.clear()`

  ###### Description
  - clear the display
  