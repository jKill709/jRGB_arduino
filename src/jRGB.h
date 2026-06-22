#include <arduino.h>

#ifndef JRGB_h
#define JRGB_h

class jRGB {
	public:
		jRGB(int redPin, int greenPin, int bluePin, bool isCommonAnode) {
			setPins(redPin, greenPin, bluePin, isCommonAnode, 0, 0, 0);
		};
		jRGB(int redPin, int greenPin, int bluePin, int red, int green, int blue) {
			setPins(redPin, greenPin, bluePin, isCommonAnode, red, green, blue);
		};
		int getRed() {
			return _redComp;
		};
		int getGreen() {
			return _greenComp;
		};
		int getBlue() {
			return _blueComp;
		};
		void setLED(int red, int green, int blue);
		void fadeLED(int redStart, int greenStart, int blueStart, int redEnd, int greenEnd, int blueEnd, int timePeriod);
		void flashLEDred(int numberOfFlashes);
	private:
		int _redPin;
		int _greenPin;
		int _bluePin;
		bool _isCommonAnode = false;
		int _redComp = 0;
		int _greenComp = 0;
		int _blueComp = 0;

		void setPins(int redPin, int greenPin, int bluePin, bool isCommonAnode, int red, int green, int blue);
};

#endif