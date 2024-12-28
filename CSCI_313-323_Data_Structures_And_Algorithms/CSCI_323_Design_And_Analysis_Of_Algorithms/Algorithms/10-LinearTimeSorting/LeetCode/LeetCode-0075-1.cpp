class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    void sortColors(vector<int>& nums) {
        #define NUM_COLORS 3
        vector<int> C(NUM_COLORS, 0);
        for (auto num: nums) C[num]++;

        for (int color=0, k=0; color<NUM_COLORS; color++){
            while (C[color]--)
                nums[k++] = color;
        } // end-for        
    } // end-sortColors
};