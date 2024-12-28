class Solution {
public:
    // Do BFS starting from (0, 0)
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0) return -1;
        if (grid[n-1][n-1] != 0) return -1;
        if (n == 1) return 1;

        //         <r, c, len>
        queue<tuple<int, int, int>> Q;
        Q.push({0, 0, 1});
        grid[0][0] = 1; // Mark visited
        
        while (!Q.empty()){
            auto [r, c, len] = Q.front(); Q.pop();
            
            // Look at 8 neighbors
            vector<pair<int, int>> neigh = {
                {r-1, c-1}, {r-1, c}, {r-1, c+1},
                {r, c-1},             {r, c+1},
                {r+1, c-1}, {r+1, c}, {r+1, c+1}};
            
            for (auto [nr, nc]: neigh){
                if (nr == n-1 && nc == n-1) return len+1;
                if (nr<0 || nr>=n || nc<0 || nc>=n) continue;
                if (grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    Q.push({nr, nc, len+1});
                } // end-if
            } // end-for
        } // end-while
        
        return -1;
    } // end-shortestPathBinaryMatrix
};