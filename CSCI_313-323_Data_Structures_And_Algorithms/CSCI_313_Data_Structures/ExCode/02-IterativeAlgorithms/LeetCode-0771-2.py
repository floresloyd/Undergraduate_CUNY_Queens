class Solution:
    # O(n+m) time algorithm, where n & m are the lengths of strings jewels and stones
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        # A big enough table to contain both upper & lower-case letters
        LUT = [False]*(ord('z')+1)

        # Mark all Jewels in the table
        for ch in jewels: 
            LUT[ord(ch)] = True

        # Go over stones. If a letter is a jewel, add it to the count
        count = 0
        for ch in stones:
            if LUT[ord(ch)]: 
                count += 1
        return count
