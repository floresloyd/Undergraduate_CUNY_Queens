class TrieNode {
    static final int NO_LETTERS = 26;
    TrieNode[] children = new TrieNode[NO_LETTERS];
    boolean storesValue = false;
}

class Trie {
    private TrieNode root = new TrieNode();
    public Trie() {}
    
    public void insert(String word) {
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
        TrieNode p = findNode(word);
        return p != null && p.storesValue;        
    }
    
    public boolean startsWith(String prefix) {
        return findNode(prefix) != null;        
    }

    private TrieNode findNode(String str){
        TrieNode p = root;
        for (int i=0; p != null && i<str.length(); i++)
            p = p.children[str.charAt(i)-'a'];
        return p;
    } // end-findNode
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */