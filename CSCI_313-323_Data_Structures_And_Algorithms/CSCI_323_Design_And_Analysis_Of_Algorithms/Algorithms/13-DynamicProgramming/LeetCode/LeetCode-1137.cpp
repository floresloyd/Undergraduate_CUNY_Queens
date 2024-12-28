class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        int prevResults[3] = {0, 1, 1};
        int result;
        for (int i=3; i<=n; i++){
            result = prevResults[0] + prevResults[1] + prevResults[2];
            prevResults[0] = prevResults[1];
            prevResults[1] = prevResults[2];
            prevResults[2] = result;
        } // end-for

        return result;
    } //end-tribonacci
};