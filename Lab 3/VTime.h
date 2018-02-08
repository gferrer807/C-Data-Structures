#pragma once
#include <iostream>
#include <string>
using namespace std;

class VTime
{
public:

	// Constructor for this class.  We allow the user to initially set the stime or it will be set to zero.
	VTime(int a_hours = 0, int a_minutes = 0, int a_seconds = 0)
	{
		m_time = a_hours * 3600 + a_minutes * 60 + a_seconds;
	}
	// Accessor functions.
	int getHours()
	{
		return m_time/3600;
	}
	int getMinutes()
	{
		return m_time/60;
	}
	int getSeconds()
	{
		return m_time;
	}
	void setHours(int a_hours)
	{
		m_time = ((a_hours * 3600) + getMinutes() + getSeconds());
	}
	void setMinutes(int a_minutes)
	{
		m_time = (getHours() + (a_minutes * 60) + getSeconds());
	}
	void setSeconds(int a_seconds)
	{
		m_time = ((getHours() + (getMinutes() * 60) + a_seconds));
	}
	// A function to add a specified number of seconds to the time.
	void addSeconds(int a_seconds);

	// Plus operator to add seconds onto the time.
	VTime operator +(int a_seconds);

	// Gets the time as an ASCII string.
	string getASCIITime();

	// Minus operator to subtract seconds from the time.
	VTime operator -(VTime x);

private:
	int m_time;

	// A function to subtract a specified number of seconds from the time.
	void subSeconds(int a_seconds);

	//with these 3 integers, its 12 bytes of memory
	//replace these 3 variables with m_time to save memory
	//user should be able to work with the same functions

	//3600 m_hours + 60 m_minutes + m_seconds
	//return m_time/3600;
	//look to kumar lab for solution

	//sethours(){ m_hours = a_hour}
	//new m_hours = a_hours = a_hour * 3600 + og minutes * 60 + og seconds;

	//submit main program .cpp
	//VTime.cpp
	//VTime.h

	//m_time % 24 * 3600
};
