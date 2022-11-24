#include "LedControl.h"                     //lib_led.
LedControl lc = LedControl(11, 13, 10, 3);  //SPI_data=11,clk=13,cs=10,3numdevice.
unsigned int val[4] = { 0 };                //Array
void setup() {
  for (int a = 0; a < 3; a++) {  //Scan each modules max7219.
    lc.shutdown(a, false), lc.setIntensity(a, 1), lc.clearDisplay(a);
  }
}
void loop() {
  for (int i = 0; i < 10000; i++) {  //Length of number.
    val[3] = (i / 1000);             //thousands.
    val[2] = ((i / 100) % 10);       //hundreds.
    val[1] = ((i / 10) % 10);        //tens.
    val[0] = (i % 10);               //ones.
    if (val[3] > 0) {
      lc.setDigit(2, 6, val[3], false);
      lc.setDigit(1, 7, val[3], false);
      lc.setDigit(0, 3, val[3], false);
    }
    if (val[2] > 0 || val[3] >= 1) {
      lc.setDigit(2, 5, val[2], false);
      lc.setDigit(1, 6, val[2], false);
      lc.setDigit(0, 2, val[2], false);
    }
    if (val[1] > 0 || val[2] >= 1 || val[3] >= 1) {
      lc.setDigit(2, 4, val[1], false);
      lc.setDigit(1, 5, val[1], false);
      lc.setDigit(0, 1, val[1], false);
    }
    if (val[0] >= 0) {
      lc.setDigit(2, 3, val[0], false);
      lc.setDigit(1, 4, val[0], false);
      lc.setDigit(0, 0, val[0], false);
    }
    delay(100);
    lc.clearDisplay(0);
  }
}
