class Solution {
public:
    /// Idea: Chain matrix multiplication
    /// Let's say the original nums = [3, 2, 4]
    /// We first insert 1 at the beginning and at the end
    /// So, nums becomes [1, 3, 2, 4, 1]
    /// The problem now is very similar to chain matrix multiplication
    /// That is, we have matrices A of size [1, 3], B of size [3, 2]
    /// C of size [2, 4] and D of size [4, 1]. We are trying to multiply
    /// AxBxCxD in a way to maximize the number of matrix multiplications
    /// A[1,3]xB[3,2]xC[2,4]xD[4,1]
    /// Try to parenthesize this matrix multiplication so as to maximize
    /// the number of operations. If, say you burst B, then it is as if
    /// we compute (AxB)x(CxD), where after (AxB), the size of the matrix
    /// is 1x2, and after CxD, the size of the matrix is 2x1
    /// So, the final multiplication will take 1x2x1 operations
    ///
    /// The following is a brute-force recursive solution. Gets TLE
    int maxCoinsAux(vector<int>& nums, int left, int right){
        if (left >= right) return 0;
        
        // We have "n" alternatives
        // Try bursting each one, and take the max.
        int maxx = INT_MIN;
        for (int i=left; i<right; i++){
            // Burst the ith baloon
            int val = maxCoinsAux(nums,left, i) + 
                      maxCoinsAux(nums,i+1, right) + 
                      nums[left-1]*nums[i]*nums[right];
            maxx = std::max(maxx, val);
        } //end-for
        
        return maxx;
    } //end-maxCoins
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return maxCoinsAux(nums, 1, n+1);
    } //end-maxCoins    
};