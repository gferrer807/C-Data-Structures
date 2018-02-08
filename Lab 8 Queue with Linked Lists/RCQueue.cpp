#include "RCQueue.h"

void RCQueue_LL::Enqueue(string x) {
	RCQueue *temp = new RCQueue;
	RCQueue *prev;
	temp->value = x;
	temp->nextnode = NULL;
	if (head == NULL) {
		head = temp;
		tail = temp;
	} else {
		prev = tail;
		tail->nextnode = temp;
		tail = temp;
	}
}

string RCQueue_LL::dequeue()
{
	RCQueue *temp1 = head;
	RCQueue *temp2 = NULL;
	if (temp1 == NULL) {
		return " ";
	}else if (temp1->nextnode == NULL) {
		temp1 = tail;
		tail = NULL;
		return "Queue is now empty";
	}else {
		temp2 = head;
		head = head->nextnode;
		string deleted = temp2->value;
		delete temp2;
		return deleted;
	}
}


void RCQueue_LL::display()
{
	RCQueue *temp = new RCQueue;
	if (head != NULL) {
		for (temp = head; temp != NULL; temp = temp->nextnode)
			cout << temp->value << " ";
		cout << endl;
	} else {
		cout << "Queue is Empty!" << endl;
	}
};

void RCQueue_LL::MakeEmpty()
{
	RCQueue *cnode = head; // Points to the node we are processing.
	RCQueue *nnode = NULL; // Points to next node

						   // Scan through the list freeing all the nodes.
	for (; cnode != NULL; cnode = nnode) {
		nnode = cnode->nextnode;
		delete cnode;
	}
	head = NULL;
	tail = NULL;
}
