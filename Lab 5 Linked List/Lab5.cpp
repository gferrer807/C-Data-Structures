#include <iostream>
using namespace std;
#include "LinkedList.h"
int main()
{
	LinkedList x;
	x.Insert(17, NULL);
	x.Insert(35, NULL);
	x.Insert(22, NULL);
	x.Insert(333, NULL);
	x.Insert(34, NULL);
	x.Insert(95, NULL);
	x.Insert(27, NULL);
	x.PrintList();

	cout << endl;
	x.FindKth(4);
	cout << endl;
	x.Replace(27, 999);
	LinkedList::Node *temp;
	LinkedList::Node *cnode = x.Find(35, temp);
	x.Delete(cnode);
	x.PrintList();
}