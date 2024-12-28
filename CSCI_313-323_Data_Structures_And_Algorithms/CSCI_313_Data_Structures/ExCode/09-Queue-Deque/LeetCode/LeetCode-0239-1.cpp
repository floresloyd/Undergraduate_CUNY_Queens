class Solution {
public:
    /// O(n) algorithm with O(k) extra space
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        int n = nums.size();
        deque<int> dq;
        for (int i=0; i<=n; i++){
            if (i >= k){
                result.push_back(nums[dq.front()]);

                if (dq.size() and dq.front() == i-k)
                    dq.pop_front();
            } // end-if

            if (i == n) break;

            while (dq.size() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        } // end-for

        return result;
    } // end-maxSlidingWindow    
};