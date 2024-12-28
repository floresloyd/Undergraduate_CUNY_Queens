class Solution {
public:
    /// The idea is to do a DFS and look for back-edges, which indicate loops
    /// When we find a back-edge, look at the length of the loop
    /// If the loop has at least 4 cells, then return true
    #define BLACK 0
    #define WHITE 1
    
    bool dfs(int r, int c,
             vector<vector<char>>& grid,
             vector<vector<char>>& color,
             vector<vector<int>>& dist){
        color[r][c] = BLACK;

        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int, int>> neigh = {{r, c-1}, {r, c+1}, {r-1, c}, {r+1, c}};
        for (auto [nr, nc]: neigh){
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (grid[nr][nc] != grid[r][c]) continue;   // Need to have the same letter            
            if (color[nr][nc] == BLACK){
                if (dist[nr][nc] - dist[r][c] >= 3) return true;
                continue;
            } // end-if
            
            dist[nr][nc] = dist[r][c]+1;
            if (dfs(nr, nc, grid, color, dist)) return true;                   
        } // end-for
        
        return false;
    } // end-dfs
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<char>> color(m, vector<char>(n, WHITE));
        vector<vector<int>> dist(m, vector<int>(n, 1));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (color[i][j] == BLACK)
                    continue;
                
                if (dfs(i, j, grid, color, dist))
                    return true;
            } // end-for
        } // end-for
        
        return false;
    } // end-containsCycle
};