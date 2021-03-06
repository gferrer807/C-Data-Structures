#include <iostream>

using namespace std;

template <typename T>
int find(T array[], int size, T key)
{
	int middle;
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		middle = (low + high)/2;

		if (key == array[middle])
		{
			return middle;
		}
		else if (key > array[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}

	return -1;

}

int main()
{
	int a[] = { 17, 18, 24, 44, 49, 56, 73, 99 };

	int num;

	cout << "Enter a number to find: " << endl;
	cin >> num;

	int key = find(a, 8, num);

	if (key >= 0)
	{
		cout << "The number " << a[key] << " was found at " << key << endl;
	}
	else
	{
		cout << "The number " << num << " was not found. " << endl;
	}
}