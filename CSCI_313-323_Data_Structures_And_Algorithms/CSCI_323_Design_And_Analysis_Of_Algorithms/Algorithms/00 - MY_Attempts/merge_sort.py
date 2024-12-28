from typing import List 

class Solution:
    def mergeSort(self, nums, left, right):
        # The mergeSort function is a recursive sorting algorithm that sorts the 'nums' list
        # within the specified range [left, right].
        if left >= right:
            return  # If the range contains 0 or 1 elements, it is already sorted.

        mid = left + (right - left) // 2  # Calculate the middle index of the range.
        self.mergeSort(nums, left, mid)  # Recursively sort the left half of the range.
        self.mergeSort(nums, mid + 1, right)  # Recursively sort the right half of the range.
        self.merge(nums, left, mid, right)  # Merge the sorted left and right halves.

    def merge(self, nums, left, mid, right):
        # The merge function merges two sorted subarrays [left, mid] and [mid+1, right] into a single sorted subarray.

        temp = []  # Temporary list to store the merged result.
        i, j = left, mid + 1  # Initialize pointers for the two subarrays.

        # Compare elements from both subarrays and append the smaller one to the 'temp' list.
        while i <= mid and j <= right:
            if nums[i] < nums[j]:
                temp.append(nums[i])
                i += 1
            else:
                temp.append(nums[j])
                j += 1

        # If there are remaining elements in the left subarray, append them to 'temp'.
        while i <= mid:
            temp.append(nums[i])
            i += 1

        # If there are remaining elements in the right subarray, append them to 'temp'.
        while j <= right:
            temp.append(nums[j])
            j += 1

        # Copy the merged elements from 'temp' back to the original 'nums' list.
        nums[left:right + 1] = temp

    def sortArray(self, nums: List[int]) -> List[int]:
        # The sortArray function is the entry point for the merge sort algorithm.
        self.mergeSort(nums, 0, len(nums) - 1)  # Start the merge sort with the full range.
        return nums  # Return the sorted 'nums' list.


nums = [5, 2, 3, 1]
print("NUMS:", nums)
solution = Solution()  # Create an instance of the Solution class
sorted_nums = solution.sortArray(nums)
print("SORTED:", sorted_nums)