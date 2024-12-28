class Solution {
public:
    /// O(n) algorithm with O(n) extra space
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;

        for (auto num: nums){
            if (mySet.count(num)) // Expected O(1)
                return true;
            mySet.insert(num); // Expected O(1)
        } // end-for

        return false;
    }
};