class Solution {
public:
    // O(N^2) algorithm with O(1) extra space
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i=0; i<nums1.size(); i++){
            bool found = false;
            for (int j=0; j<nums2.size(); j++){
                if (nums1[i] == nums2[j]){
                    found = true;
                    break;
                } // end-if
            } // end-for
            
            if (found){
                // Add num[i] to the result if not already added
                found = false;
                for (int j=0; j<result.size(); j++){
                    if (nums1[i] == result[j]){
                        found = true;
                        break;
                    } // end-if
                } // end-for
                
                if (!found) result.push_back(nums1[i]);
            } // end-if            
        } // end-for

        return result;        
    } // end-intersection
};