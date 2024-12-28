class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> G;        
        unordered_set<string> S(supplies.begin(), supplies.end());
                
        for (auto recipe: recipes){
            G[recipe] = vector<string>{};
            inDegree[recipe] = 0;
        } // end-for
            
        for (int i=0; i<recipes.size(); i++){
            auto &recipe = recipes[i];
            for (string &ingredient: ingredients[i]){
                if (G.count(ingredient) != 0){
                    G[ingredient].push_back(recipe);
                    inDegree[recipe]++;
                } else if (S.count(ingredient) == 0)
                    inDegree[recipe] = INT_MAX;
            } // end-for
        } // end-for 
        
        queue<string> Q;
        for (auto [recipe, degree]: inDegree){
            if (degree == 0)
                Q.push(recipe);
        } // end-for
        
        vector<string> result;
        while (Q.size()){
            auto recipe = Q.front(); Q.pop();
            result.push_back(recipe);
            
            for (auto v: G[recipe])
                if (--inDegree[v] == 0)
                    Q.push(v);
        } // end-while
        return result;
    } // end-findAllRecipes
};