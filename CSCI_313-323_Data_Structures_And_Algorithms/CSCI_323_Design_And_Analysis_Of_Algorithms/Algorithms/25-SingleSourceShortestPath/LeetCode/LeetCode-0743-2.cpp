class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /// This time we run the Bellmann-Ford algorithm
        int maxCost = INT_MAX/2;
        vector<int> cost(n+1, maxCost);
        cost[k] = 0;
        
        for (int iter=0; iter<n-1; iter++){
            for (int i=0; i<times.size(); i++){
                int u = times[i][0];
                int v = times[i][1];
                int w = times[i][2];
                
                cost[v] = min(cost[v], cost[u]+w); // Relax(u, v)
            } // end-for         
        } // end-for
        
        int maxVal = *std::max_element(cost.begin()+1, cost.end());        
        return maxVal == maxCost? -1: maxVal;
    } // end-for
};