#include <iostream>

using namespace std;

int main()
{
	//variables and pointer
  int q;
  int smallest = INT_MAX;
  int capacity = 2;
  int count = 0;
	int *x = new int[capacity];

	while (q != -1){
		cout << "Enter an integer (Indicate you are done with -1): ";
		cin >> q;

		if (count == capacity)
		{
			int *tmp = x;
			x = new int[capacity + 2];
			for (int size = 0; size < count; size++)
			{
				x[size] = tmp[size];
			}
			delete[] tmp;
			tmp = NULL;
		}
		x[count] = q;
		if (smallest > x[count] && x[count] != -1) smallest = x[count];
		count++;
	};

	cout << endl;

	for(int size = 0; size < (count-1); size++)
	{
    	cout << "The difference between " << x[size];
    	cout << " and the smallest integer " << smallest << " is: ";
    	cout << x[size] - smallest << endl;
	}
	return 0;
}
