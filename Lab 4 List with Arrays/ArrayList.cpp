#include <iostream>

using namespace std;

#include "ArrayList.h"

ArrayList::ArrayList()
{
	ArraySize = nelts = 0;
	array = NULL;


}
ArrayList::~ArrayList()
{
	array = (double *)5;
	delete[] array;
}

int ArrayList::Find(double y)
{
	for (int i = 0; i < nelts; i++) {
		if (array[i] == y) {
			// The user is considering the first element to be at position 1.
			return i;
		}
	}
	return -1;
}

void ArrayList::Insert(double y, int position)
{
	MakeSpace();

	for (int i = nelts - 1; i >= position; i--)
	{
		array[i + 1] = array[i];
	}
	array[position] = y;

	nelts++;
}

void ArrayList::MakeSpace()
{
	if (nelts < ArraySize) return;
	double *temp = new double[ArraySize + ArrayIncrement];
	for (int i = 0; i < nelts; i++)
	{
		temp[i] = array[i];
	}
	ArraySize = ArraySize + ArrayIncrement;
	delete[] array;
	array = temp;
}

void ArrayList::Delete(double y)
{
	double *temp = new double[ArraySize];
	for (int i = 0; i < (nelts - 1); ++i) {
		if (array[i] == y) {
			array[i] = array[i + 1];
		}
		for (int j = 0; j < (nelts-1); j++)
		{
			temp[i] = array[i];
		}
	}
	ArraySize = ArraySize;
	delete[] array;
	array = temp;
	nelts--;
}

void ArrayList::PrintList()
{
	for (int i = 0; i < nelts; i++) {
		cout << i << " . " << array[i] << endl;
	}
}

double ArrayList::FindKth(int position)
{
	int y;

	for (int i = nelts - 1; i >= position; i--)
	{
		if (i == position) {
			cout << endl;
			cout << array[i];
			cout << endl;

			return array[i];
		}
	}
}

int ArrayList::Replace(double a, double b) {
	for (int i = 0; i < nelts; ++i) {
		if (array[i] == a) {
			array[i] = b;
		}

		return array[i];
	}
}
