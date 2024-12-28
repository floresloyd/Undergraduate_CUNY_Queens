#include <stdio.h>
#include <iostream> 
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 
#include <vector>
#include <set>

using namespace std;

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

/// --------------------------------------------------
/// Ordered multiset
/// 
int main() {
	cout << "ordered multiset example..." << endl;
	multiset<int> oms;

	cout << "Insert(4)" << endl;
	oms.insert(4);

	cout << "Insert(3)" << endl;
	oms.insert(3);

	cout << "Insert(7)" << endl;
	oms.insert(7);

	cout << "Insert(1)" << endl;
	oms.insert(1);

	cout << "Insert(9)" << endl;
	oms.insert(9);

	cout << "Number of elements in the set: " << oms.size() << endl;
	PrintSet(oms);

	cout << "Erasing 7..." << endl;
	oms.erase(7);
	PrintSet(oms);

	cout << "Inserting 2..." << endl;
	oms.insert(2);
	PrintSet(oms);

	cout << "Inserting 2 again..." << endl;
	oms.insert(2);
	PrintSet(oms);

	cout << "Inserting 9 again..." << endl;
	oms.insert(9);
	PrintSet(oms);

	cout << "Inserting 9 again..." << endl;
	oms.insert(9);
	PrintSet(oms);
	cout << "---------------------------------------------------" << endl;
} // end-main

