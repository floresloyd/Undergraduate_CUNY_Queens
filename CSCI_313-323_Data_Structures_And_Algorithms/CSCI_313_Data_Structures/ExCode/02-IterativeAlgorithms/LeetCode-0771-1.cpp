class Solution {
public:
    ///------------------------------------------------------------------
    /// This is O(n*m) algorithm: For each char in S, search it in J.
    /// If it exists in J, then increment the count
    ///
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (auto ch1: stones){
            for (auto ch2: jewels){
                if (ch1 == ch2){
                    count++;
                    break;
                } // end-if
            } //end-for
        } // end-for

        return count;        
    } // end-numJewelsInStones
};
