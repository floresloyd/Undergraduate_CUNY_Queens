class Solution {
public:
    /// O(N+M) algorithm with O(N) extra space using a LUT
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int maxNum = 1000;
        vector<int> lut1(maxNum+1, 0);
        
        for (auto num: nums1) lut1[num] = 1;

        vector<int> result;
        for (auto num: nums2){
            if (lut1[num] == 1){
                result.push_back(num);
                lut1[num] = 0;  // To avoid duplicates in the result
            } // end-if
        } //end-for
        
        return result;                
    } //end-intersection
};