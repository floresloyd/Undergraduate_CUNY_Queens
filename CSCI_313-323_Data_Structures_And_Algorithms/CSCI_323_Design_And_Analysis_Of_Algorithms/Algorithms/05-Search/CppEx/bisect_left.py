from bisect import bisect_left

nums = [3, 8, 10, 11, 20, 20, 20, 50, 65, 70, 72, 90, 91, 94, 96, 99]

print(f"Index of 20: {bisect_left(nums, 20)}")
print(f"Index of 60: {bisect_left(nums, 60)}")
print(f"Index of 100: {bisect_left(nums, 100)}")
