class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        #define MAX_NUM 100
        vector<int> LUT1(MAX_NUM+1, 0);
        vector<int> LUT2(MAX_NUM+1, 0);
        vector<int> LUT3(MAX_NUM+1, 0);

        for (auto num: nums1)
            LUT1[num] = 1;
        
        for (auto num: nums2)
            LUT2[num] = 1;
        
        for (auto num: nums3)
            LUT3[num] = 1;

        vector<int> result;
        for (int i=0; i<=MAX_NUM; i++)
            if (LUT1[i]+LUT2[i]+LUT3[i] >= 2)
                result.push_back(i);
        return result;
    }
};