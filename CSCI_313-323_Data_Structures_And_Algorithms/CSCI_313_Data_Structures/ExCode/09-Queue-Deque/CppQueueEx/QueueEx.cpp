#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	///------------------------ queue ---------------------------------
	cout << "Creating a fifo queue..." << endl;

	queue<int> Q;

	cout << "Enqueue(4)" << endl;
	Q.push(4);

	cout << "Enqueue(3)" << endl;
	Q.push(3);

	cout << "Enqueue(7)" << endl;
	Q.push(7);

	cout << "Enqueue(1)" << endl;
	Q.push(1);

	cout << "Enqueue(9)" << endl;
	Q.push(9);

	cout << "Queue elements should be: <4, 3, 7, 1, 9>" << endl;
	cout << "Number of elements in the queue: " << Q.size() << endl;
	cout << "Element at the front of the queue: " << Q.front() << endl;
	cout << "Removing the front element of the queue." << endl;
	Q.pop();
	cout << "Element at the front of the queue now: " << Q.front() << endl;
	cout << "Is the queue empty? " << (Q.empty() ? "Yes" : "No") << endl;

	cout << "Removing the queue elements in order: ";
	while (!Q.empty()) {
		cout << Q.front() << ", ";
		Q.pop();
	} //end-while
	cout << endl;
	cout << "Is the queue empty? " << (Q.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;

	return 0;
} //end-main

