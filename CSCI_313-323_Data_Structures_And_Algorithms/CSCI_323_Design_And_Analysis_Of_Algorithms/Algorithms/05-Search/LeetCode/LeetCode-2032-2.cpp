class Solution {
public:
    void countFreqs(vector<int> &nums, unordered_map<int, int> &freq){
        unordered_set<int> mySet;        // numbers with no duplicates
        for (auto num: nums){
            if (mySet.count(num) > 0) continue;            
            mySet.insert(num);
            freq[num]++;
        } // end-for
    } // end-countFreqs

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        /*
        O(max(k, m, n)) algorithm with O(k, m, n) extra space, where
        k = len(nums1), m = len(nums2), n = len(nums3)
        */        
        unordered_map<int, int> freq;
        countFreqs(nums1, freq);
        countFreqs(nums2, freq);
        countFreqs(nums3, freq);
        
        vector<int> result;
        for (auto iter: freq){
            if (iter.second >= 2)
                result.push_back(iter.first);
        } // end-for
        
        return result;    
    } // end-twoOutOfThree
};