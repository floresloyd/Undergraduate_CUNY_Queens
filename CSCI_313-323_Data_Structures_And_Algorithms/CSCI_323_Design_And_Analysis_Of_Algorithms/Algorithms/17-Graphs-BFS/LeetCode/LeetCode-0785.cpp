class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        #define BLACK 0
        #define WHITE 1
        vector<int> color(n, WHITE);
        
        #define SETA 0
        #define SETB 1
        vector<int> set(n);  // Which set does the node belong to? 
        
        // Since the graph may be disconnected, we may have to start a new BFS
        // for each connected component. This is why we have this for loop
        queue<int> Q;
        for (int i=0; i<n; i++){
            if (color[i] == WHITE){
                // Start a BFS at node "i"
                color[i] = BLACK;
                set[i] = SETA;
                Q.push(i);
                
                while (!Q.empty()){
                    int u = Q.front(); Q.pop();
                    
                    for (int j=0; j<graph[u].size(); j++){
                        int v = graph[u][j];
                        
                        if (color[v] == BLACK){
                            if (set[u] == set[v]) return false;
                        } else {
                            color[v] = BLACK;
                            Q.push(v);
                            set[v] = set[u] == SETA? SETB: SETA;
                        } // end-else
                    } // end-for
                } // end-while
                
            } // end-if
        } // end-for
        
        return true;
    } // end-isBipartite
};