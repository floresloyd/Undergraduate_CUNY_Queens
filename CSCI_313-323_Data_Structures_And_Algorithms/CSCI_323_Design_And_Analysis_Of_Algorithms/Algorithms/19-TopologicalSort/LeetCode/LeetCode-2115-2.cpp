class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> G(n);       
        unordered_map<string, int> R;
        unordered_set<string> S(supplies.begin(), supplies.end());

        for (int i=0; i<n; i++)
            R[recipes[i]] = i;
            
        for (int i=0; i<n; i++){
            auto &recipe = recipes[i];
            for (string &ingredient: ingredients[i]){
                if (R.count(ingredient) != 0){
                    G[R[ingredient]].push_back(i);
                    inDegree[i]++;
                } else if (S.count(ingredient) == 0)
                    inDegree[i] = INT_MAX;
            } // end-for
        } // end-for 
        
        queue<int> Q;
        for (int i=0; i<n; i++)
            if (inDegree[i] == 0)
                Q.push(i);
        
        vector<string> result;
        while (Q.size()){
            auto u = Q.front(); Q.pop();
            result.push_back(recipes[u]);
            
            for (auto v: G[u])
                if (--inDegree[v] == 0)
                    Q.push(v);
        } // end-while
        return result;
    } // end-findAllRecipes
};