#pragma once
#include <iostream>
#include <string>
using namespace std;


class RCQueue_LL
{
public:
	struct RCQueue {
		string value;
		RCQueue *nextnode;
		RCQueue *prevnode;
	};
	RCQueue_LL() {
		head = NULL;
		tail = NULL;
	};
	void Enqueue(string x);
	string dequeue();
	void display();
	void MakeEmpty();
	~RCQueue_LL() {
		MakeEmpty();
	};
private:
	RCQueue *head;
	RCQueue *tail;
};

