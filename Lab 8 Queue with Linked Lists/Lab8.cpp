#include <iostream>
#include <string>
#include "RCQueue.h"

using namespace std;

int main() {
	RCQueue_LL q;
	q.display();
	q.Enqueue("Aye");
	q.display();
	q.Enqueue("My");
	q.display();
	q.Enqueue("Man");
	q.display();
	q.dequeue();
	q.display();
	return 0;
}

