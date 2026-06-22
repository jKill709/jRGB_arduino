#include <jRGB.h>

// Change these pins to match your hardware
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// false = common cathode
// true  = common anode
const bool COMMON_ANODE = false;

jRGB led(RED_PIN, GREEN_PIN, BLUE_PIN, COMMON_ANODE);


void setup()
{
    // Start off
    led.setLED(0, 0, 0);

    delay(1000);
}


void loop()
{
    /*
        Example 1:
        Fade in red from off
    */
    led.fadeLED(
        0, 0, 0,        // Start color
        255, 0, 0,      // End color
        3000            // 3 second fade
    );

    delay(1000);


    /*
        Example 2:
        Fade red back to off
    */
    led.fadeLED(
        255, 0, 0,
        0, 0, 0,
        1500            // Faster fade
    );

    delay(1000);



    /*
        Example 3:
        Fade directly from red to green
    */
    led.fadeLED(
        255, 0, 0,
        0, 255, 0,
        4000
    );

    delay(1000);



    /*
        Example 4:
        Fade green to blue
    */
    led.fadeLED(
        0, 255, 0,
        0, 0, 255,
        4000
    );

    delay(1000);



    /*
        Example 5:
        Fade blue to white
    */
    led.fadeLED(
        0, 0, 255,
        255, 255, 255,
        2500
    );

    delay(1000);



    /*
        Example 6:
        Smooth rainbow-like transitions
    */
    led.fadeLED(
        255, 255, 255,
        255, 0, 255,
        2000
    );

    led.fadeLED(
        255, 0, 255,
        255, 255, 0,
        2000
    );

    led.fadeLED(
        255, 255, 0,
        0, 255, 255,
        2000
    );

    delay(1000);



    /*
        Example 7:
        Very slow ambient fade
    */
    led.fadeLED(
        0, 0, 0,
        50, 0, 100,
        10000
    );

    led.fadeLED(
        50, 0, 100,
        0, 0, 0,
        10000
    );


    delay(2000);
}