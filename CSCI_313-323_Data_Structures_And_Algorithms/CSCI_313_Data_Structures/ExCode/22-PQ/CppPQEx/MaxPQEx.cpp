#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main(){
	cout << "Creating a max-PQ..." << endl;
	priority_queue<int> H;

	cout << "Insert(4)" << endl;
	H.push(4);

	cout << "Insert(3)" << endl;
	H.push(3);

	cout << "Insert(7)" << endl;
	H.push(7);

	cout << "Insert(1)" << endl;
	H.push(1);

	cout << "Insert(9)" << endl;
	H.push(9);
	cout << "Number of elements in the PQ: " << H.size() << endl;
	cout << "Element at the top of the PQ: " << H.top() << endl;
	cout << "Removing the top element of the PQ." << endl;
	H.pop();
	cout << "Element at the top of the PQ now: " << H.top() << endl;
	cout << "Is the PQ empty? " << (H.empty() ? "Yes" : "No") << endl;

	cout << "Removing the PQ elements in order: ";
	while (!H.empty()) {
		cout << H.top() << ", ";
		H.pop();
	} //end-while
	cout << endl;
	cout << "Is the PQ empty? " << (H.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
} // end-main
