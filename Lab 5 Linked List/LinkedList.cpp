// Functions to support list operations on an array.
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;


// Tests to see if the linked list structure is empty.
bool LinkedList::isEmpty()
{
	return head == NULL;
}

// Empties out the linked list structure.  This is certainlymore difficult than the
// ArrayList implementation. 
void LinkedList::MakeEmpty()
{
	Node *cnode = head; // Points to the node we are processing.
	Node *nnode = NULL; // Points to next node
						// Scan through the list freeing all the nodes.
	for (; cnode != NULL; cnode = nnode) {
		nnode = cnode->next;
		delete cnode;
	}
	head = NULL;
}

// Finds a specifies element of the linked list. Returns NULL if not found.
LinkedList::Node *LinkedList::Find(double y, Node *&PreNode)
{
	Node *cnode = head;
	Node *pnode = NULL;
	// Search each element of the linked list for y.
	for (; cnode != NULL; pnode = cnode, cnode = cnode->next) {
		if (cnode->value == y) {
			PreNode = pnode;
			return cnode;
		}
	}
	// Node not found.
	return NULL;
}

// Inserts an element at a specified position in the linked list.
void LinkedList::Insert(double y, Node *PrePosition)
{
	Node *tmp = new Node; // The new node to be added.

						  // Record y in the new node.
	tmp->value = y;

	// If this new node is at the head, treat this as a special case.
	if (PrePosition == NULL) {
		tmp->next = head;
		head = tmp;
		return;
	}
	// We are adding the new node after the head.
	tmp->next = PrePosition->next;
	PrePosition->next = tmp;
	return;
}
// Displays the list.
void LinkedList::PrintList()
{
	int ill = 0; // Position in linked list.

				 // Display the list.
	for (Node *cnode = head; cnode != NULL; cnode = cnode->next) {
		cout << ill++ << ". " << cnode->value << endl;
	}
}

void LinkedList::Delete(Node *PrePosition) {

	Node *headnode = head;
	Node *temp = NULL;
	
	if (PrePosition == NULL) {
		temp = headnode->next;
		delete headnode;
		head = temp;
		return;
	}
	
	temp = PrePosition->next;
	PrePosition->next = temp->next;
	delete temp;
}

double LinkedList::FindKth(int position) {
	Node *cnode = head;

	for (int i = 1; i<position; i++)
	{
		cnode = cnode->next;
	}
	cout << cnode->value;
	cout << endl;
	return cnode->value;
}

int LinkedList::Replace(double x, double y) {
	for (Node *cnode = head; cnode != NULL; cnode = cnode->next) {
		if (cnode->value == x) {
			cnode->value = y;
			return cnode->value;
		}
	}
	return -1;
}
