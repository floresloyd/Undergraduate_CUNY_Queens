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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DS ds(m*n);
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                // Look at two neighbors: Left, Up
                vector<pair<int, int>> neigh = {{i, j-1}, {i-1, j}};
                
                for (auto [nr, nc]: neigh){
                    if (nr >= 0 && nc >= 0 && grid[nr][nc] == grid[i][j]){
                        int u = i*n+j;
                        int v = nr*n+nc;
                        int set1 = ds.find(u);
                        int set2 = ds.find(v);
                        if (set1 == set2){
                            if (ds.size(set1) >= 4) return true;
                        } else {
                            ds.join(set1, set2);
                        } // end-else
                    } // end-if
                } // end-for
            } // end-for
        } // end-for
        
        return false;
    } // end-containsCycle
};