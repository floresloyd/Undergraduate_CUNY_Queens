#include <stdio.h>
#include <iostream> 
#include <algorithm> 
#include <unordered_set>

using namespace std;

///======================= ASSOCIATIVE CONTAINERS: SET =======================================
/// Associative Containers: 
/// set, multiset [both O(logn)], unordered_set, unordered_multiset [both expected O(1)]
///

void PrintSet(unordered_multiset<int>& set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

/// -------------------------------------------------
/// Unordered MultiSet Ex
/// 
int main(){
	cout << "unordered_multiset example..." << endl;

	unordered_multiset<int> ums;

	cout << "Insert(4)" << endl;
	ums.insert(4);

	cout << "Insert(3)" << endl;
	ums.insert(3);

	cout << "Insert(7)" << endl;
	ums.insert(7);

	cout << "Insert(1)" << endl;
	ums.insert(1);

	cout << "Insert(9)" << endl;
	ums.insert(9);
	cout << "Number of elements in the set: " << ums.size() << endl;
	PrintSet(ums);

	cout << "Erasing 7..." << endl;
	ums.erase(7);
	PrintSet(ums);

	cout << "Inserting 2..." << endl;
	ums.insert(2);
	PrintSet(ums);

	cout << "Inserting 2 again..." << endl;
	ums.insert(2);
	PrintSet(ums);

	cout << "Inserting 9 again..." << endl;
	ums.insert(9);
	PrintSet(ums);

	cout << "Inserting 9 again..." << endl;
	ums.insert(9);
	PrintSet(ums);

	cout << "-------------------------------------------------" << endl;
} //end-UnorderedMultisetEx

