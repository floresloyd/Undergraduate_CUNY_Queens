#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

void print(std::vector<int>& list);

int main() {
	try {
		std::vector<int> list;

		printf("Appending 5 to the list. \n");
		list.push_back(5);       // [5]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Appending 6 to the list. \n");
		list.push_back(6);       // [5, 6]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Appending 1 to the list. \n");
		list.push_back(1);       // [5, 6, 1]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Appending 9 to the list. \n");
		list.push_back(9);       // [5, 6, 1, 9]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Appending 15 to the list. \n");
		list.push_back(15);      // [5, 6, 1, 9, 15]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Appending 3 to the list. \n");
		list.push_back(3);       // [5, 6, 1, 9, 15, 3]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Adding 7 to index 2. \n");
		list.insert(list.begin()+2, 7);    // [5, 6, 7, 1, 9, 15, 3]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Adding 4 to index 4. \n");
		list.insert(list.begin()+4, 4);    // [5, 6, 7, 1, 4, 9, 15, 3]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Setting the item at index 3 to 20. \n");
		list[3] = 20;    // [5, 6, 7, 20, 4, 9, 15, 3]
		print(list);
		printf("--------------------------------------------------\n");

		printf("Deleting the item at index 3...\n");
		list.erase(list.begin()+3);
		print(list);
		printf("--------------------------------------------------\n");

		printf("Get an iterator to %d\n", *std::find(list.begin(), list.end(), 15));
		printf("--------------------------------------------------\n");

		printf("Appending 6 to the list\n");
		list.push_back(6);
		print(list);
		printf("--------------------------------------------------\n");

		printf("Get an iterator to %d\n", *std::find(list.begin(), list.end(), 6));
		printf("--------------------------------------------------\n");

		printf("Removing 15 from the list\n");
		list.erase(std::find(list.begin(), list.end(), 15));
		print(list);
		printf("--------------------------------------------------\n");

		printf("Is the list empty? %s\n", (list.empty() ? "Yes" : "No"));
		printf("Deleting all items from the list...\n");
		list.clear();
		printf("Is the list empty now? %s\n", (list.empty() ? "Yes" : "No"));
		print(list);
		printf("--------------------------------------------------\n");

		printf("Trying to access index 4: ");
		printf("Item at index 4 is: %d\n", list.at(4));
		printf("--------------------------------------------------\n");

	} catch (std::exception const& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
	} //end-catch
} //end-main

void print(std::vector<int> &list) {
	printf("The list has %d items: [", (int)list.size());

	for (auto iter: list){
		printf("%d, ", iter);
	} // end-while

	if (list.size() != 0) printf("\b\b");
	printf("]\n");
} //end-print

