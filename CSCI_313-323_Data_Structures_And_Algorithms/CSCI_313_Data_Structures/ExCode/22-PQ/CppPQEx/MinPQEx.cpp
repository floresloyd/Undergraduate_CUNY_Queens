#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main(){
	cout << "Creating a min-PQ" << endl;
#if 1
	auto cmp = [](int left, int right) { return (left >= right); };
	std::priority_queue<int, std::vector<int>, decltype(cmp)> H2(cmp);
#else
	// Alternatively, you can use standard template classes less & greater to create a max/min PQ
	// This is only possible after C++17
	std::priority_queue<int, std::vector<int>, std::greater<int>> H2;
#endif

	cout << "Insert(4)" << endl;
	H2.push(4);

	cout << "Insert(3)" << endl;
	H2.push(3);

	cout << "Insert(7)" << endl;
	H2.push(7);

	cout << "Insert(1)" << endl;
	H2.push(1);

	cout << "Insert(9)" << endl;
	H2.push(9);
	cout << "Number of elements in the PQ: " << H2.size() << endl;
	cout << "Element at the top of the PQ: " << H2.top() << endl;
	cout << "Removing the top element of the PQ." << endl;
	H2.pop();
	cout << "Element at the top of the PQ now: " << H2.top() << endl;
	cout << "Is the PQ empty? " << (H2.empty() ? "Yes" : "No") << endl;

	cout << "Removing the PQ elements in order: ";
	while (!H2.empty()) {
		cout << H2.top() << ", ";
		H2.pop();
	} //end-while
	cout << endl;
	cout << "Is the PQ empty? " << (H2.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
} // end-main
