class Solution {
public:
    /// O(n+klogn) with O(n) extra space
    long long maxKelements(vector<int>& nums, int k) {        
        priority_queue<int> Q(nums.begin(), nums.end());

        int64_t result = 0;
        while (k--){
            int num = Q.top();
            Q.pop();
            result += num;
            Q.push((num+2)/3);
        } // end-while
        return result;
    } // end-maxKelements
};