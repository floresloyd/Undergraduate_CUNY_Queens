#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

enum Color {BLACK, GRAY, WHITE};

int currTime = 0; // Global time counter

void dfsVisit(int u, vector<vector<int>> &G, vector<Color> &color, 
              vector<int> &d, vector<int> &f){
    color[u] = GRAY;
    d[u] = ++currTime;

    for (auto v: G[u]){
        if (color[v] == WHITE){
            dfsVisit(v, G, color, d, f);
        } // end-if
    } // end-for

    color[u] = BLACK;
    f[u] = ++currTime;
} // end-dfsVisit

void dfsVisit2(int u, vector<vector<int>> &R, vector<Color> &color, 
              vector<vector<int>> &scc){
    color[u] = GRAY;
    scc.back().push_back(u);

    for (auto v: R[u]){
        if (color[v] == WHITE){
            dfsVisit2(v, R, color, scc);
        } // end-if
    } // end-for

    color[u] = BLACK;
} // end-dfsVisit2


///--------------------------------------------------------------
/// Runs the stronly connected components algorithm
///
void stronglyConnectedComponents(vector<vector<int>> &G, vector<string> &vertexNames){
    /// 1. Run DFS(G), Computing finish time f[u] for each vertex u;
    int n = G.size();
    vector<Color> color(n, WHITE);
    vector<int> d(n);
    vector<int> f(n);

    for (int u=0; u<n; u++){
        if (color[u] == WHITE)
            dfsVisit(u, G, color, d, f);
    } // end-for

    /// 2. Compute R = Reverse(G), reversing all edges of G;
    vector<vector<int>> R(n);
    for (int u=0; u<n; u++){
        for (auto v: G[u]){
            // (u, v) in G --> (v, u) in R
            R[v].push_back(u);
        } // end-for
    } // end-for

    /// 3. Sort the vertices of R (by count sort) in decreasing order of f[u];
    ///    For simplicity, I will sort the vertices using std::sort
    vector<int> I(n);
    for (int i=0; i<n; i++) I[i] = i;
    std::sort(I.begin(), I.end(), 
        [&](int one, int two){
            return f[one] > f[two];
        });

    /// 4. Run DFS(R) using this order. Each DFS tree is a strong component; 
    for (int u=0; u<n; u++) color[u] = WHITE;

    vector<vector<int>> scc;
    for (int i=0; i<n; i++){
        int u = I[i];
        if (color[u] == BLACK) continue;
        scc.push_back({});
        dfsVisit2(u, R, color, scc);
    } // end-for

    /// Print the verices in each strongly connected component
    printf("We have %d strongly connected components\n", scc.size());
    for (int i=0; i<scc.size(); i++){
        printf("Component[%d] vertices: {", i+1);
        for (auto v: scc[i]) printf("%s, ", vertexNames[v].c_str());
        printf("\b\b}\n");
    } // end-for
} // end-stronglyConnectedComponents

int main(){
    // Edges of the graph shown in the slides
    vector<string> vertexNames = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {0, 6},
        {1, 2}, {1, 5},
        {2, 0},
        {3, 4},
        {4, 3}, {4, 6},
        {5, 6},
        {6, 8},
        {7, 8},
        {8, 7}, {8, 5}
    };
    int n = vertexNames.size();
    vector<vector<int>> G(n);

    for (auto &edge: edges){
        // directed edge
        int u = edge[0];
        int v = edge[1];
        G[u].push_back(v);
    } // end-for

    stronglyConnectedComponents(G, vertexNames);

    return 0;
} // end-main