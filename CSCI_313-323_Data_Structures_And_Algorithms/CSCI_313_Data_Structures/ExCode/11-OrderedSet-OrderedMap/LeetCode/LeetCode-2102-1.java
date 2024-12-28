class Pair implements Comparable<Pair> {
    int score;
    String name;
    public Pair(int score, String name){
        this.score = score;
        this.name = name;
    }

    public int compareTo(Pair p){
        if (score == p.score) return name.compareTo(p.name);
        return p.score - score;
    }
}
class SORTracker {    
    private TreeSet<Pair> locs = new TreeSet<>();
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
        if (loc.compareTo(curr) < 0)
            curr = locs.lower(curr);
    }
    
    public String get() {
        curr = locs.higher(curr);
        return curr.name;
    }
}

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker obj = new SORTracker();
 * obj.add(name,score);
 * String param_2 = obj.get();
 */