class Solution {
public:
    /// An O(nxm) algorithm that uses O(m) extra space (monotonic stack)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> S;

        vector<int> nextGreater(nums2.size());
        for (int i=(int)nums2.size()-1; i>=0; i--){
            while (!S.empty() && nums2[i] >= S.top()) S.pop();

            if (S.empty()) nextGreater[i] = -1;
            else           nextGreater[i] = S.top();

            S.push(nums2[i]);
        } //end-for

        // Find the index of nums1[i] inside nums2, and push the nextGreater to the result
        vector<int> result;
        for (int i=0; i<nums1.size(); i++){
            for (int j=0; j<nums2.size(); j++){
                if (nums1[i] == nums2[j]){
                    result.push_back(nextGreater[j]);
                    break;
                } //end-if
            } //end-for
        } //end-for

        return result;
    } //end-nextGreaterElement
};