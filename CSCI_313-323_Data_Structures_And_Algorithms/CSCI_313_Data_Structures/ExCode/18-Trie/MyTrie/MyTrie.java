class MyTrieNode {
    static final int NO_LETTERS = 26;
    MyTrieNode[] children;
    boolean storesValue;

    public MyTrieNode(){
        children = new MyTrieNode[NO_LETTERS];
        storesValue = false;
    } //end-MyTrieNode
}

class MyTrie {
    private MyTrieNode[] root = new MyTrieNode[MyTrieNode.NO_LETTERS];

    public MyTrie() {}

    void add(String word) {
        int index[] = new int[word.length()];
        for (int i=0; i<word.length(); i++)
            index[i] = word.charAt(i)-'a';

        if (root[index[0]] == null) root[index[0]] = new MyTrieNode();

        MyTrieNode p = root[index[0]];
        for (int i=1; i<index.length; i++){
            if (p.children[index[i]] == null)
                p.children[index[i]] = new MyTrieNode();            
            p = p.children[index[i]];
        } //end-for

        p.storesValue = true;
    } //end-add

    boolean find(String word) {
        MyTrieNode p = findNode(word);
        return p != null && p.storesValue;
    } // end-find

    boolean startsWith(String prefix) {
        return findNode(prefix) != null;
    } //end-startsWith

    private MyTrieNode findNode(String str){
        int index[] = new int[str.length()];
        for (int i=0; i<str.length(); i++)
            index[i] = str.charAt(i)-'a';        

        MyTrieNode p = root[index[0]];
        for (int i=1; p != null && i<index.length; i++)
            p = p.children[index[i]];
            
        return p;
    }
}
