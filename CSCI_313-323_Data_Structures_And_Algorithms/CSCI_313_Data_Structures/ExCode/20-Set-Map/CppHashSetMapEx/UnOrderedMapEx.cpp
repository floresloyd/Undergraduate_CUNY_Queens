#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <string> 
#include <vector>
#include <unordered_map>

using namespace std;

void PrintMap(unordered_map<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

///---------------------------------------------------
/// UnorderedMapEx
/// 
int main() {
	cout << "unordered map example..." << endl;

	unordered_map<int, string> uom;

	cout << "Insert(4, Ali)" << endl;
	uom.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	uom.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	uom.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	uom.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	uom.insert(make_pair(9, "Cem"));

	cout << "Number of elements in the map: " << uom.size() << endl;
	PrintMap(uom);

	cout << "Erasing 7..." << endl;
	uom.erase(7);
	PrintMap(uom);

	cout << "Inserting (2, Hasan)..." << endl;
	uom.insert(make_pair(2, "Hasan"));
	PrintMap(uom);

	cout << "Inserting (2, Huseyin)!" << endl;
	uom.insert(make_pair(2, "Huseyin"));
	PrintMap(uom);

	cout << "Does the map contain 1? ";
	auto it3 = uom.find(1);
	if (it3 == uom.end()) cout << "No" << endl;
	else                  cout << "Yes. [1, " << it3->second << "]" << endl;

	cout << "-------------------------------------------------------" << endl;
} // end-UnorderedMapEx

