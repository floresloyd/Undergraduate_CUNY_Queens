#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void printShortestPath(int u, vector<int> &pred, vector<string> &vertexNames){
    vector<int> path;
    while (u != -1){
        path.push_back(u);
        u = pred[u];
    } // end-while

    printf("[");
    for (auto iter=path.rbegin(); iter != path.rend(); ++iter)
        printf("%s->", vertexNames[*iter].c_str());
    printf("\b\b] \n");
} // end-printShortestPath

///--------------------------------------------------------------------------
/// Run Dijkstra's shortes path algorithm to compute the shortest paths
/// from the given "sourceVertex" to all other vertices
///
void dijkstra(vector<vector<pair<int, int>>> &G, int sourceVertex, vector<string> &vertexNames){
    enum Color {BLACK, WHITE};

    int n = G.size();
    vector<Color> color(n, WHITE);
    vector<int> pred(n, -1);
    vector<int> cost(n, INT_MAX);  // Current distance of the vertex from the source node
    cost[sourceVertex] = 0;

    // Create a min PQ that stores {currDist, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> Q;
    Q.push({0, sourceVertex});

    while (!Q.empty()){
        auto [currCost, u] = Q.top();
        Q.pop();

        if (color[u] == BLACK) continue;  // Already processed
        color[u] = BLACK;

        for (auto [v, weight]: G[u]){
            if (color[v] == BLACK) continue; // Already processed

            // Relax(u, v)
            int newCost = currCost + weight;
            if (newCost < cost[v]){
                pred[v] = u;
                cost[v] = newCost;
                Q.push({newCost, v});
            } // end-if
        } // end-for
    } // end-while

    // Print u, cost[u], pred[u], vertices on the shortest path
    printf("+---+---------+---------+---------------------------+\n");
    printf("| u | cost[u] | pred[u] | Vertices on shortest path |\n");
    printf("+---+---------+---------+---------------------------+\n");
    for (int u=0; u<n; u++){
        if (pred[u] < 0) continue;
        printf("| %s | %7d | %7s | ", vertexNames[u].c_str(), cost[u], vertexNames[pred[u]].c_str());
        printShortestPath(u, pred, vertexNames);
    }
    printf("+---+---------+---------+---------------------------+\n");
} // end-dijksra

int main(){
    // These are the edges of the graph in the slides
    struct Edge {
        int u;  
        int v;  // (u, v)
        int weight;
        Edge(int u, int v, int weight): u(u), v(v), weight(weight) {}
    }; 

    vector<string> vertexNames = {"A", "B", "C", "D", "E"};
    vector<Edge> edges = {
        Edge(0, 1, 2), Edge(0, 2, 1),
        Edge(1, 2, 1),
        Edge(2, 0, 9), Edge(2, 3, 8), Edge(2, 4, 2), 
        Edge(3, 0, 3),
        Edge(4, 3, 3)
    };
    int n = vertexNames.size();
                // <vertex, weight>
    vector<vector<pair<int, int>>> G(n);

    for (auto &edge: edges){
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        // directed graph
        G[u].push_back({v, weight});
    } // end-for

    int sourceVertex = 2; // "C"
    dijkstra(G, sourceVertex, vertexNames);

    return 0;
}
