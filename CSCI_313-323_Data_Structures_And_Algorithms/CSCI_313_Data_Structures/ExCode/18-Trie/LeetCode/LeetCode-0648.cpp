#define NO_LETTERS 26
struct TrieNode {
    TrieNode *children[NO_LETTERS];
    bool storesValue;

    TrieNode(){
        for (int i=0; i<NO_LETTERS; i++) children[i] = NULL;
        storesValue = false;
    } //end-TrieNode
};

class Solution {
    TrieNode *root = new TrieNode();

    /** Inserts a word into the trie. */
    void insert(string &word) {
        if (word.length() == 0) return;

        TrieNode *p = root;
        for (int i=0; i<word.length(); i++){
            int index = word[i]-'a';
            if (p->children[index] == NULL) 
                p->children[index] = new TrieNode();
            p = p->children[index];
        } //end-for

        p->storesValue = true;
    } //end-insert

public:
    string replaceWords(vector<string>& dict, string sentence) {
        for (int i=0; i<dict.size(); i++)
            insert(dict[i]);

        string result;
        for (int i=0; i<sentence.length();){
            if (sentence[i] == ' '){result.push_back(' '); i++; continue;}

            // Find the start & end of the word
            int first = i;
            while (i<sentence.length() && sentence[i] != ' ') i++;
            int last = i;

            // See if a root of this word exists in the trie.
            // If it does, replace the word with the root
            // Otherwise, copy the word to the result
            string rootWord;
            TrieNode *p = root;
            bool found = false;
            for (int index=first; p && index<last; index++){
                if (p->storesValue){found = true; break;}
                rootWord.push_back(sentence[index]);
                p = p->children[sentence[index]-'a'];
            } //end-while

            // If we found the root, append it to the result
            // otherwise, append the word to the result
            if (found) result.append(rootWord);
            else {
                for (int index=first; index<last; index++){
                    result.push_back(sentence[index]);
                } //end-for
            } //end-else
        } //end-for

        return result;
    } //end-replaceWords
};
