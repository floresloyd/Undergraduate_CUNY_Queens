#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

///-----------------------------------------------------
/// Topological sort using BFS
/// Move in the forward direction by reducing inDegrees
///
void topoSort1(vector<vector<int>> &G, vector<string> &vertexNames){
    int n = G.size();
    vector<int> inDegree(n, 0);
    for (int u=0; u<n; u++){
        for (auto v: G[u])
            inDegree[v]++;
    } // end-for

    queue<int> Q;
    for (int u=0; u<n; u++){
        if (inDegree[u] == 0)
            Q.push(u);   
    } // end-for

    vector<int> result;
    while (Q.size()){
        int u = Q.front();
        Q.pop();
        result.push_back(u);

        for (auto v: G[u]){
            if (--inDegree[v] == 0)
                Q.push(v);
        } // end-for
    } // end-while

    if (result.size() < n) 
        printf("The graph can NOT be topo-sorted!\n");
    else {
        printf("Topo-sorted graph: ");
        for (auto u: result) printf("%s, ", vertexNames[u].c_str());
        printf("\b\b \n");
    } // end-else
} // end-topoSort1

///-----------------------------------------------------
/// Topological sort using DFS
///
enum Color {BLACK, WHITE};

void topoVisit(int u, vector<vector<int>> &G, vector<Color> &color, vector<int> &result){
    color[u] = BLACK;
    for (auto v: G[u]){
        if (color[v] == WHITE){
            topoVisit(v, G, color, result);
        } // end-if
    } // end-for
    result.push_back(u);
} // end-topoVisit

void topoSort2(vector<vector<int>> &G, vector<string> &vertexNames){
    int n = G.size();
    vector<int> result;
    vector<Color> color(n, WHITE);

    for (int u=0; u<n; u++){
        if (color[u] == WHITE)
            topoVisit(u, G, color, result);
    } // end-for

    // Reverse the final list to obtain the result
    std::reverse(result.begin(), result.end());

    if (result.size() < n) 
        printf("The graph can NOT be topo-sorted!\n");
    else {
        printf("Topo-sorted graph: ");
        for (auto u: result) printf("%s, ", vertexNames[u].c_str());
        printf("\b\b \n");
    } // end-else
} // end-topoSort2

///-------------------------------------------------------
int main(){
#if 1
    vector<string> vertexNames = {"a", "b", "c", "d", "e", "f"};
    int n = vertexNames.size();
    vector<vector<int>> edges = {
        {0, 1}, {0, 2},
        {1, 2}, 
        {2, 3}, {2, 4},
        {3, 4}
    };
#elif 0
    vector<string> vertexNames = {"shorts", "pants", "belt", "shirt", "tie", "jacket", "socks", "shoes"};
    int n = vertexNames.size();
    vector<vector<int>> edges = {
        {0, 1}, {0, 6},
        {1, 2}, {1, 6},
        {2, 5},
        {3, 4}, {3, 2},
        {4, 5},
        {6, 7}
    };
#else
    vector<string> vertexNames =  {"111", "123", "201", "306", "427", "213", "304", "446", "205", "220", "302", "402"};
    int n = vertexNames.size();
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2}, {1, 5}, {1, 8},
        {2, 3},
        {3, 4},
        {5, 3}, {5, 6},
        {6, 7},
        {8, 9},
        {9, 10},
        {10, 11}
    };
#endif    
    vector<vector<int>> G(n);

    for (auto &edge: edges){
        // directed edge
        int u = edge[0];
        int v = edge[1];
        G[u].push_back(v);
    } // end-for

    topoSort1(G, vertexNames);
    printf("-------------------------------------------------\n");
    topoSort2(G, vertexNames);

    return 0;
} // end-main