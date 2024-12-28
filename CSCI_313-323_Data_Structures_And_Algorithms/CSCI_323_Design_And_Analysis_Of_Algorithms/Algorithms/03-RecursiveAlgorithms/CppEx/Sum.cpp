#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

///-----------------------------------------------------
/// O(N) recursive algorithm to compute 1+2+..+N
///  
int Sum1(int n) {
	/* Base case */
	if (n == 1) return 1;

	/* Divide and conquer */
	int partialSum = Sum1(n - 1);

	/* Merge */
	return partialSum + n;
} /* end-Sum1 */

///-----------------------------------------------------
/// O(N) recursive algorithm to compute A[0] + A[1] + .. + A[N-1]
/// The recursion depth of this code is O(N), which is NOT good!
///  
int Sum2(vector<int> &nums, int N) {
	if (N == 0) return 0;
	if (N == 1) return nums[0];

	/* Divide & Conquer */
	int localSum = Sum2(nums, N - 1);

	/* Merge */
	return localSum + nums[N - 1];
} /* end-Sum2 */

///-----------------------------------------------------
/// O(N) recursive algorithm to compute A[0] + A[1] + .. + A[N-1]
/// The recursion depth of this code is O(logN), which is good
///  
int Sum3(vector<int>& nums, int left, int right) {
	if (left > right) return 0;
	if (left == right) return nums[left];

	int middle = (left + right) / 2;
	return Sum3(nums, left, middle) + Sum3(nums, middle+1, right);
} // end-Sum3

int main(){
	printf("1+2+3+4 = %d\n", Sum1(4));

	vector<int> nums = { 3, 1, 6, 5, 8, 2, 4, 7 }; // sum: 3+1+6+5+8+2+4+7 = 36
	int sum = Sum2(nums, nums.size());
	printf("The sum of the numbers in the array: %d\n", sum);

	sum = Sum3(nums, 0, nums.size()-1);
	printf("The sum of the numbers in the array: %d\n", sum);

	return 0;
} // end-main

