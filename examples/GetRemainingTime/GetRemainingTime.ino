//
//  GetRemainingTime.ino
//  ArduinoTimer
//
//  Created by Haoyuan Kevin Xia on 2024-03-31
//

#include "timer.h"

// Forward declaration of the callback functions
void timerCallback();
void checkRemainingTime();

// Create instances of Timer with the callback functions
Timer myTimer(10000, timerCallback, false);					   // Timer triggers after 10 seconds
Timer checkRemainingTimeTimer(1000, checkRemainingTime, true); // Timer triggers every 1 second to check the remaining time of myTimer

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

	checkRemainingTimeTimer.start();
	// Check the remaining time immediately after starting the timer
	// The first trigger of the timer is after 1 second
	checkRemainingTime();
}

void loop()
{
	myTimer.update();
	checkRemainingTimeTimer.update();

	// Your other code here
}

// Callback function for the timer
void timerCallback()
{
	Serial.println("millis(): " + String(millis()));
	Serial.println("Timer triggered!");
	checkRemainingTimeTimer.stop();
}

void checkRemainingTime()
{
	// Get the remaining time of myTimer
	unsigned long remainingTime = myTimer.getRemainingTime();
	Serial.print("Remaining time: ");
	Serial.println(remainingTime);
}
