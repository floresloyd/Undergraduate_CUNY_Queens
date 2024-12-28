class Solution {
    void dfs(string &u, unordered_map<string, vector<string>> &G, vector<string> &result){
        while (G[u].size()){
            auto v = G[u].back();
            G[u].pop_back();
            dfs(v, G, result);
        } // end-while
        result.push_back(u);
    } // end-dfs
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        unordered_map<string, vector<string>> G;
    
        for (auto &ticket: tickets){
            string &u = ticket[0];
            string &v = ticket[1];
            G[u].push_back(v);
        } // end-for
    
        for (auto &[_, v]: G)
            std::sort(v.begin(), v.end(), std::greater());
    
        vector<string> result;
        string s = "JFK";
        dfs(s, G, result);    
        std::reverse(result.begin(), result.end());
        return result;
    } // end-findItinerary
};