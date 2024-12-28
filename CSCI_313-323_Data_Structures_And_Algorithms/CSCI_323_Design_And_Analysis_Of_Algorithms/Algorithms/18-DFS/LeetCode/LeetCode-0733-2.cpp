class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
                
        // Did we visit this slot before?
        vector<vector<char>> color(m, vector<char>(n, 0));
        
        // <row, column>
        stack<pair<int, int>> S;
        S.push(make_pair(sr, sc));
        int initialColor = image[sr][sc];
        image[sr][sc] = newColor;
        color[sr][sc] = 1;

        // Expand by DFS
        while (!S.empty()){
            auto [r, c] = S.top(); S.pop();

            vector<pair<int, int>> neighs = {{r, c-1}, {r, c+1}, {r-1, c}, {r+1, c}};
            for (auto [nr, nc]: neighs){
                if (nr<0 || nr==m || nc<0 || nc == n) continue;
                if (color[nr][nc] == 0 && image[nr][nc] == initialColor){
                    image[nr][nc] = newColor;
                    color[nr][nc] = 1;
                    S.push(make_pair(nr, nc));
                } //end-if
            } // end-for
        } // end-while

        return image;
    } // end-floodFill
};