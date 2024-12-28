class Solution {
public:
    /// O(n) algorithm with O(n) extra space
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        //           <string, index of the vector of this anagram in result>
        unordered_map<string, int> anagrams;

        for (auto &origStr: strs){
            string str = origStr;
            std::sort(str.begin(), str.end());

            if (anagrams.count(str))
                result[anagrams[str]].push_back(origStr);
            else {
                result.push_back({origStr});
                anagrams[str] = result.size()-1;  // Index of the vector
            } // end-else
        } // end-for

        return result;
    } // end-groupAnagrams
};