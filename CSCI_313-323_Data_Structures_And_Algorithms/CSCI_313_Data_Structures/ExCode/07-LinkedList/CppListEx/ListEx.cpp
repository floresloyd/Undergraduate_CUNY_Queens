#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void PrintList(list<int>& list);

int main() {
	try {
		std::list<int> list;

		printf("Appending 5 to the list. \n");
		list.push_back(5);       // [5]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Appending 6 to the list. \n");
		list.push_back(6);       // [5, 6]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Appending 1 to the list. \n");
		list.push_back(1);       // [5, 6, 1]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Appending 9 to the list. \n");
		list.push_back(9);       // [5, 6, 1, 9]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Appending 15 to the list. \n");
		list.push_back(15);      // [5, 6, 1, 9, 15]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Appending 3 to the list. \n");
		list.push_back(3);       // [5, 6, 1, 9, 15, 3]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Adding 7 to index 2. \n");
		auto iter = list.begin(); // Points to the first node in the list
		iter++;  // Points to the node with index == 1
		iter++;  // Points to the node with index == 2
		list.insert(iter, 7);    // [5, 6, 7, 1, 9, 15, 3]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Adding 4 to index 4. \n");
		iter = list.begin();  // Points to the first node
		iter++; // Points to the node with index == 1
		iter++; // Points to the node with index == 2
		iter++; // Points to the node with index == 3
		iter++; // Points to the node with index == 4
		list.insert(iter, 4);    // [5, 6, 7, 1, 4, 9, 15, 3]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Setting the item at index 3 to 20. \n");
		iter = list.begin();
		iter++; iter++; iter++;  // Points to the node with index == 3
		*iter = 20;    // [5, 6, 7, 20, 4, 9, 15, 3]
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Removing the item at index 3...\n");
		iter = list.begin();
		iter++;
		iter++;
		iter++;
		list.erase(iter);
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Removing the first item...\n");
		list.erase(list.begin());
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Removing the last item ...\n");
		list.erase(--list.end());
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Get an iterator to %d\n", *std::find(list.begin(), list.end(), 15));
		printf("--------------------------------------------------\n");

		printf("Appending 6 to the list\n");
		list.push_back(6);
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Get an iterator to %d\n", *std::find(list.begin(), list.end(), 6));
		printf("--------------------------------------------------\n");

		printf("Removing 15 from the list\n");
		list.erase(std::find(list.begin(), list.end(), 15));
		PrintList(list);
		printf("--------------------------------------------------\n");

		printf("Is the list empty? %s\n", (list.empty() ? "Yes" : "No"));
		printf("Deleting all items from the list...\n");
		list.clear();
		printf("Is the list empty now? %s\n", (list.empty() ? "Yes" : "No"));
		PrintList(list);
		printf("--------------------------------------------------\n");

	} catch (std::exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
	} //end-catch
} //end-main

void PrintList(list<int> &list) {
	printf("The list has %d items: [", (int)list.size());

	for (auto iter: list){
		printf("%d, ", iter);
	} // end-while

	if (list.size() != 0) printf("\b\b");
	printf("]\n");
} //end-PrintList

