//
//  timer.cpp
//  ArduinoTimer
//
//  Created by Haoyuan Kevin Xia on 2024-03-31
//

#include <Arduino.h>

#include "timer.h"

Timer::Timer(unsigned long intervalMillis, void (*callback)(), bool repeat) : _intervalMillis(intervalMillis), _running(false), _repeat(repeat), _callback(callback) {}

Timer::~Timer() {}

void Timer::start()
{
	_running = true;
	_previousMillis = millis();
}

void Timer::stop()
{
	_running = false;
}

void Timer::update()
{
	if (_running)
	{
		unsigned long currentMillis = millis();
		if (currentMillis - _previousMillis >= _intervalMillis)
		{
			_previousMillis = currentMillis;
			trigger();
			if (!_repeat)
			{
				stop(); // Stop the timer if not in repeat mode
			}
		}
	}
}

void Timer::setInterval(unsigned long intervalMillis)
{
	_intervalMillis = intervalMillis;
}

bool Timer::isRunning()
{
	return _running;
}

unsigned long Timer::getRemainingTime()
{
	if (_running)
	{
		unsigned long currentMillis = millis();
		unsigned long elapsedTime = currentMillis - _previousMillis;
		if (elapsedTime >= _intervalMillis)
		{
			return 0; // Timer has elapsed, remaining time is 0
		}
		else
		{
			return _intervalMillis - elapsedTime; // Remaining time until the next invocation
		}
	}
	else
	{
		return 0; // Timer is not running, remaining time is 0
	}
}

void Timer::trigger()
{
	if (_callback != NULL)
	{
		_callback();
	}
}
