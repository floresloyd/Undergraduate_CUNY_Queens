class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<int> dist;
        for (auto &p: points){
            dist.push_back(p[0]*p[0] + p[1]*p[1]);                    
        } // end-for

        std::nth_element(dist.begin(), dist.begin()+k-1, dist.end()); 
        int max_dist = dist[k-1];

        vector<vector<int>> result;
        for (auto &p: points){
            if (p[0]*p[0] + p[1]*p[1] <= max_dist)
                result.push_back(p);
        } // end-for
        return result;
    } // end-kClosest
};