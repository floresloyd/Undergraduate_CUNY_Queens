class Solution {
public:
    #define BLACK 0
    #define WHITE 1
    
    #define SETA 0
    #define SETB 1
    
    bool dfs(int u, vector<vector<int>>& G, vector<int> &color, vector<int> &set){
        color[u] = BLACK;
        
        for (auto v: G[u]){
            if (color[v] == BLACK){
                if (set[u] == set[v]) return false;
            } else {
                color[v] = BLACK;
                set[v] = set[u] == SETA? SETB: SETA;
                if (dfs(v, G, color, set) == false) return false;
            } // end-else            
        } // end-for
        
        return true;
    } // end-dfs
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, WHITE);
        vector<int> set(n);  // Which set does the node belong to? 

        // Since the graph may be disconnected, we may have to start a new BFS
        // for each connected component. This is why we have this for loop
        for (int i=0; i<n; i++){
            if (color[i] == WHITE){
                // Start a DFS at node "i"
                set[i] = SETA;
                if (dfs(i, graph, color, set) == false) return false;
            } //end-if
        } //end-for
        
        return true;
    } // end-isBipartite
};