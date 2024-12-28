class MyHashMap {
    #define TABLE_SIZE 2011 // 1013 //5011    // Some prime number
    vector<list<pair<int, int>>> T;

public:
    /** Initialize your data structure here. */
    MyHashMap() {T.resize(TABLE_SIZE);}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % TABLE_SIZE;
        for (auto iter = T[index].begin(); iter != T[index].end(); iter++){
            if (iter->first == key){
                iter->second = value;
                return;
            } //end-if
        } //end-for

        T[index].push_back(make_pair(key, value));
    } // end-put

    /** Returns the value to which the specified key is mapped,
        or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % TABLE_SIZE;
        for (auto p: T[index]){
            if (p.first == key) return p.second;   // Exists. Return the value
        } //end-for

        return -1;    // Does not exist
    } //end-get

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % TABLE_SIZE;
        for (auto iter = T[index].begin(); iter != T[index].end(); iter++){
            if (iter->first == key){
                T[index].erase(iter);
                return;
            } //end-if
        } //end-for
    } //end-remove
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */