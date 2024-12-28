class Solution {
public:
    ///------------------------------------------------------------------
    /// O(n+m) time algorithm, where n & m are the lengths of strings jewels and stones
    ///
    int numJewelsInStones(string jewels, string stones) {
        // A big enough table to contain both upper & lower-case letters
        #define NO_LETTERS 'z'+ 1
        bool LUT[NO_LETTERS] = {false};

        // Mark all Jewels in the table
        for (auto ch: jewels) LUT[ch] = true;

        // Go over stones. If a letter is a jewel, add it to the count
        int count = 0;
        for (auto ch: stones){
            if (LUT[ch]) count++;
        } //end-if

        return count;
    } // end-numJewelsInStones
};


