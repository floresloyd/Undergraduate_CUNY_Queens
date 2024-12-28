#define NO_LETTERS 26
struct TrieNode {
    TrieNode *children[NO_LETTERS];
    bool storesValue;

    TrieNode(){
        for (int i=0; i<NO_LETTERS; i++) children[i] = NULL;
        storesValue = false;
    } //end-TrieNode
};

class Trie {
private:
    TrieNode *root = new TrieNode();

    void deleteNodes(TrieNode *ptr){
        if (ptr == NULL) return;
        for (int i=0; i<NO_LETTERS; i++) 
            deleteNodes(ptr->children[i]);
        delete ptr;
    } // end-deleteNodes

    TrieNode *findNode(string &str){
        TrieNode *p = root;
        for (auto ch: str){
            if (p == NULL) break;
            p = p->children[ch - 'a'];
        } //end-for        
        return p;
    } // end-findNode

public:
    /** Initialize your data structure here. */
    Trie() {}

    ~Trie(){deleteNodes(root);}

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (auto ch: word){
            int index = ch-'a';
            if (p->children[index] == NULL) 
                p->children[index] = new TrieNode();
            p = p->children[index];
        } //end-for

        p->storesValue = true;
    } //end-insert

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = findNode(word);
        return p && p->storesValue;
    } // end-search

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return findNode(prefix) != NULL;
    } //end-startsWith


};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */