class Solution {
public:
    void dfs(int r, int c, int initialColor, int newColor, vector<vector<int>>& image,
            vector<vector<char>> &color){
        int m = image.size();
        int n = image[0].size();
        
        image[r][c] = newColor;
        color[r][c] = 1;

        vector<pair<int, int>> neighs = {{r, c-1}, {r, c+1}, {r-1, c}, {r+1, c}};
        for (auto [nr, nc]: neighs){
            if (nr<0 || nr==m || nc<0 || nc == n) continue;
            if (color[nr][nc] == 0 && image[nr][nc] == initialColor)
                dfs(nr, nc, initialColor, newColor, image, color);
        } // end-for        
    } // end-dfs
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
                
        // Did we visit this slot before?
        vector<vector<char>> color(m, vector<char>(n, 0));

        // Flood fill using DFS
        dfs(sr, sc, image[sr][sc], newColor, image, color);

        return image;
    } // end-floodFill
};