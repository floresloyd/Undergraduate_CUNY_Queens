/// Disjoint set class
class DS {
    vector<int> sets;
    int numSets;
public:
    DS(int n){sets.resize(n, -1); numSets=n;}
    
    // Find set with path compression
    int find(int u){
        if (sets[u] < 0) return u;
        
        int s = find(sets[u]);
        sets[u] = s;
        return s;
    } // end-findSet
    
    void join(int u, int v){
        if (sets[u] >= 0) u = find(u);
        if (sets[v] >= 0) v = find(v);
        if (u == v) return;
        
        numSets--;
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
    int numberOfSets(){return numSets;}
}; // end-DS

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DS ds(n);
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (isConnected[i][j]){
                    ds.join(i, j);
                } // end-if            
            } // end-for
        } // end-for
        
        return ds.numberOfSets();
    } // end-findCircleNum
};