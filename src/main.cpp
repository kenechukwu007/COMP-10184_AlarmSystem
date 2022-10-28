// COMP-10184 – Mohawk College
// PIR Sensor Test Application
// Turn on the blue LED with motion is detected.

// I, William Ohia, 000791775, I acknowledge that this is my own work and
// no other person's work has been copied without acknowledgement.

#include <Arduino.h>

// digital input pin definitions
#define PIN_PIR D5
#define PIN_BUTTON D6

// *************************************************************
void setup()
{

  // configure the USB serial monitor
  Serial.begin(115200);

  // configure the LED output
  pinMode(LED_BUILTIN, OUTPUT);

  // PIR sensor is an INPUT
  pinMode(PIN_PIR, INPUT);

  // Button is an INPUT
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  // analogWriteRange(1023);
}

int pushButton()
{
  int i = 0;
  if (digitalRead(D6) == 0)
  {
    i = 2;
    return i;
  }
  return i;
}

// *************************************************************
void loop()
{
  bool a = false;

  bool bPIR;

  // read PIR sensor (true = Motion detected!).  As long as there
  // is motion, this signal will be true.  About 2.5 seconds after
  // motion stops, the PIR signal will become false.
  bPIR = digitalRead(PIN_PIR);
  if (bPIR == true)
  {
    for (int i = 0; i < 40; i++)
    {

      if (pushButton() != 2)
      {
        digitalWrite(LED_BUILTIN, LOW);
        delay(125);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(125);
      }
    }

    // delay(10000);
  }
  digitalWrite(LED_BUILTIN, LOW);
  while (a == true)
  {
    Serial.println("button pushed");
    if (bPIR == true)
    {
      a = false;
    }
  }

  // send the PIR signal directly to the LED
  // but invert it because true = LED off!
  digitalWrite(LED_BUILTIN, bPIR);

  //
}