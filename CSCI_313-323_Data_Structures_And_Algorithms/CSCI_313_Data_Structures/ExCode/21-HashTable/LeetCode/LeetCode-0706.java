class Pair {
    int key;
    int value;
    public Pair(int key, int value){
        this.key = key;
        this.value = value;
    }
}

class MyHashMap {
    private int TABLE_SIZE = 2011; // Some prime number
    private List<Pair>[] T = new LinkedList[TABLE_SIZE];

    public MyHashMap() {}
    
    public void put(int key, int value) {
        int index = key % TABLE_SIZE;
        if (T[index] == null) T[index] = new LinkedList<>();
        for (var pair: T[index]){
            if (pair.key == key){
                pair.value = value;
                return;
            }
        } // end-for

        T[index].add(new Pair(key, value));
    }
    
    public int get(int key) {
        int index = key % TABLE_SIZE;
        if (T[index] == null) return -1;

        for (var pair: T[index])
            if (pair.key == key)
                return pair.value;

        return -1;        
    }
    
    public void remove(int key) {
        int index = key % TABLE_SIZE;
        if (T[index] == null) return;
        for (int i=0; i<T[index].size(); i++){
            if (T[index].get(i).key == key){
                T[index].remove(i);
                return;
            } // end-for
        } // end-for
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */