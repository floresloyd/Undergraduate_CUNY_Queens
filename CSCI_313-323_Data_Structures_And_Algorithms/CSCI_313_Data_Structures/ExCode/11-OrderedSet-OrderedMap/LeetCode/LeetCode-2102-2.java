record Pair(int score, String name){}

class SORTracker {    
    // Custom comparator for Pair objects
    private Comparator<Pair> comparator = new Comparator<>(){
        @Override
        public int compare(Pair p1, Pair p2){
            if (p1.score() == p2.score()) 
                return p1.name().compareTo(p2.name());
            return p2.score() - p1.score();
        }
    };

    private TreeSet<Pair> locs = new TreeSet<>(comparator);
    private Pair curr = null;

    public SORTracker() {
        curr = new Pair(Integer.MIN_VALUE, ""); // Sentinel node
        locs.add(curr);
    }
    
    public void add(String name, int score) {
        Pair loc = new Pair(score, name);
        locs.add(loc);
        
        // If we insert a new key to the left of current,
        // then we must move curr one position to the left
        if (comparator.compare(loc, curr) < 0)
            curr = locs.lower(curr);
    }
    
    public String get() {
        curr = locs.higher(curr);
        return curr.name();
    }
}

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker obj = new SORTracker();
 * obj.add(name,score);
 * String param_2 = obj.get();
 */