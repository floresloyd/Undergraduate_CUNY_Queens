class Solution {
public:
    // O(n) algorithm with O(1) extra space
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::nth_element(points.begin(), points.begin()+k, points.end(),
            [&](vector<int> &p1, vector<int> &p2){
                int d1 = p1[0]*p1[0] + p1[1]*p1[1];
                int d2 = p2[0]*p2[0] + p2[1]*p2[1];
                return d1 < d2;
            }); 
        return {points.begin(), points.begin()+k};
    } // end-kClosest
};