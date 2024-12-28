class Solution {
public:
    ///---------------------------------------------------------
    /// This is basically the same problem as 435
    /// Simply sort the points wrt their finish times & 
    /// find the number of intervals that dont overlap
    ///
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), 
                  [&](auto &left, auto &right){return left[1] < right[1];});
        
        int count = 1;
        int time = points[0][1];
        for (int i=1; i<points.size(); i++){
            if (points[i][0] <= time) continue;
            count++;
            time = points[i][1];
        } // end-for
        
        return count;        
    } // end-findMinArrowShots
};