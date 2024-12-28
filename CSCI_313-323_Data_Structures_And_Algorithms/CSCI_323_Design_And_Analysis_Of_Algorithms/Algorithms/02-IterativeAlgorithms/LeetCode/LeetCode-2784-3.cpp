class Solution {
public:
    /// O(n) algorithm with O(n) extra space
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> C(n, 0);
        for (auto num: nums){
            if (num <= 0) return false;
            if (num >= n) return false;
            if (++C[num] > 2) return false;
        } // end-for

        if (C[n-1] != 2) return false;
        for (int i=1; i<n-1; i++)
            if (C[i] != 1) return false;
        return true;
    }
};