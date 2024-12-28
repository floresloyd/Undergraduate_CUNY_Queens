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
/// Run Bellman-Ford shortest path algorithm to compute the shortest paths
/// from the given "sourceVertex" to all other vertices
///
struct Edge {
    int u;  
    int v;  // (u, v)
    int weight;
    Edge(int u, int v, int weight): u(u), v(v), weight(weight) {}
}; 

void bellmanFord(vector<Edge> &edges, int sourceVertex, vector<string> &vertexNames){
    enum Color {BLACK, WHITE};

    int n = vertexNames.size();
    vector<int> pred(n, -1);
    int MAX_DIST = INT_MAX/2;
    vector<int> cost(n, MAX_DIST);  // Current distance of the vertex from the source node
    cost[sourceVertex] = 0;

    for (int iter=0; iter<n-1; iter++){
        for (auto [u, v, w]: edges){
            // Relax(u, v)
            int newCost = cost[u] + w;
            if (newCost < cost[v]){
                pred[v] = u;
                cost[v] = newCost;
            } // end-if
        } // end-for         
    } // end-for

    // Print u, cost[u], pred[u], vertices on shortest path
    printf("+---+---------+---------+---------------------------+\n");
    printf("| u | cost[u] | pred[u] | Vertices on shortest path |\n");
    printf("+---+---------+---------+---------------------------+\n");
    for (int u=0; u<n; u++){
        if (pred[u] < 0) continue;
        printf("| %s | %7d | %7s | ", vertexNames[u].c_str(), cost[u], vertexNames[pred[u]].c_str());
        printShortestPath(u, pred, vertexNames);
    }
    printf("+---+---------+---------+---------------------------+\n");
} // end-bellmanFord

int main(){
    // These are the edges of the graph in the slides
#if 0    
    vector<string> vertexNames = {"A", "B", "C", "D", "E"};
    vector<Edge> edges = {
        Edge(0, 1, 2), Edge(0, 2, 1),
        Edge(1, 2, 1),
        Edge(2, 0, 9), Edge(2, 3, 8), Edge(2, 4, 2), 
        Edge(3, 0, 3),
        Edge(4, 3, 3)
    };
    int sourceVertex = 2; // "C"
#else
    vector<string> vertexNames = {"A", "B", "C", "D", "E"};
    vector<Edge> edges = {
        Edge(0, 1, 4), Edge(0, 2, 3),
        Edge(1, 2, -2), Edge(1, 3, 2), Edge(1, 4, -3),
        Edge(2, 3, 1),
        Edge(3, 4, -1)
    };
    int sourceVertex = 0; // "A"
#endif

    bellmanFord(edges, sourceVertex, vertexNames);

    return 0;
}
