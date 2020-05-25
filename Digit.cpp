#include "Arduino.h"
#include "Digit.h"

Digit::Digit(byte _a_pin, byte _b_pin, byte _c_pin, byte _d_pin, byte _e_pin, byte _f_pin, byte _g_pin, byte _dp_pin)
: segments {_a_pin, _b_pin, _c_pin, _d_pin, _e_pin, _f_pin, _g_pin, _dp_pin}
{
  a_pin = _a_pin;
  b_pin = _b_pin;
  c_pin = _c_pin;
  d_pin = _d_pin;
  e_pin = _e_pin;
  f_pin = _f_pin;
  g_pin = _g_pin;
  dp_pin = _dp_pin;
  for (byte i = 0; i < 8; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void Digit::displayMessage(String str, int delay_ms) {
  for (int i = 0; i < str.length(); i++) {
    display((char) str[i]);
    delay(delay_ms);
    clear();
  }
}

void Digit::display(int num, boolean decimal = false) {
  switch (num) {
    case 0: {
      byte segs0[] = {a_pin, b_pin, c_pin, d_pin, e_pin, f_pin};
      set(segs0, 6);
      break;
    }
    case 1: {
      byte segs1[] = {b_pin, c_pin};
      set(segs1, 2);
      break;
    }
    case 2: {
      byte segs2[] = {a_pin, b_pin, g_pin, e_pin, d_pin};
      set(segs2, 5);
      break;
    }
    case 3: {
      byte segs3[] = {a_pin, b_pin, g_pin, c_pin, d_pin};
      set(segs3, 5);
      break;
    }
    case 4: {
      byte segs4[] = {f_pin, g_pin, b_pin, c_pin};
      set(segs4, 4);
      break;
    }
    case 5:
      {
      byte segs5[] = {a_pin, f_pin, g_pin, c_pin, d_pin};
      set(segs5, 5);
      break;
      }
    case 6: {
      byte segs6[] = {a_pin, f_pin, g_pin, e_pin, d_pin, c_pin};
      set(segs6, 6);
      break;
    }
    case 7: {
      byte segs7[] = {a_pin, b_pin, c_pin};
      set(segs7, 3);
      break;
    }
    case 8: {
      byte segs8[] = {a_pin, b_pin, c_pin, d_pin, e_pin, f_pin, g_pin};
      set(segs8, 7);
      break;
    }
    case 9: {
      byte segs9[] = {a_pin, b_pin, c_pin, f_pin, g_pin};
      set(segs9, 5);
      break;
    }
    default:
      break;
  }
  if (decimal) {
      digitalWrite(dp_pin, HIGH);
  }
}

void Digit::display(char c, boolean period = false) {
  switch (c) {
    case 'A': {
      byte segsA[] = {a_pin, b_pin, c_pin, f_pin, e_pin, g_pin};
      set(segsA, 6);
      break;
    }
    case 'a': {
      byte segsa[] = {a_pin, b_pin, c_pin, d_pin, e_pin, g_pin};
      set(segsa, 6);
      break;
    }
    case 'b': {
      byte segsb[] = {f_pin, e_pin, d_pin, c_pin, g_pin};
      set(segsb, 5);
      break;
    }
    case 'C': {
      byte segsC[] = {a_pin, f_pin, e_pin, d_pin};
      set(segsC, 4);
      break;
    }
    case 'c': {
      byte segsc[] = {g_pin, e_pin, d_pin};
      set(segsc, 3);
      break;
    }
    case 'd': {
      byte segsd[] = {b_pin, g_pin, e_pin, d_pin, c_pin};
      set(segsd, 5);
      break;
    }
    case 'E': {
      byte segsE[] = {a_pin, f_pin, g_pin, e_pin, d_pin};
      set(segsE, 5);
      break;
    }
    case 'e': {
      byte segse[] = {a_pin, b_pin, g_pin, f_pin, d_pin, e_pin};
      set(segse, 6);
      break;
    }
    case 'F': {
      byte segsF[] = {a_pin, f_pin, g_pin, e_pin};
      set(segsF, 4);
      break;
    }
    case 'G': {
      byte segsG[] = {a_pin, f_pin, e_pin, d_pin, c_pin};
      set(segsG, 5);
      break;
    }
    case 'H': {
      byte segsH[] = {f_pin, e_pin, g_pin, b_pin, c_pin};
      set(segsH, 5);
      break;
    }
    case 'h': {
      byte segsh[] = {f_pin, e_pin, g_pin, c_pin};
      set(segsh, 4);
      break;
    }
    case 'I': case 'l': {
      byte segsI[] = {f_pin, e_pin};
      set(segsI, 2);
      break;
    }
    case 'i': {
      byte segsi[] = {e_pin};
      set(segsi, 1);
      break;
    }
    case 'J': {
      byte segsJ[] = {e_pin, d_pin, c_pin, b_pin};
      set(segsJ, 4);
      break;
    }
    case 'L': {
      byte segsL[] = {f_pin, e_pin, d_pin};
      set(segsL, 3);
      break;
    }
    case 'n': {
      byte segsn[] = {e_pin, g_pin, c_pin};
      set(segsn, 3);
      break;
    }
    case 'O': {
      byte segsO[] = {a_pin, b_pin, c_pin, d_pin, e_pin, f_pin};
      set(segsO, 6);
      break;
    }
    case 'o': {
      byte segso[] = {g_pin, c_pin, d_pin, e_pin};
      set(segso, 4);
      break;
    }
    case 'P': case 'p': {
      byte segsP[] = {a_pin, b_pin, g_pin, f_pin, e_pin};
      set(segsP, 5);
      break;
    }
    case 'q': {
      byte segsq[] = {a_pin, b_pin, c_pin, f_pin, g_pin};
      set(segsq, 5);
      break;
    }
    case 'r': {
      byte segsr[] = {e_pin, g_pin};
      set(segsr, 2);
      break;
    }
    case 'S': case 's': {
      byte segsS[] = {a_pin, f_pin, g_pin, c_pin, d_pin};
      set(segsS, 5);
      break;
    }
    case 't': {
      byte segst[] = {f_pin, e_pin, d_pin, g_pin};
      set(segst, 4);
      break;
    }
    case 'U': {
      byte segsU[] = {f_pin, e_pin, d_pin, c_pin, b_pin};
      set(segsU, 5);
      break;
    }
    case 'u': {
      byte segsu[] = {e_pin, d_pin, c_pin};
      set(segsu, 3);
      break;
    }
    case 'Y': case 'y': {
      byte segsY[] = {f_pin, g_pin, b_pin, c_pin, d_pin};
      set(segsY, 5);
      break;
    }
    case '"': {
      byte segsdq[] = {f_pin, b_pin};
      set(segsdq, 2);
      break;
    }
    case '\'': {
      byte segssq[] = {f_pin};
      set(segssq, 1);
      break;
    }
    case '=': {
      byte segseq[] = {g_pin, d_pin};
      set(segseq, 2);
      break;
    }
    case '-': {
      byte segsdash[] = {g_pin};
      set(segsdash, 1);
      break;
    }
    case '_': {
      byte segsus[] = {d_pin};
      set(segsus, 1);
      break;
    }
    case ' ': {
      clear();
      break;
    }
    case '.': {
      byte segsdot[] = {dp_pin};
      set(segsdot, 1);
      break;
    }
    default:
      display(c - '0'); // display num if provided as a char
      break;
  }
  if (period) {
      digitalWrite(dp_pin, HIGH);
  }
}

void Digit::clear() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(segments[i], LOW);
  }
}

void Digit::set(byte segs[], byte size) {
  for (byte i = 0; i < size; i++) {
    digitalWrite(segs[i], HIGH);
  }
}
