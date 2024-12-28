class Solution {
public:
    /// O(n^2) algorithm with O(1) extra space
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        for (auto num: nums){
            if (num <= 0 or num >= n)
                return false;
        } // end-for

        for (int i=1; i<n; i++){
            int count = 0;
            for (auto num: nums){
                if (num == i)
                    count++;
            } // end-for
            if (i == n-1) return count == 2;
            if (count != 1) return false;
        } // end-for
        return true;
    }
};