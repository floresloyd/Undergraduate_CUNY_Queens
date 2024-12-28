class Solution {
public:
    /// Bottom-up DP soluton
    int climbStairs(int n) {
        // Handle corner cases first (n=0 & n=1)
        if (n <= 1) return 1;

        int a = 1;  // n=0
        int b = 1;  // n=1
        int result;

        for (int i=2; i<=n; i++){
            result = a + b;
            a = b;
            b = result;
        } //end-for

        return result;
    } // end-climbStairs
};