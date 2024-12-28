class Solution {
public:
    /// O(N+M) algorithm with O(n+m) extra space
    #include <unordered_set>
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;

        for (auto n: nums1) set1.insert(n);
        for (auto n: nums2) set2.insert(n);

        vector<int> result;
        for (auto n: set1){
            if (set2.count(n) > 0) result.push_back(n);
        } //end-for

        return result;
    } //end-intersection
};