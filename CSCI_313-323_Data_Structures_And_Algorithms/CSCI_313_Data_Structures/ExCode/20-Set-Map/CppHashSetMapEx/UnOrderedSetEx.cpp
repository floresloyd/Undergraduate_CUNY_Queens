#include <stdio.h>
#include <iostream> 
#include <algorithm> 
#include <unordered_set>

using namespace std;  

///======================= ASSOCIATIVE CONTAINERS: SET =======================================
/// Associative Containers: 
/// set, multiset [both O(logn)], unordered_set, unordered_multiset [both expected O(1)]
///

void PrintSet(std::unordered_set<int>& set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

/// -------------------------------------------------
/// UnorderedSet Ex
/// 
int main() {
	cout << "unordered_set example..." << endl;

	unordered_set<int> uos;

	cout << "Insert(4)" << endl;
	uos.insert(4);

	cout << "Insert(3)" << endl;
	uos.insert(3);

	cout << "Insert(7)" << endl;
	uos.insert(7);

	cout << "Insert(1)" << endl;
	uos.insert(1);

	cout << "Insert(9)" << endl;
	uos.insert(9);

	cout << "Number of elements in the set: " << uos.size() << endl;
	PrintSet(uos);

	cout << "Erasing 7..." << endl;
	uos.erase(7);
	PrintSet(uos);

	cout << "Inserting 2..." << endl;
	uos.insert(2);
	PrintSet(uos);

	cout << "Inserting 2 again!" << endl;
	uos.insert(2);
	PrintSet(uos);
	cout << "---------------------------------------------------" << endl;
} // end-UnorderedSetEx
