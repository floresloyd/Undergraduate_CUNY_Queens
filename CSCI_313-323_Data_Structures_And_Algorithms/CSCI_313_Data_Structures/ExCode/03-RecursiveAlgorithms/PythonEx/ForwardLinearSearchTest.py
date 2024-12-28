from typing import List

# Recursive forward linear search
def ForwardLinearSearch(nums: List[int], index: int, numsLength: int, key: int) -> int:
    # Base cases
    if index == numsLength: return -1     # Unsuccessful search
    if key == nums[index]: return index  # Success

    # Divide & Conquer & Merge
    return ForwardLinearSearch(nums, index + 1, numsLength, key)

# main function
def main():
    nums = [9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 12, 62, 55]
    numsLength = len(nums)

    print("nums:", nums)

    key = 12
    index = ForwardLinearSearch(nums, 0, numsLength, key)
    if index < 0: print(f"Key {key} does not exist in the array.")
    else: print(f"The first index of key {key} is {index}")
    print("--------------------------")

    key = 77
    index = ForwardLinearSearch(nums, 0, numsLength, key)
    if index < 0: print(f"Key {key} does not exist in the array.\n")
    else: print(f"The first index of key {key} is {index}\n")

# Run main
if __name__ == "__main__":
    main()