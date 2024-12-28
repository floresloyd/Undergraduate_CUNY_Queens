class Solution {
public:
    /// Radix sort
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int maxNum = *std::max_element(nums.begin(), nums.end());        
        vector<int> out(n);        
        for (int exp=1; maxNum/exp; exp *= 10){            
            // Count the number of digits
            vector<int> C(10, 0);
            for (auto num: nums) C[(num/exp)%10]++;             

            // Calculate the destination indices
            for (int i=1; i<10; i++) C[i] += C[i-1];

            // Copy from nums to out in reverse direction
            for (int i=n-1; i>=0; i--)
                out[--C[(nums[i]/exp)%10]] = nums[i];
            
            // Copy back to nums
            nums = out;
        } // end-for
                
        int maxGap = nums[1] - nums[0];
        for (int i=2; i<n; i++)
            maxGap = std::max(maxGap, nums[i]-nums[i-1]);
        return maxGap;        
    } // end-maximumGap
};