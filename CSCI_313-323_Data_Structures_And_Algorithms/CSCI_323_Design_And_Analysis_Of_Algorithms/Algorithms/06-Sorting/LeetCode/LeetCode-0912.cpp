class Solution {
public:
    /// O(nlogn) algorithm with O(n) extra space
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> buffer(n);

        function<void(int, int)> ms = [&](int left, int right){
            // Base case [], [1]
            if (left >= right) return;

            int middle = left + (right-left)/2;

            // [left..middle]
            ms(left, middle);

            // [middle+1..right]
            ms(middle+1, right);

            // Merge
            int i = left;  
            int j = middle+1;
            int k = 0;
            while (i<=middle and j<=right){
                if (nums[i] <= nums[j])
                    buffer[k++] = nums[i++];
                else
                    buffer[k++] = nums[j++];
            } // end-while

            while (i<=middle)
                buffer[k++] = nums[i++];

            while (j<=right)
                buffer[k++] = nums[j++];

            // Copy from buffer back to nums
            for (int i=left, k=0; i<=right; i++, k++)
                nums[i] = buffer[k];                
        };

        ms(0, n-1);
        return nums;
    } // end-sortArray
};