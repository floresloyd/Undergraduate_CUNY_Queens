from typing import List

# Searches a key in sorted array A[left..right]
def BinarySearch(nums: List[int], left: int, right: int, key: int)->int:
    # Base case 1: Number of elements in the array */
    if left > right: return -1  # Unsuccessful search

    # Compare the key with the middle element */
    middle = (left + right) // 2
    if key == nums[middle]: return middle # Success

    # Conquer & Merge
    elif key < nums[middle]:
        return BinarySearch(nums, left, middle - 1, key)
    else:
        return BinarySearch(nums, middle + 1, right, key)

# main function
def main():
    nums = [1, 4, 5, 6, 10, 12, 13, 17, 25, 30, 32, 33, 50, 54, 55, 58]
    lastIndex = len(nums)-1

    print("nums:", nums)

    key = 12
    index = BinarySearch(nums, 0, lastIndex, key)
    if index < 0: print(f"Key {key} does not exist in the array")
    else: print(f"The last index of key {key} is {index}")

    key = 77
    index = BinarySearch(nums, 0, lastIndex, key)
    if index < 0: print(f"Key {key} does not exist in the array")
    else: print(f"The last index of key {key} is {index}")

# Run main
if __name__ == "__main__":
    main()