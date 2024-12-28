class MyHashSet {
    private int TABLE_SIZE = 2011; //1013 //5011    // Some prime number
    private List<Integer>[] T = new LinkedList[TABLE_SIZE];

    public MyHashSet() {}
    
    public void add(int key) {
        int index = key % TABLE_SIZE;
        if (T[index] == null) T[index] = new LinkedList<>();
        else if (T[index].contains(key)) return; // Duplicates not allowed
        T[index].add(key);
    }
    
    public void remove(int key) {
        int index = key % TABLE_SIZE;
        if (T[index] == null) return;
        for (int i=0; i<T[index].size(); i++){
            if (T[index].get(i) == key){
                T[index].remove(i);
                return;
            } // end-for
        } // end-for
    }
    
    public boolean contains(int key) {
        int index = key % TABLE_SIZE;
        if (T[index] == null) return false;
        return T[index].contains(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */