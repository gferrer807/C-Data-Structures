// Functions to support list operations on an array.
#include <iostream>
#include <string>
#include "DLinkedList.h"
using namespace std;


// Tests to see if the linked list structure is empty.
bool DLinkedList::isEmpty()
{
	return head == NULL;
}

// Empties out the linked list structure.
void DLinkedList::MakeEmpty()
{
	DLLNode *cnode = head; // Points to the node we are processing.
	DLLNode *nnode = NULL; // Points to next node

						   // Scan through the list freeing all the nodes.
	for (; cnode != NULL; cnode = nnode) {
		nnode = cnode->nextnode;
		delete cnode;
	}
	head = NULL;
	tail = NULL;
}

// Finds a specifies element of the linked list. Returns NULL if not found.
DLinkedList::DLLNode *DLinkedList::Find(double y)
{
	DLLNode *cnode = head;

	// Search each element of the linked list for y.
	for (; cnode != NULL; cnode = cnode->nextnode) {

		if (cnode->value == y) {
			return cnode;
		}
	}
	// Node not found.
	return NULL;
}

// Inserts an element at a specified position in the linked list.
void DLinkedList::Insert(double y, DLLNode *PrePosition)
{
	DLLNode *tmp = new DLLNode; // The new node to be added.

								// Record y in the new node.
	tmp->value = y;
	tmp->nextnode = NULL;
	tmp->prenode = NULL;

	// Update the tail if we are adding to the tail.
	if (tail == PrePosition) {

		tail = tmp;
	}
	// If this new node is at the head, treat this as a special case.
	if (PrePosition == NULL) {
		tmp->nextnode = head;

		if (head != NULL) {

			head->prenode = tmp;
		}
		head = tmp;
		return;
	}
	// We are adding the new node after the head.
	DLLNode *nextPrePos = PrePosition->nextnode;
	tmp->nextnode = nextPrePos;
	tmp->prenode = PrePosition;

	PrePosition->nextnode = tmp;
	if (nextPrePos != NULL) {

		nextPrePos->prenode = tmp;
	}
}
// Displays the list.
void DLinkedList::PrintList()
{
	int ill = 1; // Position in linked list.

				 // Display the list.
	for (DLLNode *cnode = head; cnode != NULL; cnode = cnode->nextnode) {
		cout << ill++ << ". " << cnode->value << endl;
	}
}

double DLinkedList::FindKth(int position) {
	{
		DLLNode *cnode = head;

		for (int i = 1; i<position; i++)
		{
			cnode = cnode->nextnode;
		}
		cout << endl;
		cout << cnode->value;
		cout << endl;
		return cnode->value;
	}
}

void DLinkedList::reversePrintList() {
	int ill = 1;
	DLLNode *ptr = tail;
	while (ptr != NULL) {
		cout << ill++ << ". " << ptr->value << endl;
		ptr = ptr->prenode;
	}
}

void DLinkedList::Delete(DLLNode *Position) {
	DLLNode *cnode = head;
	DLLNode *snode = tail;
	DLLNode *newNode = NULL;
	if (Position->nextnode == NULL && Position->prenode == NULL) {
		delete cnode;
		head = tail;
		tail = NULL;
		return;
	} else if (Position->prenode == NULL) {
		newNode = cnode->nextnode;
		delete cnode;
		newNode->prenode = NULL;
		head = newNode;
		return;
	} else if (Position->nextnode == NULL) {
		newNode = snode->prenode;
		delete snode;
		newNode->nextnode = NULL;
		tail = newNode;
		return;
	}
	newNode = Position;
	cnode = Position->prenode;
	snode = Position->nextnode;
	cnode->nextnode = snode;
	snode->prenode = cnode;
	delete Position;
}

void DLinkedList::appendList(double x)
{
	DLLNode	*anode = new DLLNode;

	anode->value = x;
	anode->nextnode = NULL;
	anode->prenode = NULL;

	if (tail == NULL){
		head = tail;
		tail = anode;
	} else{
		tail->nextnode = anode;
		anode->prenode = tail;
		tail = anode;
	}
}
