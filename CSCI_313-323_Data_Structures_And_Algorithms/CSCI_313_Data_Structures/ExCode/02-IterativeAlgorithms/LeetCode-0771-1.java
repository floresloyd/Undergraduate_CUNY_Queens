class Solution {
    /**
     * This is O(n*m) algorithm: For each char in S, search it in J.
     * If it exists in J, then increment the count
     */
    public int numJewelsInStones(String jewels, String stones) {
        int count = 0;
        for (int i=0; i<stones.length(); i++){
            for (int j=0; j<jewels.length(); j++){
                if (stones.charAt(i) == jewels.charAt(j)){
                    count++;
                    break;
                } // end-if
            } //end-for
        } // end-for

        return count;        
    } // end-numJewelsInStones
}