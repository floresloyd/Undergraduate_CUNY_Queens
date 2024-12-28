#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

void dfsVisit(int u, vector<unordered_set<int>> &G, vector<int> &result){
    while (G[u].size()){
        int v = *G[u].begin();   // Take the first vertex in the set
        G[u].erase(v);           // Delete the edge from G[u]
        G[v].erase(u);           // Delete the edge from G[v]
        dfsVisit(v, G, result);
    } // end-for
    result.push_back(u);
} // end-dfsVisit

void eulerCircuit(vector<unordered_set<int>> &G, vector<string> &vertexNames){
    int n = G.size();
    vector<int> result;

    dfsVisit(0, G, result);

    // Reverse the final list to obtain the result
    std::reverse(result.begin(), result.end());

    printf("Euler circuit: ");
    for (auto u: result) printf("%s, ", vertexNames[u].c_str());
    printf("\b\b \n");
} // end-topoSort2

///-------------------------------------------------------
int main(){
#if 1
    vector<string> vertexNames = {"A", "B", "C", "D", "E", "F", "G"};
    int n = vertexNames.size();
    vector<vector<int>> edges = {
        {0, 1}, {0, 2},
        {1, 2}, {1, 3}, {1, 6},
        {2, 4}, {2, 6},
        {3, 4}, {3, 5}, {3, 6},
        {4, 5}, {4, 6}
    };
#else
    vector<string> vertexNames = {"A", "B", "C", "D", "E"};
    int n = vertexNames.size();
    vector<vector<int>> edges = {
        {0, 1}, {0, 2},
        {1, 2}, {1, 3}, {1, 4},
        {2, 3}, {2, 4}
    };
#endif

    // Represent the edges as a HashSet for fast deletion
    vector<unordered_set<int>> G(n);
    for (auto &edge: edges){
        // undirected edge
        int u = edge[0];
        int v = edge[1];
        G[u].insert(v);
        G[v].insert(u);
    } // end-for

    eulerCircuit(G, vertexNames);

    return 0;
} // end-main