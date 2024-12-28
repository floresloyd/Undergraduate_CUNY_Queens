#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <string> 
#include <vector>
#include <map>

using namespace std; 

///================ ASSOCIATIVE CONTAINERS: MAP ==================================
/// Associative Containers: map, multimap [both O(logn)], 
/// unordered_map, unordered_multimap [both expected O(1)]

void PrintMap(map<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

void PrintMap(multimap<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

///---------------------------------------------------
/// OrderedMultimapEx
/// 
int main(){
	cout << "ordered multimap example..." << endl;

	multimap<int, string> omm;

	cout << "Insert(4, Ali)" << endl;
	omm.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	omm.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	omm.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	omm.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	omm.insert({ 9, "Cem" });  // {} is the same as make_pair

	cout << "Number of elements in the set: " << omm.size() << endl;
	PrintMap(omm);

	cout << "Erasing 7..." << endl;
	omm.erase(7);
	PrintMap(omm);

	cout << "Inserting (2, Hasan)..." << endl;
	omm.insert(make_pair(2, "Hasan"));
	PrintMap(omm);

	cout << "Inserting (2, Huseyin)..." << endl;
	omm.insert(make_pair(2, "Huseyin"));
	PrintMap(omm);

	cout << "Inserting (9, Oya)..." << endl;
	omm.insert(make_pair(9, "Oya"));
	PrintMap(omm);

	cout << "Inserting (9, Kadir)..." << endl;
	omm.insert(make_pair(9, "Kadir"));
	PrintMap(omm);

	cout << "Looking for 2: ";
	for (auto it = omm.find(2); it != omm.end(); it++) {
		if (it->first != 2) break;
		cout << "[2, " << it->second << "], ";
	} //end-for
	cout << endl;

	cout << "-----------------------------------------------------" << endl;
} // end-main
