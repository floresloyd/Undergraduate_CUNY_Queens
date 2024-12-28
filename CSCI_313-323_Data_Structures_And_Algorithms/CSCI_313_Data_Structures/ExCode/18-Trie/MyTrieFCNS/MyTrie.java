/**
 * This is the first child/next sibling implementation of the conventional trie
 */
class MyTrieNode {
    boolean storesValue;
    char ch;
    MyTrieNode firstChild;
    MyTrieNode nextSibling;

    public MyTrieNode(char ch){this.ch = ch;}
}

class MyTrie {
    private MyTrieNode root = null;

    public MyTrie() {}

    void add(String word) {
        MyTrieNode pp = null;  // Parent of p
        MyTrieNode p = root;
        for (int i=0; i<word.length(); i++){
            char ch = word.charAt(i);
            // See if any of the children contains this char
            MyTrieNode q = p;
            while (q != null && q.ch != ch) q = q.nextSibling;

            if (q == null){
                MyTrieNode node = new MyTrieNode(ch);            
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
    } //end-add

    boolean find(String word) {
        MyTrieNode pp = findNode(word);
        return pp != null && pp.storesValue;
    } // end-find

    boolean startsWith(String prefix) {
        return findNode(prefix) != null;
    } //end-startsWith

    private MyTrieNode findNode(String str){
        MyTrieNode pp = null; // parent of p
        MyTrieNode p = root;
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
