class Solution {
    /**
     * O(n+m) time algorithm, where n & m are the lengths of strings jewels and stones
     */
    public int numJewelsInStones(String jewels, String stones) {
        // A big enough table to contain both upper & lower-case letters
        boolean[] LUT = new boolean['z'+ 1];

        // Mark all Jewels in the table
        for (int i=0; i<jewels.length(); i++) LUT[jewels.charAt(i)] = true;

        // Go over stones. If a letter is a jewel, add it to the count
        int count = 0;
        for (int i=0; i<stones.length(); i++){
            if (LUT[stones.charAt(i)]) count++;
        } //end-if

        return count;        
    } // end-numJewelsInStones
}
