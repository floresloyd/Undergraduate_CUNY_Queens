class Solution {
public:
    /// O(nlogn) algorithm with O(n) extra space
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strs2 = strs;

        for (auto &str: strs2)
            std::sort(str.begin(), str.end());

        int n = strs.size();
        vector<int> I(n);
        for (int i=0; i<n; i++) I[i] = i;

        std::sort(I.begin(), I.end(), 
            [&](int one, int two){
                return strs2[one] < strs2[two];
            });

        vector<vector<string>> result;
        result.push_back({strs[I[0]]});        
        for (int i=1; i<n; i++){
            if (strs2[I[i]] == strs2[I[i-1]])
                result.back().push_back(strs[I[i]]);
            else
                result.push_back({strs[I[i]]});
        } // end-for
        return result;
    } // end-groupAnagrams
};