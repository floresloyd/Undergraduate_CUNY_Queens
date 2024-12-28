class Solution {
public:
    /// O(nlogn) algorithm with O(n) extra space
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> marbles(nums.begin(), nums.end());
        for (int i=0; i<moveFrom.size(); i++){
            if (moveFrom[i] == moveTo[i]) continue;
            marbles.erase(moveFrom[i]);
            marbles.insert(moveTo[i]);
        } // end-for

        return vector<int>(marbles.begin(), marbles.end());
    } // end-relocateMarbles
};