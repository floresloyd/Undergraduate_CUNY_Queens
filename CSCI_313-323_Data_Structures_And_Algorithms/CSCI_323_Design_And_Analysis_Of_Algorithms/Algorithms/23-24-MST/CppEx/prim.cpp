#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

///-------------------------------------------------
/// Run Prims's algorithm to compute the MST
///
void prim(vector<vector<pair<int, int>>> &G, vector<string> &vertexNames){
    enum Color {BLACK, WHITE};

    int n = G.size();
    vector<Color> color(n, WHITE);
    vector<int> pred(n, -1);
    vector<int> cost(n, INT_MAX);  // Current cost of the vertex in PQ
    cost[0] = 0;

    // Create a min PQ that stores {currCost, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> Q;
    Q.push({0, 0});

    while (!Q.empty()){
        auto [_, u] = Q.top();
        Q.pop();

        if (color[u] == BLACK) continue;  // Already processed
        color[u] = BLACK;

        for (auto [v, weight]: G[u]){
            if (color[v] == WHITE && weight < cost[v]){
                cost[v] = weight;
                Q.push({weight, v});
                pred[v] = u;
            } // end-if
        } // end-for
    } // end-while

    printf("MST edges: \n");
    int mstCost = 0;
    for (int u=0; u<n; u++){
        if (pred[u] < 0) continue;
        printf("  (%s, %s, %d)\n", vertexNames[pred[u]].c_str(), vertexNames[u].c_str(), cost[u]);
        mstCost += cost[u];
    } // end-for
    printf("Total cost of the MST: %d\n", mstCost);
} // end-prim

int main(){
    // These are the edges of the graph in the slides
    struct Edge {
        int u;  
        int v;  // (u, v)
        int weight;
        Edge(int u, int v, int weight): u(u), v(v), weight(weight) {}
    };

    vector<string> vertexNames = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    vector<Edge> edges = {
        Edge(0, 1, 4), Edge(0, 7, 8),
        Edge(1, 7, 11), Edge(1, 2, 8),
        Edge(2, 3, 7), Edge(2, 5, 4), Edge(2, 8, 2),
        Edge(3, 4, 9), Edge(3, 5, 14),
        Edge(4, 5, 10),
        Edge(5, 6, 2),
        Edge(6, 7, 1), Edge(6, 8, 6),
        Edge(7, 8, 7)
    };
    int n = vertexNames.size();
                // <vertex, weight>
    vector<vector<pair<int, int>>> G(n);

    for (auto &edge: edges){
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        // undirected graph
        G[u].push_back({v, weight});
        G[v].push_back({u, weight});
    } // end-for

    prim(G, vertexNames);

    return 0;
}
