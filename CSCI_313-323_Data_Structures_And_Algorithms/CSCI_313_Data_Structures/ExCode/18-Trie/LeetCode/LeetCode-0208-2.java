/**
 * This is the first child/next sibling implementation of the conventional trie
 */
class TrieNode {
    boolean storesValue;
    char ch;
    TrieNode firstChild;
    TrieNode nextSibling;

    public TrieNode(char ch){this.ch = ch;}
}

class Trie {
    private TrieNode root = null;

    public Trie() {}

    void insert(String word) {
        TrieNode pp = null;  // Parent of p
        TrieNode p = root;
        for (int i=0; i<word.length(); i++){
            char ch = word.charAt(i);
            // See if any of the children contains this char
            TrieNode q = p;
            while (q != null && q.ch != ch) q = q.nextSibling;

            if (q == null){
                TrieNode node = new TrieNode(ch);            
                node.nextSibling = p;
                p = node;

                if (pp == null) root = p;
                else pp.firstChild = p;

                pp = p;
                p = p.firstChild;

            } else {
                pp = q;
                p = q.firstChild;
            } // end-else
        } //end-for

        pp.storesValue = true;
    } //end-insert

    boolean search(String word) {
        TrieNode pp = findNode(word);
        return pp != null && pp.storesValue;
    } // end-search

    boolean startsWith(String prefix) {
        return findNode(prefix) != null;
    } //end-startsWith

    private TrieNode findNode(String str){
        TrieNode pp = null; // parent of p
        TrieNode p = root;
        for (int i=0; i<str.length(); i++){
            char ch = str.charAt(i);
            while (p != null && p.ch != ch) p = p.nextSibling;
            if (p == null) return null;
            pp = p;
            p = p.firstChild;
        } //end-for

        return pp;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */