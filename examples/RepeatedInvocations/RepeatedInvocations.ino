//
//  RepeatedInvocations.ino
//  ArduinoTimer
//
//  Created by Haoyuan Kevin Xia on 2024-03-31
//

#include "timer.h"

// Forward declaration of the callback function
void timerCallback();

// Create an instance of Timer with the callback function
Timer myTimer(1000, timerCallback, true); // Timer with 1-second interval

void setup()
{
	Serial.begin(9600);

	while (!Serial)
	{
		; // wait for serial port to connect
	}

	Serial.println("millis(): " + String(millis()));
	Serial.println("System started!");

	myTimer.start();
}

void loop()
{
	myTimer.update();
	// Your other code here
}

// Callback function for the timer
void timerCallback()
{
	Serial.println("millis(): " + String(millis()));
	Serial.println("Timer triggered!");
}
