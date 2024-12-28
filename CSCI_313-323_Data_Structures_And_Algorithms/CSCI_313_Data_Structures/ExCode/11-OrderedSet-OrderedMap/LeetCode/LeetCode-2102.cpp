class SORTracker {
    set<pair<int, string>> locs;
    set<pair<int, string>>::iterator curr;
public:
    SORTracker() {
        // Initially insert a sentinel node
        locs.insert({INT_MIN, ""});
        curr = locs.begin();
    } // end-SORTracker
    
    void add(string name, int score) {
        // Create a key from score & name s.t. -score+name is lexicographically ordered
        pair<int, string> key = {-score, name};        
        locs.insert(key);
        
        // If we insert a new key to the left of current,
        // then we must move curr one position to the left
        if (key < *curr)
            --curr;
    } // end-add
    
    string get() {
        return (++curr)->second;
    } // end-get
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */