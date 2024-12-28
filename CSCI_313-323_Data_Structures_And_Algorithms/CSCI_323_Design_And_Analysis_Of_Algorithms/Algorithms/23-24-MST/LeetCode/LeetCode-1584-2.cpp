class Solution {
public:
    // Uses Prim's MST algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> G(n);
               
        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                auto p1 = points[i];
                auto p2 = points[j];
                int dist = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                G[i].push_back({j, dist});
                G[j].push_back({i, dist});
            } // end-for
        } // end-for
        
        enum Color {BLACK, WHITE};
        vector<Color> color(n, WHITE);       
        vector<int> cost(n, INT_MAX);
        cost[0] = 0;

        // Min PQ                           //   <cost, vertex>
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        std::greater<pair<int, int>>> Q;
        Q.push({0, 0});
        int result = 0;

        while (Q.size()){
            auto [_, u] = Q.top(); Q.pop();
            if (color[u] == BLACK) continue;
            
            color[u] = BLACK;
            result += cost[u];

            for (auto [v, weight]: G[u]){
                if (color[v] == WHITE && weight < cost[v]){
                    cost[v] = weight;
                    Q.push({weight, v});
                } // end-if
            } // end-for
        } // end-while
        return result;
    }
};