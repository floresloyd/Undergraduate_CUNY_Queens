class Solution {
public:
    ///-----------------------------------------------------
    /// Simply do BFS & find connected components
    ///
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        #define BLACK 0
        #define WHITE 1
        vector<char> color(n, WHITE);
        
        int numProvinces = 0;
        for (int i=0; i<n; i++){
            if (color[i] == BLACK) continue;

            numProvinces++;
            color[i] = BLACK;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()){
                int u = Q.front(); Q.pop();
                
                for (int v=0; v<isConnected[i].size(); v++){
                    if (isConnected[u][v] && color[v] == WHITE){
                        color[v] = BLACK;
                        Q.push(v);
                    } // end-if
                } // end-for
            } // end-while
        } // end-for
        
        return numProvinces;
    } // end-findCircleNum
};