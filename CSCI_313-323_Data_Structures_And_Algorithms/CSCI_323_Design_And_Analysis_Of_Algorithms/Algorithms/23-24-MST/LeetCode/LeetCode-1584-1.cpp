class Solution {
public:
    ///-------------------------------------------------------
    /// Simply run Kruskal's MST algorithm
    ///
    // Find set with path compression
    int find(vector<int> &sets, int u){
        if (sets[u] < 0) return u;
        
        int s = find(sets, sets[u]);
        sets[u] = s;
        return s;
    } // end-findSet
    
    void join(vector<int> &sets, int u, int v){
        if (u == v) return;
        if (sets[u] < sets[v]){
            sets[u] += sets[v];
            sets[v] = u;
        } else {
            sets[v] += sets[u];
            sets[u] = v;
        } //end-else
    } // end-join
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;
    
        vector<tuple<int, int, int>> dists;
        
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                int dx = abs(points[i][0] - points[j][0]);
                int dy = abs(points[i][1] - points[j][1]);
                
                dists.push_back({dx+dy, i, j});
            } // end-for
        } // end-for
        
        // Sort the edges wrt their distance in increasing order
        std::sort(dists.begin(), dists.end());
        
        // Walk over the edges & select the edges that do not create a cycle
        int minCost = 0;
        vector<int> sets(n, -1);
        for (auto [d, i, j]: dists){
            int s1 = find(sets, i);
            int s2 = find(sets, j);
            if (s1 != s2){
                minCost += d;
                join(sets, s1, s2);
            } // end-if
        } // end-for
        
        return minCost;
    } // end-minCostConnectPoints
};