#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

void printShortestPath(vector<int> &pred, int u){
    vector<int> path;
    while (u != -1){
        path.push_back(u);
        u = pred[u];
    } // end-while

    printf("[");
    for (auto iter=path.rbegin(); iter != path.rend(); ++iter)
        printf("%d->", *iter);
    printf("\b\b] \n");
} // end-printShortestPath

///---------------------------------------
/// Run BFS starting at vertex "s"
///
void bfs(vector<vector<int>> &G, int s){
    enum Color {BLACK, GRAY, WHITE};
    int n = G.size();
    vector<Color> color(n, WHITE);
    vector<int> d(n, INT_MAX);
    vector<int> pred(n, -1);

    queue<int> Q;
    Q.push(s);
    color[s] = GRAY;

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();

        for (auto v: G[u]){
            if (color[v] == WHITE){
                color[v] = GRAY;
                pred[v] = u;
                d[v] = d[u] + 1;
                Q.push(v);
            } // end-if
        } // end-for

        color[u] = BLACK;
    } // end-while

    // Print u, d[u], pred[u], vertices on shortest path
    printf("+---+------+---------+---------------------------+\n");
    printf("| u | d[u] | pred[u] | Vertices on shortest path |\n");
    printf("+---+------+---------+---------------------------+\n");
    for (int u=0; u<n; u++){
        if (pred[u] < 0) continue;
        printf("| %d | %4d | %7d | ", u, d[u], pred[u]);
        printShortestPath(pred, u);
    }
    printf("+---+------+---------+---------------------------+\n");
} // end-bfs

///---------------------------------------
/// Another way to code BFS starting at "s"
/// Process one level of nodes at each iteration of the inner while loop
///
void bfs2(vector<vector<int>> &G, int s){
    enum Color {WHITE, GRAY, BLACK};
    int n = G.size();
    vector<Color> color(n, WHITE);
    vector<int> d(n, INT_MAX);
    vector<int> pred(n, -1);

    queue<int> Q;
    Q.push(s);
    color[s] = GRAY;

    int level = 0;
    while (!Q.empty()){
        int size = Q.size();  // # of nodes at this level
        printf("Nodes at level %d: [", level);

        level += 1;           // Distance of the nodes at this level from the source

        // Process all nodes at this level within this inner loop
        while (size--){
            int u = Q.front();
            Q.pop();
            printf("%d, ", u);

            for (auto v: G[u]){
                if (color[v] == WHITE){
                    color[v] = GRAY;
                    pred[v] = u;
                    d[v] = level;
                    Q.push(v);
                } // end-if
            } // end-for

            color[u] = BLACK;
        } // end-while
        printf("\b\b] \n");
    } // end-while

    // Print u, d[u], pred[u], shortest path from the source node
    printf("+---+------+---------+---------------------------+\n");
    printf("| u | d[u] | pred[u] | Shortest path from source |\n");
    printf("+---+------+---------+---------------------------+\n");
    for (int u=0; u<n; u++){
        printf("| %d | %4d | %7d | ", u, d[u], pred[u]);
        printShortestPath(pred, u);
    }
    printf("+---+------+---------+---------------------------+\n");
} // end-bfs2

int main(){
    int n = 10; // 10 vertices [0-9]
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 4}, {1, 5},
        {2, 5}, {2, 6}, {2, 7},
        {3, 7},
        {4, 8},
        {5, 8},
        {6, 8},
        {8, 9}
    };
    vector<vector<int>> G(n);

    for (auto &edge: edges){
        // undirected edge
        int u = edge[0];
        int v = edge[1];
        G[u].push_back(v);
        G[v].push_back(u);
    } // end-for

//    bfs(G, 0);
    bfs2(G, 0);

    return 0;
} // end-main