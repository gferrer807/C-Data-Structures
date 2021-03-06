
// To test the implementation of the ADT list using linked lists
#include <iostream>
#include "DLinkedList.h"
using namespace std;

int main()
{
	DLinkedList aaa;

	// Insert a lot of stuff;
	aaa.Insert(111, NULL);
	aaa.Insert(222, NULL);
	aaa.PrintList();
	cout << endl;

	aaa.Insert(333, NULL);
	aaa.Insert(444, NULL);

	DLinkedList::DLLNode *npt = aaa.Find(444);
	aaa.Insert(555, NULL);
	aaa.PrintList();
	
	aaa.FindKth(3);
	aaa.Delete(npt);
	cout << endl;
	aaa.PrintList();
	cout << endl;
	aaa.reversePrintList();
	aaa.appendList(999);
	cout << endl;
	aaa.reversePrintList();
}