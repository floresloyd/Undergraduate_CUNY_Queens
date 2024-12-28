class Solution:
    # This is O(n*m) algorithm: For each char in S, search it in J.
    # If it exists in J, then increment the count
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        count = 0
        for ch1 in stones:
            if ch1 in jewels:
                    count += 1
        return count

