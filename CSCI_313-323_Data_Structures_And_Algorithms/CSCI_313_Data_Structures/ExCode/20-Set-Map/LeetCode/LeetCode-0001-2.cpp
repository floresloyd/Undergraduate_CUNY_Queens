class Solution {
public:
    // O(n) algorithm with O(1) extra space
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;

        for (int i=0; i<nums.size(); i++){
            int otherNum = target-nums[i];
            if (myMap.count(otherNum))
                return {myMap[otherNum], i};
            else
                myMap[nums[i]] = i;
        } // end-for
        return {-1, -1};
    } // end-twoSum
};