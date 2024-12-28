class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k=0;
        while (k<n and nums[k] != 0)
            k++;        
        if (k >= n) return;

        for (int i=k+1; i<n; i++){
            if (nums[i] != 0){
                nums[k++] = nums[i];
                nums[i] = 0;
            } // end-if
        } // end-for  
    }
};