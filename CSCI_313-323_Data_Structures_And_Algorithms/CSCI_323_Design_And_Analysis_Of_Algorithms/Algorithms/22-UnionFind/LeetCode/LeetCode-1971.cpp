/// Disjoint set class
class DS {
    vector<int> sets;
public:
    DS(int n){sets.resize(n, -1);}
    
    // Find set with path compression
    int find(int u){
        if (sets[u] < 0) return u;
        
        int s = find(sets[u]);
        sets[u] = s;
        return s;
    } // end-findSet
    
    void join(int u, int v){
        if (u == v) return;
        if (sets[u] < sets[v]){
            sets[u] += sets[v];
            sets[v] = u;
        } else {
            sets[v] += sets[u];
            sets[u] = v;
        } //end-else
    } // end-join
    
    // Assume that "u" is a valid set head
    int size(int u){return -sets[u];}
}; // end-DS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        /// For a path to exist between start & end, they have to be
        /// on the same connected component, i.e., same set
        DS ds(n);

        for (int i=0; i<edges.size(); i++){
            int set1 = ds.find(edges[i][0]);
            int set2 = ds.find(edges[i][1]);
            ds.join(set1, set2);
        } // end-for
        
        return ds.find(start) == ds.find(end);
    } // end-validPath
};