#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main() {
	///------------------------ queue ---------------------------------
	cout << "Creating a deque..." << endl;

	deque<int> dq;

	cout << "push_back(4)" << endl;
	dq.push_back(4);                      // 4

	cout << "push_back(3)" << endl;
	dq.push_back(3);                      // 4, 3

	cout << "push_front(7)" << endl;
	dq.push_front(7);                     // 7, 4, 3

	cout << "push_front(1)" << endl;
	dq.push_front(1);                    // 1, 7, 4, 3

	cout << "push_front(9)" << endl;
	dq.push_front(9);                    // 9, 1, 7, 4, 3

	cout << "Deque elements should be: <9, 1, 7, 4, 3>\n";
	cout << "Number of elements in the deque: " << dq.size() << endl;
	cout << "Element at the front of the deque: " << dq.front() << endl;
	cout << "Element at the end of the deque: " << dq.back() << endl;
	cout << "Removing the front element of the deque." << endl;
	dq.pop_front();
	cout << "Element at the front of the deque now: " << dq.front() << endl;
	cout << "Removing the last element of the deque." << endl;
	dq.pop_back();
	cout << "Element at the end of the deque now: " << dq.back() << endl;
	cout << "Is the queue empty? " << (dq.empty() ? "Yes" : "No") << endl;

	cout << "Removing the deque elements in order: ";
	while (!dq.empty()) {
		cout << dq.front() << ", ";
		dq.pop_front();
	} //end-while
	cout << endl;
	cout << "Is the deque empty? " << (dq.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;

	return 0;
} //end-main

