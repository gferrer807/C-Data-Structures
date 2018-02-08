//Name: Giancarlo Ferrer
//Assignment: Lab 1
//Due Date: 9.28.17
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
	int smallest = INT_MAX;

	//ask user to set array size
	cout << "How many integers will you input: ";
	do {
    	cin >> n;
	} while (n < 0);

	//declare new dynamic array
	int *x = new int[n];

	for(int count = 0; count < n; count++)
	{
    	cout << "Enter an integer: ";
    	cin >> x[count];
    	if (smallest > x[count]) smallest = x[count];
	}

	for(int count = 0; count < n; count++)
	{
    	cout << "The difference between " << x[count];
    	cout << " and the smallest integer " << smallest << " is: ";
    	cout << x[count] - smallest << endl;
	}
	return 0;
}
