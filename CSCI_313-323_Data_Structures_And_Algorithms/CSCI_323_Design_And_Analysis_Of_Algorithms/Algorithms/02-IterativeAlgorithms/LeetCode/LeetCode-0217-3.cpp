class Solution {
public:
    // O(N) algorithm with O(N) extra space
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for (auto num: nums){
            if (mySet.count(num) != 0)
                return true;
            else
                mySet.insert(num);
        } // end-for
        
        return false;        
    } // end-containsDuplicate
};