#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

enum Color {BLACK, GRAY, WHITE};

int currTime = 0; // Global time counter

void dfsVisit(int u, vector<vector<int>> &G, vector<Color> &color, 
              vector<int> &d, vector<int> &f, vector<int> &pred){
    color[u] = GRAY;
    d[u] = ++currTime;

    for (auto v: G[u]){
        if (color[v] == WHITE){
            pred[v] = u;
            dfsVisit(v, G, color, d, f, pred);
        } // end-if
    } // end-for

    color[u] = BLACK;
    f[u] = ++currTime;
} // end-dfsVisit

void dfs(vector<vector<int>> &G){
    int n = G.size();
    vector<Color> color(n, WHITE);
    vector<int> d(n);
    vector<int> f(n);
    vector<int> pred(n, -1);

    for (int u=0; u<n; u++){
        if (color[u] == WHITE)
            dfsVisit(u, G, color, d, f, pred);
    } // end-for

    // Print u, d[u], f[u], pred[u]
    printf("+---+------+------+---------+\n");
    printf("| u | d[u] | f[u] | pred[u] |\n");
    printf("+---+------+------+---------+\n");
    for (int u=0; u<n; u++){
        printf("| %d | %4d | %4d | %7d |\n", u, d[u], f[u], pred[u]);
    } // end-for
    printf("+---+------+------+---------+\n");
} // end-dfs

int main(){
    int n = 10; // 10 vertices [0-9]
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 5},
        {1, 4}, {1, 5},
        {2, 5}, {2, 6},
        {3, 7},
        {4, 8},
        {5, 8},
        {6, 8},
        {7, 9},
        {8, 9},
        {9, 4}
    };
    vector<vector<int>> G(n);

    for (auto &edge: edges){
        // directed edge
        int u = edge[0];
        int v = edge[1];
        G[u].push_back(v);
    } // end-for

    dfs(G);

    return 0;
} // end-main