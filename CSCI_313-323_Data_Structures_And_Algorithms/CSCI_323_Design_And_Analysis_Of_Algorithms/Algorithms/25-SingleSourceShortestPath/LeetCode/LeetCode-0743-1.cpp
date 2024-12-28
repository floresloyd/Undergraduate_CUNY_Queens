class Solution {
public:
    /// Simply run Dijkra's shortest path algorithm & take the distance
    /// to the farthest node as the solution
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Convert times to an adjacency list
        vector<vector<pair<int, int>>> G(n+1);
        for (int i=0; i<times.size(); i++)
            G[times[i][0]].push_back({times[i][1], times[i][2]});

        // Run Dijktra's algorithm
        enum Color {BLACK, WHITE};
        vector<Color> color(n+1, WHITE);
        vector<int> cost(n+1, INT_MAX);
        cost[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       std::greater<pair<int, int>>> Q;
        Q.push({0, k});
        
        while (Q.size() > 0){
            // Find the node with the min distance
            auto [currCost, u] = Q.top(); Q.pop();
            if (color[u] == BLACK) continue;

            color[u] = BLACK;  // Mark as processed
                
            for (auto [v, w]: G[u]){
                if (color[v] == BLACK) continue;
                    
                int newCost = currCost + w;
                if (newCost < cost[v]){
                    cost[v] = newCost;
                    Q.push({newCost, v});                    
                } // end-if
            } // end-for
        } // end-while

        int maxVal = *std::max_element(cost.begin()+1, cost.end());        
        return maxVal == INT_MAX? -1: maxVal;
    } // end-networkDelayTime
};