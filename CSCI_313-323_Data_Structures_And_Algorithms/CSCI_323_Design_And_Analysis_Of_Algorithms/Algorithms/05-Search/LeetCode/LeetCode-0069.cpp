class Solution {
public:
    // O(log(x)): upper_bound/bisect_right
    int mySqrt(int x) {
        if (x == 0 or x == 1) return x;

        int left = 1;
        int right = x;
        while (left <= right){
            long long middle = left + (right-left)/2;
            if (middle*middle <= x)
                left = middle+1;
            else
                right = middle-1;
        }
        return left-1;
    } // end-mySqrt
};
