// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// This demo code returns raw readings, public domain

#include <stdint.h>
#include "TouchScreen.h"

#define YP PB1  // must be an analog pin, use "An" notation!
#define XM PB0  // must be an analog pin, use "An" notation!
#define YM PA1   // can be a digital pin
#define XP PA0   // can be a digital pin

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup(void) {
  Serial1.begin(9600);
  Serial.print("pressure Threshold: ");
  Serial1.println(ts.pressureThreshhold);
}

void loop(void) {
  // a point object holds x y and z coordinates
  TSPoint p = ts.getPoint();
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > ts.pressureThreshhold) {
     Serial1.print("X = "); Serial1.print(p.x);
     Serial1.print("\tY = "); Serial1.print(p.y);
     Serial1.print("\tPressure = "); Serial1.println(p.z);
  }

  delay(100);
}
