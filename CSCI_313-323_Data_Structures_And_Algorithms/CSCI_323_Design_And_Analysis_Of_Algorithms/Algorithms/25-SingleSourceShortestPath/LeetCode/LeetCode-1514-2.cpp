class Solution {
public:
    /// Bellman-Ford algorithm. Gets TLE
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {       
        vector<double> cost(n, 0);            
        cost[start] = 1.0;

        for (int iter=0; iter<n-1; iter++){
            for (int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                double p = succProb[i];                
                cost[v] = std::max(cost[v], cost[u]*p); // Relax(u, v)
                cost[u] = std::max(cost[u], cost[v]*p); // Relax(v, u)
            } // end-for         
        } // end-for

        return cost[end];
    } // end-maxProbability
};