#include "stdafx.h"
#include ".\VTime.h" // This works but is freaky!   I will leave it in so we can talk.

#include <iostream>
#include "VTime.h"

using namespace std;

// Adds a specified number of seconds onto the time.
void VTime::addSeconds(int a_seconds)
{
	m_time += a_seconds;
	if (m_time > 60) return;
}

VTime VTime::operator +(int a_seconds)
{
	VTime tmp(m_time);
	tmp.addSeconds(a_seconds);
	return tmp;
}

// Gets the time as an ASCII string
string VTime::getASCIITime()
{
	char buff[128];
	sprintf_s(buff, "%2.2d:%2.2d:%2.2d", m_time);

	return buff;
}

void VTime::subSeconds(int a_seconds)
{
	m_time -= a_seconds;
	if (m_time > 60) return;
}


VTime VTime::operator -(VTime x)
{
	VTime tmp(m_time);
	tmp.subSeconds(m_time);
	return m_time - x.m_time;
}