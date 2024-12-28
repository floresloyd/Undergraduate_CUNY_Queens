class Solution {
public:
    // O(NlogN + MlogM) algorithm with O(1) extra space
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> result;
        
        int i = 0;
        int j = 0;
        while (i<nums1.size() and j<nums2.size()){
            if (nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i += 1;
                j += 1;
                
                // Skip over duplicates
                while (i<nums1.size() and nums1[i] == nums1[i-1]) i++;
                while (j<nums2.size() and nums2[j] == nums2[j-1]) j++;

            } else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        } // end-while
        
        return result;
    } // end-intersection
};