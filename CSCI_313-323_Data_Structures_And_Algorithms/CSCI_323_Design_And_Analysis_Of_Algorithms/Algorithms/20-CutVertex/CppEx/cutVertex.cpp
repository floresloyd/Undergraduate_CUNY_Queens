#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

enum Color {BLACK, GRAY, WHITE};

int currTime = 0; // Global time

void dfs(int u, vector<vector<int>> &G, vector<Color> &color, 
        vector<int> &d, vector<int> &low, vector<int> &pred, 
        unordered_set<int> &result){
    color[u] = GRAY;
    d[u] = low[u] = ++currTime;

    int child = 0;
    for (auto v: G[u]){
        if (color[v] == WHITE){
            child++;
            pred[v] = u;            

            dfs(v, G, color, d, low, pred, result);

            low[u] = std::min(low[u], low[v]);

            if (pred[u] < 0){
                // root
                if (child >= 2) result.insert(u); // root is an articulation point

            } else if (d[u] <= low[u]){
                // internal node: No back edge from any of the descendants to any of the ancestors
                result.insert(u);
            } // end-else

        } else if (v != pred[u]){  // This check is to skip the edge to parent
            // back edge
            low[u] = std::min(low[u], d[v]);
        } // end-else
    } // end-for
    color[u] = BLACK;
} // end-dfs

void cutVertex(vector<vector<int>> &G, vector<string> &vertexNames){
    int n = G.size();
    unordered_set<int> result;
    vector<Color> color(n, WHITE);
    vector<int> pred(n, -1);
    vector<int> d(n);
    vector<int> low(n);

    dfs(0, G, color, d, low, pred, result);

    printf("Articulation points are: ");
    for (auto u: result) printf("%s, ", vertexNames[u].c_str());
    printf("\b\b \n");
} // end-cutVertex

///-------------------------------------------------------
int main(){
    vector<string> vertexNames = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    vector<vector<int>> edges = {
        {0, 1}, {0, 4}, {0, 5},
        {1, 2}, {1, 5},
        {2, 3}, {2, 5}, {2, 6},
        {3, 7},
        {4, 8}, {4, 9},
        {6, 7},  // If we remove this edge, then "d" also becomes an articulation point
        {8, 9}
    };
    int n = vertexNames.size();
    vector<vector<int>> G(n);

    for (auto &edge: edges){
        // undirected edge
        int u = edge[0];
        int v = edge[1];
        G[u].push_back(v);
        G[v].push_back(u);
    } // end-for

    cutVertex(G, vertexNames);

    return 0;
} // end-main