#include <jRGB.h>

jRGB led(9, 10, 11, false);

void setup() {
}

void loop() {

    led.setLED(255, 0, 0);
    delay(1000);

    led.setLED(0, 255, 0);
    delay(1000);

    led.setLED(0, 0, 255);
    delay(1000);
}