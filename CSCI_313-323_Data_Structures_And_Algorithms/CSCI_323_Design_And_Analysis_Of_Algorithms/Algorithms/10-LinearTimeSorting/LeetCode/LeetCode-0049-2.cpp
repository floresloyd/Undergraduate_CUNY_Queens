class Solution {
public:
    /// O(n) algorithm with O(n) extra space
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //           <string, indices of all anagrams
        unordered_map<string, vector<int>> anagrams;

        for (int i=0; i<strs.size(); i++){
            string str = strs[i];
            std::sort(str.begin(), str.end());
            anagrams[str].push_back(i);
        } // end-for

        vector<vector<string>> result;
        for (auto &[_, indices]: anagrams){
            result.push_back({});
            for (auto idx: indices)
                result.back().push_back(strs[idx]);
        } // end-for

        return result;
    } // end-groupAnagrams
};