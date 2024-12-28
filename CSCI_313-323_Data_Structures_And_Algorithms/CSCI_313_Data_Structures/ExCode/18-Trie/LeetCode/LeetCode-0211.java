class TrieNode {
    static final int NO_LETTERS = 26;
    TrieNode[] children = new TrieNode[NO_LETTERS];
    boolean storesValue = false;
}

class WordDictionary {
    private TrieNode root = new TrieNode();

    private boolean search(String word, int index, TrieNode p){
        if (p == null) return false;
        if (index >= word.length()) return p.storesValue;

        if (word.charAt(index) != '.') 
            return search(word, index+1, p.children[word.charAt(index)-'a']);

        for (var child: p.children)
            if (search(word, index+1, child)) return true;
        return false;
    } //end-search    

    public WordDictionary() {}
    
    public void addWord(String word) {
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
    
    public boolean search(String word) {
        return search(word, 0, root);        
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */