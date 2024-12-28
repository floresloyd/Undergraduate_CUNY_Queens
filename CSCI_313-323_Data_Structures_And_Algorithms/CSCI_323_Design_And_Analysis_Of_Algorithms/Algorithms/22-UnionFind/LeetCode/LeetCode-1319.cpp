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
}; // end-DS

class Solution {
public:
    ///---------------------------------------------------------
    /// Idea: Compute the number of connected components using 
    /// a Union-Find DS. At the same time, count the number 
    /// of extra connections, i.e., connections that create loops
    /// Finally, simply compare the number of extra connections
    /// and the number of connected components
    int makeConnected(int n, vector<vector<int>>& connections) {
        DS ds(n);
        
        int noExtraCables = 0;
        int noSets = n;
        for (int i=0; i<connections.size(); i++){
            int s1 = ds.find(connections[i][0]);
            int s2 = ds.find(connections[i][1]);
            if (s1 == s2) noExtraCables++; // loop
            else {
                ds.join(s1, s2);
                noSets--;
            } // end-else
        } // end-for
        
        int noCablesNeeded = noSets-1;
        if (noCablesNeeded > noExtraCables) return -1;
        return noCablesNeeded;
    } // end-makeConnected
};