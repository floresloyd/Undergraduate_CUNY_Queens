class Solution {
public:
    /// Naive recursive implementation
    /// Notice that this is nothing but the Fibonacci sequence
    int climbStairs(int n) {
        if (n <= 1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    } //end-climbStairs
};