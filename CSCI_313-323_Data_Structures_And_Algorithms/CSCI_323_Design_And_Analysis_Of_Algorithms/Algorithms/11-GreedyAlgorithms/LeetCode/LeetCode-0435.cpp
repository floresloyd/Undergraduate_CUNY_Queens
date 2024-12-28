class Solution {
public:
    static bool compare(vector<int> &left, vector<int> &right){
        return left[1] < right[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        std::sort(intervals.begin(), intervals.end(), compare);
        std::sort(intervals.begin(), intervals.end(), 
                  [&](auto &left, auto &right){return left[1] < right[1];});
        
        int count = 0;
        int time = intervals[0][1];
        for (int i=1; i<intervals.size(); i++){
            if (intervals[i][0] < time)
                count++;
            else 
                time = intervals[i][1];
        } // end-for
        
        return count;
    } // end-eraseOverlapIntervals
};