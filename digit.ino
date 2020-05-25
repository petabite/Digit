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
