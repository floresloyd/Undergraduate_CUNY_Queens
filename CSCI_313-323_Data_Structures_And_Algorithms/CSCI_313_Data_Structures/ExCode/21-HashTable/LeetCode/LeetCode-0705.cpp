class MyHashSet {
    #define TABLE_SIZE 2011 //1013 //5011    // Some prime number
    vector<list<int>> T;

public:
    /** Initialize your data structure here. */
    MyHashSet() {T.resize(TABLE_SIZE);}

    void add(int key) {
        int index = key % TABLE_SIZE;
        for (auto no: T[index]){
            if (no == key) return;   // Duplicates not allowed
        } //end-for

        T[index].push_back(key);
    } //end-add

    void remove(int key) {
        int index = key % TABLE_SIZE;
        for (auto iter = T[index].begin(); iter != T[index].end(); iter++){
            if (*iter == key){
                T[index].erase(iter);
                return;
            } //end-if
        } //end-for
    } //end-remove

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key % TABLE_SIZE;
        for (auto no: T[index]){
            if (no == key) return true;   // Exists
        } //end-for

        return false;
    } // end-contains
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */