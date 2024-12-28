class Solution {
public:
    /// O(n) algorithm with O(n) extra space
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> result(nums.size());
        int evenIndex = 0;
        int oddIndex = 1;
        for (auto num: nums){
            if (num % 2 == 0){
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            } // end-else
        } // end-for
        
        return result;        
    } // end-sortArrayByParityII
};