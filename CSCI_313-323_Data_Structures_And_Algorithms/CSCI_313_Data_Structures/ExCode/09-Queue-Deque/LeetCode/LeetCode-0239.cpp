class Solution {
public:
    /// O(n) algorithm with O(k) extra space
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;        
        vector<int> result;

        for (int i=0; i<nums.size(); i++){
            auto curr = nums[i];
            
            // Remove the number that got out of the window
            if (dq.size() and dq.front()<=i-k) dq.pop_front();
            
            // Remove numbers that cannot be max. in the future
            while (dq.size() and curr >= nums[dq.back()]) dq.pop_back();  
                      
            // Push the current index
            dq.push_back(i);
            
            // If the window size is "k", push the max. value to the result
            if (i >= k-1)
                result.push_back(nums[dq.front()]);
        } //end-for

        return result;
    } // end-maxSlidingWindow    
};