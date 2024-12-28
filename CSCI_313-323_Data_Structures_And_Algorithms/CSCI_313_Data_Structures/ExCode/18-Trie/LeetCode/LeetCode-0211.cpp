#define NO_LETTERS 26
struct TrieNode {
    TrieNode *children[NO_LETTERS];
    bool storesValue;

    TrieNode(){
        for (int i=0; i<NO_LETTERS; i++) children[i] = NULL;
        storesValue = false;
    } //end-TrieNode
};

class WordDictionary {
    TrieNode *root = new TrieNode();

    bool search(string &word, int index, TrieNode *p){
        if (!p) return false;
        if (index >= word.length()) return p->storesValue;

        if (word[index] != '.') return search(word, index+1, p->children[word[index]-'a']);

        for (int i=0; i<NO_LETTERS; i++)
            if (search(word, index+1, p->children[i])) return true;
        return false;
    } //end-search

public:
    /** Initialize your data structure here. */
    WordDictionary() {}

    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.length() == 0) return;

        TrieNode *p = root;
        for (auto ch: word){
            int index = ch-'a';
            if (p->children[index] == NULL) 
                p->children[index] = new TrieNode();
            p = p->children[index];
        } //end-for

        p->storesValue = true;
    } //end-addWord

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    } //end-search
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
