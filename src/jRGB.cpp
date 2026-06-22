#include "Arduino.h"
#include "jRGB.h"

void jRGB::setPins(int redPin, int greenPin, int bluePin, bool isCommonAnode, int red, int green, int blue){
	_redPin = redPin;
	_greenPin = greenPin;
	_bluePin = bluePin;
	_isCommonAnode = isCommonAnode;

	pinMode(_redPin, OUTPUT);
	pinMode(_greenPin, OUTPUT);
	pinMode(_bluePin, OUTPUT);

	setLED(red, green, blue);
}

void jRGB::setLED(int red, int green, int blue){
	_redComp = red;
	_greenComp = green;
	_blueComp = blue;

	if (isCommonAnode) {
		analogWrite(ledRed, 255 - redValue);
		analogWrite(ledGreen, 255 - greenValue);
		analogWrite(ledBlue, 255 - blueValue);
	} else {
		analogWrite(ledRed, redValue);
		analogWrite(ledGreen, greenValue);
		analogWrite(ledBlue, blueValue);
	}
}

void jRGB::fadeLED(int redStart, int greenStart, int blueStart, int redEnd, int greenEnd, int blueEnd, int timePeriod){
	int t;

	for (t = 0; t < 32; t++) {
		setLED(redStart + (t*((redEnd - redStart) / 32)), greenStart + (t*((greenEnd - greenStart) / 32)), blueStart + (t*((blueEnd - blueStart) / 32)));

		delay(timeSpan / 32);
	}

	setLED(redEnd, greenEnd, blueEnd);
}

void jRGB::flashLEDred(int numberOfFlashes){
	int i;

	setLED(0, 0, 0);
	for (i = 0; i < numberOfFlashes; i++){
		setLED(255, 0, 0);
		delay (250);
		setLED(0, 0, 0);
		delay (250);
	}
}