#include "stdafx.h"
#include <iostream>
#include "VTime.h"

using namespace std;

int main()
{
	VTime a(1, 1, 1);
	a.getASCIITime();
	a.addSeconds(5);
	a.getASCIITime();
	a - 5;
	a.getASCIITime();
	a.setHours(2);
	a.getASCIITime();
	a.setMinutes(1);
	a.getASCIITime();
	a.setSeconds(1);
	a.getASCIITime();

	return 0;
}