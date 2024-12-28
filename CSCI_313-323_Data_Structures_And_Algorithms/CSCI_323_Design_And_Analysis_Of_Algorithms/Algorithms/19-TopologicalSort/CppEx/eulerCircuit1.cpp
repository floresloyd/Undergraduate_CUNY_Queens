#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

void dfsVisit(int u, vector<vector<bool>> &G, vector<int> &result){
    int n = G.size();
    for (int v=0; v<n; v++){
        if (G[u][v]){
            G[u][v] = false;  // Erase (u, v)
            G[v][u] = false;  // Erase (v, u)
            dfsVisit(v, G, result);
        } // end-if
    } // end-for
    result.push_back(u);
} // end-dfsVisit

void eulerCircuit(vector<vector<bool>> &G, vector<string> &vertexNames){
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
#if 0
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

    // Represent the graph with adjacency matrix
    vector<vector<bool>> G(n, vector<bool>(n, false));
    for (auto &edge: edges){
        // undirected edge
        int u = edge[0];
        int v = edge[1];
        G[u][v] = true;
        G[v][u] = true;
    } // end-for

    eulerCircuit(G, vertexNames);

    return 0;
} // end-main