#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <string> 
#include <vector>
#include <unordered_map>

using namespace std;

void PrintMap(unordered_multimap<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap


///---------------------------------------------------
/// UnorderedMultimapEx
/// 
int main(){
	cout << "unordered multimap example..." << endl;

	unordered_multimap<int, string> umm;

	cout << "Insert(4, Ali)" << endl;
	umm.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	umm.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	umm.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	umm.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	umm.insert({ 9, "Cem" });  // {} is the same as make_pair

	cout << "Number of elements in the set: " << umm.size() << endl;
	PrintMap(umm);

	cout << "Erasing 7..." << endl;
	umm.erase(7);
	PrintMap(umm);

	cout << "Inserting (2, Hasan)..." << endl;
	umm.insert(make_pair(2, "Hasan"));
	PrintMap(umm);

	cout << "Inserting (2, Huseyin)..." << endl;
	umm.insert(make_pair(2, "Huseyin"));
	PrintMap(umm);

	cout << "Inserting (9, Oya)..." << endl;
	umm.insert(make_pair(9, "Oya"));
	PrintMap(umm);

	cout << "Inserting (9, Kadir)..." << endl;
	umm.insert(make_pair(9, "Kadir"));
	PrintMap(umm);

	cout << "Looking for 9: ";
	for (auto it = umm.find(9); it != umm.end(); it++) {
		if (it->first != 9) break;
		cout << "[9, " << it->second << "], ";
	} //end-for
	cout << endl;
} //end-UnorderedMultipmapEx
