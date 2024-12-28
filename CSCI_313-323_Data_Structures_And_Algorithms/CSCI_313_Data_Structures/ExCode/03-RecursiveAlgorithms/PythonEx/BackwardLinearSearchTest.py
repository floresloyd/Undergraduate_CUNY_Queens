from typing import List

# Recursive backward linear search
def BackwardLinearSearch(nums: List[int], index: int, key: int) -> int:
        # Base case
        if index < 0: return -1    # Unsuccessful search

        # Compare "key" with the last element
        if key == nums[index]: return index   # Success

        # Divide & Conquer & Merge
        return BackwardLinearSearch(nums, index-1, key)

# main function
def main():
    nums = [9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 12, 62, 55]
    lastIndex = len(nums)-1

    print("nums:", nums)

    key = 12
    index = BackwardLinearSearch(nums, lastIndex, key)
    if index < 0: print(f"Key {key} does not exist in the array.")
    else: print(f"The first index of key {key} is {index}")
    print("--------------------------")

    key = 77
    index = BackwardLinearSearch(nums, lastIndex, key)
    if index < 0: print(f"Key {key} does not exist in the array.\n")
    else: print(f"The first index of key {key} is {index}\n")

# Run main
if __name__ == "__main__":
    main()