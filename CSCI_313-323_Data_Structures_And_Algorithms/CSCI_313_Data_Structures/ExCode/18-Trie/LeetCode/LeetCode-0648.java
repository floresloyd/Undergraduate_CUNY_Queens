class TrieNode {
    static final int NO_LETTERS = 26;
    TrieNode[] children = new TrieNode[NO_LETTERS];
    boolean storesValue = false;
}

class Solution {
    private TrieNode root = new TrieNode();

    /**
     * Insert a new word to the trie
     */
    public void insert(String word) {
        if (word.length() == 0) return;

        TrieNode p = root;
        for (int i=0; i<word.length(); i++){
            int index = word.charAt(i)-'a';
            if (p.children[index] == null) 
                p.children[index] = new TrieNode();
            p = p.children[index];
        } //end-for

        p.storesValue = true;        
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        for (var word: dictionary) insert(word);

        StringBuilder result = new StringBuilder();
        for (int i=0; i<sentence.length();){
            if (sentence.charAt(i) == ' '){result.append(' '); i++; continue;}

            // Find the start & end of the word
            int first = i;
            while (i<sentence.length() && sentence.charAt(i) != ' ') i++;
            int last = i;

            // See if a root of this word exists in the trie.
            // If it does, replace the word with the root
            // Otherwise, copy the word to the result
            StringBuilder rootWord = new StringBuilder();
            TrieNode p = root;
            boolean found = false;
            for (int index=first; p != null && index<last; index++){
                if (p.storesValue){found = true; break;}
                rootWord.append(sentence.charAt(index));
                p = p.children[sentence.charAt(index)-'a'];
            } //end-while

            // If we found the root, append it to the result
            // otherwise, append the word to the result
            if (found) result.append(rootWord.toString());
            else {
                for (int index=first; index<last; index++){
                    result.append(sentence.charAt(index));
                } //end-for
            } //end-else
        } //end-for

        return result.toString();        
    }
}