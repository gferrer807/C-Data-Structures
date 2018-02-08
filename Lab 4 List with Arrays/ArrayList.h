
// Defines a class to manipulate lists that are stored as an array.  Before 2/13/2016
// the program was assuming that the index to the first element of the list was 1. Now
// it is 0 to be consistent with C++.
#pragma once

class ArrayList {

public:
	// The size we use to increment arrays. I use a small increment for testing.
	const static int ArrayIncrement = 2;

	// Constructor to initialize the list.
	ArrayList();

	// Destructor to clean up the list.
	~ArrayList();

	// Empties out the array list structure.
	void MakeEmpty() { nelts = 0; };

	// Tests to see if the array list structure is empty.
	bool isEmpty() { return nelts == 0; };

	// Returns the size of the array.
	int listSize() { return nelts; }

	// Finds a specifies element of the array list. Returns -1 if not found.
	int Find(double y);

	// Inserts an element at a specified position in the array list.
	void Insert(double y, int position);

	// Deletes a specified element in the array list.  ASSIGNED AS LAB
	void Delete(double y);

	// Returns the kth element in the array. Returns 0 if not found.  ASSIGNED AS LAB
	double FindKth(int position);

	// You get this one for free if you implement FindKth.
	double operator[] (int position) { return FindKth(position); }

	// Displays the list.  This is a good debugging aid
	void PrintList();

	int Replace(double a, double b);

private:

	int ArraySize;// Size of the array.
	int nelts; // Number of elements in the array.
	double *array;// Pointer to the array.

				  // Makes sure that there is space for a new element in the list.
	void MakeSpace();
};
