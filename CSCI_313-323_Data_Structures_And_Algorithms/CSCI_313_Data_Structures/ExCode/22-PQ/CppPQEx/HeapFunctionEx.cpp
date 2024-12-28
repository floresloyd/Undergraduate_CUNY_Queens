#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	/// Heap manipulation functions
	/// is_heap			checks if the given range is a max PQ
	/// make_heap		creates a max PQ out of a range of elements
	///	push_heap		adds an element to a max PQ
	///	pop_heap		removes the largest element from a max PQ
	///	sort_heap		turns a max PQ into a range of elements sorted in ascending order

	vector<int> nums = { 5, 2, 7, 8, 3 };
	std::make_heap(nums.begin(), nums.end());
	for (auto num : nums) cout << num << ", "; cout << endl;
	cout << "----------------------------------------------------------" << endl;

	/// Push 9 to the PQ
	cout << "Pushing 9 to the max PQ" << endl;
	nums.push_back(9);
	std::push_heap(nums.begin(), nums.end());
	for (auto num : nums) cout << num << ", "; cout << endl;
	cout << "----------------------------------------------------------" << endl;

	string isHeap = is_heap(nums.begin(), nums.end()) ? "yes" : "no";
	cout << "Is nums a PQ? " << isHeap << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Popping the maximum number from the PQ: " << *nums.begin() << endl;
	std::pop_heap(nums.begin(), nums.end());
	for (auto num : nums) cout << num << ", "; cout << endl;
	cout << "----------------------------------------------------------" << endl;

	// Here is heap sort
	vector<int> nums2 = { 8, 4, 2, 1, 7, 5 };

	cout << "Values before heapsort: ";
	for (auto num : nums2) cout << num << ", "; cout << endl;

	std::make_heap(nums2.begin(), nums2.end());
	for (auto iter = nums2.end(); iter != nums2.begin(); --iter)
		std::pop_heap(nums2.begin(), iter);

	cout << "Values  after heapsort: ";
	for (auto num : nums2) cout << num << ", "; cout << endl;
} // end-main
