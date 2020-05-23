// Sat May 23 11:35:50 UTC 2020 // STM32F407 Discovery running C.H. Ting's eForth
// kabnilip gelron pibulatto

// Mon Dec 23 13:59:52 UTC 2019 // STM32F405 Express running C.H. Ting's eForth
// Sat Jun  8 00:38:57 UTC 2019
// fyndov pdxva

// 23 May - seems to address a lot, by adding alot of WEIGHT:
#define WEIGHT 32760

// so this WEIGHT must be > 800 or so (probably 1200 or so).

#include <Arduino.h>

extern void blink_m(void);
extern void setup_dotstar(void); // dotstar.cpp

#define SERIAL Serial1  // the UART is on Serial1

const int STKSIZE = 8;
const int STKMASK = 7;
int stack[STKSIZE];
int p = 0;

/* TOS is Top Of Stack */
#define TOS stack[p]
/* NAMED creates a string in flash */
#define NAMED(x, y) const char x[]=y

char ch;
char chI;

/* push n to top of data stack */
void push(int n) {
  p = (p + 1)& STKMASK;
  TOS = n;
}

/* return top of stack */
int pop() {
  int n = TOS;
  p = (p - 1)& STKMASK;
  return n;
}

void throw_() {
  SERIAL.print("\r\n        THROW:  -1 \r\n");
}


void printing() {
  while (SERIAL.available()) {
    chI = SERIAL.read();
    Serial.print(chI);
  }
}

void seriAvail() {
  for (int i = 1; i < WEIGHT; i++) {
      if (SERIAL.available()) {
        printing();
        if (!SERIAL.available()) delay(1);
    }
  }
}

void local_echo(void) {
  if (ch == '\n') { Serial.print(' '); return; }
}

byte reading() {
  if (!Serial.available()) return 1;
  ch = Serial.read();   // local keystroke is read
  local_echo();         // echo that character, locally // KLUDGE

  SERIAL.write(ch);     // immediately send it out the UART port

  if (ch == '\r') {
  while (!SERIAL.available());

    Serial.print("");
    SERIAL.print("");
  }

  // ^^ eForth doesn't like to report, unprodded,
  //    on most (but not all) words.
  //    .S is an exception, for example.
  //    Had suspected eForth itself was
  //    coded somewhat unintuitively; now
  //    it seems more likely that serial
  //    timing is responsible for the 'bug'
  //    ('failure to complete without an
  //    '.. additional space/other char
  //    '.. sent to eForth, after having
  //    '.. pressed ENTER').

  seriAvail();
}

void readword() {
  while (reading());
}

/* Arduino main loop */

void setup() {
  Serial.begin(38400); // USB
  setup_dotstar(); // turn off dotstar (apa-102 RGB LED)

  while (!Serial) {
    blink_m();
  }

  Serial.println ("terminal - based on the Forth-like interpreter");
  SERIAL.begin(115200); // TX/RX pair
}

void loop() {
  readword();
}
