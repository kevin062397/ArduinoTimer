//
//  timer.cpp
//  ArduinoTimer
//
//  Created by Haoyuan Kevin Xia on 2024-03-31
//

#include <Arduino.h>

#include "timer.h"

Timer::Timer(unsigned long intervalMs, void (*callback)(), bool repeat = false) : _intervalMs(intervalMs), _running(false), _repeat(repeat), _callback(callback) {}

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
		if (currentMillis - _previousMillis >= _intervalMs)
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

void Timer::trigger()
{
	if (_callback != NULL)
	{
		_callback();
	}
}
