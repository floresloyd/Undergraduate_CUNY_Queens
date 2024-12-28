#include <stdio.h>
#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <string> 
#include <vector>
#include <set>

using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.

///======================= ASSOCIATIVE CONTAINERS: SET =======================================
/// Associative Containers: 
/// set, multiset [both O(logn)], unordered_set, unordered_multiset [both expected O(1)]
///

void PrintSet(std::set<int>& set1) {
#if 1
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
#elif 0
	// Forward walk using explicit iterators
	cout << "Set elements: ";
	for (auto iter = set1.begin(); iter != set1.end(); iter++) {
		cout << *iter << ", ";
	} //end-for
	cout << endl;
#elif 0
	// Backward walk using explicit forward iterators & -- operator
	cout << "Set elements in reverse order: ";
	for (auto iter = --set1.end(); iter != set1.end(); iter--) {
		cout << *iter << ", ";
	} //end-for
	cout << endl;
#else
	// Backward walk using explicit reverse iterators
	// Note: reverse iterators are NOT compatible with forward iterators!
	cout << "Set elements in reverse order: ";
	for (auto iter = set1.rbegin(); iter != set1.rend(); iter++) {
		cout << *iter << ", ";
	} //end-for
	cout << endl;
#endif
} //end-PrintSet

void PrintSet(multiset<int>& set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

///-------------------------------------------------
/// OrderedSetEx
/// 
int main() {
	cout << "ordered set example..." << endl;

	set<int> os;

	cout << "Insert(4)" << endl;
	os.insert(4);

	cout << "Insert(3)" << endl;
	os.insert(3);

	cout << "Insert(7)" << endl;
	os.insert(7);

	cout << "Insert(1)" << endl;
	os.insert(1);

	cout << "Insert(9)" << endl;
	os.insert(9);

	cout << "Number of elements in the set: " << os.size() << endl;
	PrintSet(os);

	printf("The min key is: %d\n", *os.begin());
	printf("The max key is: %d\n", *os.rbegin());

	auto iter = os.find(7);
	if (iter != os.end()) {
		printf("The key found is: %d\n", *iter);
		auto prev = iter;
		prev--;
		if (prev != os.end()) printf("Previous key is: %d\n", *prev);

		auto next = iter;
		next++;
		if (next != os.end()) printf("Next key is: %d\n", *next);

	} 
	else                  printf("7 does not exist in the set\n");

	iter = os.find(5);
	if (iter != os.end()) printf("The key found is: %d\n", *iter);
	else                  printf("5 does not exist in the set\n");

	PrintSet(os);
	cout << "Erasing 7..." << endl;
	os.erase(7);
	PrintSet(os);

	cout << "Erasing 3..." << endl;
	iter = os.find(3);
	os.erase(iter);
	PrintSet(os);

	cout << "Inserting 2..." << endl;
	os.insert(2);
	PrintSet(os);

	cout << "Inserting 2 again!" << endl;
	os.insert(2);
	PrintSet(os);
	cout << "--------------------------------------------------" << endl;
} //end-OrderedSetEx

