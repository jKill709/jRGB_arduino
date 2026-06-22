#include <jRGB.h>

// RGB LED pins
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// Set to true for common anode RGB LEDs
const bool COMMON_ANODE = false;

// Create RGB LED object
jRGB statusLED(RED_PIN, GREEN_PIN, BLUE_PIN, COMMON_ANODE);


void setup()
{
    // Startup indication
    statusLED.setLED(0, 255, 0);   // Green = OK
    delay(2000);

    /*
       Simulate an error condition.

       The number of flashes can represent
       different error codes:

       1 flash  = Warning
       2 flashes = Sensor failure
       3 flashes = Communication failure
       4 flashes = Critical failure
    */

    int errorCode = 3;

    statusLED.flashLEDred(errorCode);

    delay(5000);
}


void loop()
{
    // Normal operation would go here

    // Keep signaling the error condition
    statusLED.flashLEDred(3);

    delay(5000);
}