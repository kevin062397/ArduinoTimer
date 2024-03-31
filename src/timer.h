//
//  timer.h
//  ArduinoTimer
//
//  Created by Haoyuan Kevin Xia on 2024-03-31
//

#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
	unsigned long _previousMillis; // Store the previous millis value
	unsigned long _intervalMs;	   // Interval for triggering the timer
	bool _running;				   // Flag to indicate whether the timer is running
	bool _repeat;				   // Flag to indicate whether the timer should repeat
	void (*_callback)();		   // Function pointer to the callback function

public:
	/**
	 * Constructor for the Timer class.
	 *
	 * @param intervalMs The interval (in milliseconds) at which the timer should trigger.
	 * @param callback   The function pointer to the callback function that will be called when the timer triggers.
	 * @param repeat     Whether the timer should trigger repeatedly (true) or just once (false). Default is false.
	 */
	Timer(unsigned long intervalMs, void (*callback)(), bool repeat = false);

	/**
	 * Destructor for the Timer class.
	 */
	~Timer();

	/**
	 * Start the timer.
	 */
	void start();

	/**
	 * Stop the timer.
	 */
	void stop();

	/**
	 * Update the timer. This method should be called in the main loop to update the timer state.
	 * If the timer is running and the specified interval has elapsed, it triggers the timer and optionally stops it (if not in repeat mode).
	 */
	void update();

	/**
	 * Set a new interval for the timer.
	 *
	 * @param intervalMs The new interval (in milliseconds) at which the timer should trigger.
	 */
	void setInterval(unsigned long intervalMs);

	/**
	 * Check if the timer is running.
	 *
	 * @return True if the timer is running, false otherwise.
	 */
	bool isRunning();

private:
	/**
	 * Trigger the timer callback function.
	 */
	void trigger();
};

#endif // TIMER_H
