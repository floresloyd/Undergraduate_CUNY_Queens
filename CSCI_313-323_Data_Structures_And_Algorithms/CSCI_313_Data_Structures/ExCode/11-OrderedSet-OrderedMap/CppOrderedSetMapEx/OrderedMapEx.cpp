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

/// ----------------------------------------------------------------
/// OrderedMapEx
/// 
int main(){
	cout << "ordered map example..." << endl;

	map<int, string> om;

	cout << "Insert(4, Ali)" << endl;
	om.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	om.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	om.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	om.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	om.insert(make_pair(9, "Cem"));

	cout << "Number of elements in the map: " << om.size() << endl;
	PrintMap(om);

	printf("The min key/value is: <%d, %s>\n", om.begin()->first, om.begin()->second.c_str());
	printf("The min key/value is: <%d, %s>\n", om.rbegin()->first, om.rbegin()->second.c_str());

	auto iter = om.find(7);
	printf("Found <%d, %s>\n", iter->first, iter->second.c_str());

	auto prev = iter; prev--;
	printf("Previous key/value pair: <%d, %s>\n", prev->first, prev->second.c_str());

	auto next = iter; next++;
	printf("Next key/value pair: <%d, %s>\n", next->first, next->second.c_str());

	cout << "Erasing 7..." << endl;
	om.erase(7);
	PrintMap(om);

	cout << "Inserting (2, Hasan)..." << endl;
	om.insert(make_pair(2, "Hasan"));
	PrintMap(om);

	cout << "Inserting (2, Huseyin)!" << endl;
	om.insert(make_pair(2, "Huseyin"));
	PrintMap(om);

	cout << "Does the map contain 1? ";
	auto it = om.find(1);
	if (it == om.end()) cout << "No" << endl;
	else                cout << "Yes. [1, " << it->second << "]" << endl;

	cout << "--------------------------------------------------------" << endl;
} //end-main
