class Solution {
public:
    // Each time dfs finishes, we have traversed all nodes
    // of a connected component
    #define BLACK 0
    #define WHITE 1
    
    void dfs(int u, vector<vector<int>>& isConnected, vector<char> &color){
        color[u] = BLACK;
        for (int v=0; v<isConnected[u].size(); v++)
            if (isConnected[u][v] && color[v] == WHITE)
                dfs(v, isConnected, color);
    } // end-dfs
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<char> color(n, WHITE);
        
        int noProvinces = 0;
        for (int i=0; i<n; i++){
            if (color[i] == WHITE){
                noProvinces++;
                dfs(i, isConnected, color);
            } // end-if
        } // end-for
        
        return noProvinces;
    } // end-findCircleNum
};