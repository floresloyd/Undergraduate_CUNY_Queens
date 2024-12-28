class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        S = []
        nextGreater = []
        for num in nums2[-1::-1]:
            while len(S) > 0 and num >= S[-1]: S.pop()

            if len(S) == 0: nextGreater.append(-1)
            else:           nextGreater.append(S[-1])

            S.append(num)

        # Find the index of nums1[i] inside nums2, and push the nextGreater to the result
        nextGreater.reverse()
        result = []
        for num1 in nums1:
            for j in range(0, len(nums2)):
                if num1 == nums2[j]:
                    result.append(nextGreater[j])
                    break
        return result
