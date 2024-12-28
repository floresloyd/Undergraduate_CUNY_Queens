#include <stdio.h>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// For random number generation in the range [0.0-1.0]
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dist(0.0, 1.0);

///-------------------------------------------------
/// Prints the elements of the array on the screen
///
static void PrintVector(vector<int>& nums) {
	printf("nums=[");

	for (auto num : nums)
		printf("%d, ", num);

	printf("\b\b]\n");
} //end-PrintVector

///--------------------------------------------------------
/// Swaps two integers
///
void inline Swap(int& a, int& b) {
	// If a & b are the same memory slot, nothing to swap. Just return
	// Without this check, xor based code will NOT work, 
	// because when a & b are the same memory slot, the xor will make the value 0!
	if (&a == &b) return;
#if 0
	// Swap using extra memory
	int tmp = a;
	a = b;
	b = tmp;
#else	
	// Swap using xor
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
#endif
} //end-Swap

///--------------------------------------------------------
/// Partition w/o extra space
///
int RandomizedPartition(vector<int> &nums, int left, int right) {
	if (left >= right) return 0;
	
	int randomIndex = left + (right-left)*dist(gen); // a random index in [left, right]
	Swap(nums[left], nums[randomIndex]);  // Bring the pivot to nums[left]
	int pivot = nums[left]; 
	int i = left+1, j = right;

	while (true) {
		while (nums[i] < pivot && i < j) i++;  // Move i
		while (nums[j] > pivot) j--;           // Move j

		// Are we done?					
		if (i >= j) break;

		// Swap nums[i] and nums[j]
		Swap(nums[i], nums[j]);

		i++; j--;
	} //end-while

	// Restore the pivot
	nums[left] = nums[j];
	nums[j] = pivot;

	return j;  // return the index of the pivot
} //end-RandomizedPartition

///---------------------------------------------------------------------
/// Returns the kth smalles element. Assumes 0 <= k <= N-1
///
class IllegalArgumentException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Argument Exception!";
    }
};

int SelectAux(vector<int> &nums, int left, int right, int k){
	if (left == right) return nums[left];

	int q = RandomizedPartition(nums, left, right);
	if (k == q) return nums[q];
	if (k < q) return SelectAux(nums, left, q-1, k);
	return SelectAux(nums, q+1, right, k);
} // end-SelectAux

int Select(vector<int> &nums, int k) {
	if (k < 0 or k >= nums.size()) throw IllegalArgumentException();
	return SelectAux(nums, 0, nums.size()-1, k);
} //end-Select

///---------------------------------------------------
/// Select using std::partition
///
int SelectAux2(std::vector<int>::iterator left, std::vector<int>::iterator right, int k){
	int n = std::distance(left, right);
	if (n == 1) return *left;

    // Generate a random number in [left, right)
	auto randomIter = left + (n-1)*dist(gen); // a random index in [left, right)
	int pivot = *randomIter;
	auto iter1 = std::partition(left, right, [pivot](int num){return num < pivot;});	
	auto iter2 = std::partition(iter1, right, [pivot](int num){return num == pivot;}); // Bring the pivot to nums[q]

	// All values in [iter1, iter2) are equal to the pivot
	int q1 = std::distance(left, iter1);
	int q2 = std::distance(left, iter2);
	if (q1 <= k and k < q2) return *iter1;

	// Recurse on the left hand side
	if (k < q1) return SelectAux2(left, iter1, k);

	// Recurse on the right hand side
	// We are now eliminating q2 elements. So, need to subtract that from k
	return SelectAux2(iter2, right, k-q2);
} // end-SelectAux2

int Select2(vector<int> &nums, int k) {
	if (k < 0 or k >= nums.size()) throw IllegalArgumentException();
	return SelectAux2(nums.begin(), nums.end(), k);
} // end-Select2

///---------------------------------------------------
/// main
/// 
int TestSelect1(int k){
	vector<int> nums = { 42, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };
	return Select(nums, k);
} // end-TestSelect1

int TestSelect2(int k){
	vector<int> nums = { 42, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };
	return Select2(nums, k);
} // end-TestSelect2

int main() {
	vector<int> nums = { 42, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };
	PrintVector(nums);

	for (int k = 0; k < nums.size(); k++) {
		printf("%dth smallest element is: %d, %d\n", k, TestSelect1(k), TestSelect2(k));
	} //end-for

	printf("\n\n");
} // end-main

