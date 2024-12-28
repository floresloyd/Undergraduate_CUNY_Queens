#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INFINITY (INT_MAX/2)

void shortestPath(int i, int j, vector<vector<int>> &pred, vector<int> &nodes){
    if (pred[i][j] < 0){
        // Shortest path is edge
        nodes.push_back(i);
        nodes.push_back(j);
    } else {
        shortestPath(i, pred[i][j], pred, nodes);
        shortestPath(pred[i][j], j, pred, nodes);
    } // end-else
} // end-shortestPath

///--------------------------------------------------------------------------
/// Run Floyd-Warshall algorithm to compute the shortest paths between
/// each pair of vertices
///
void floydWarshall(vector<vector<int>> &G, vector<string> &vertexNames){
    int n = G.size();
    vector<vector<int>> pred(n, vector<int>(n, -1));
    vector<vector<int>> D = G;

    for (int k=0; k<n; k++){      // Intermediate {0,2,..,k}
		for (int i=0; i<n; i++){  // consider all i, j
            for (int j=0; j<n; j++){
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];    // new shorter path length
					pred[i][j] = k;                 // new path is through k
				} //end-if
			} //end-for
		} //end-for
	} //end-for

    printf("+--------+------+------+---------------------------+\n");
    printf("| Source | Dest | Cost | Vertices on shortest path |\n");
    printf("+--------+------+------+---------------------------+\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j) continue;
            printf("| %6s | %4s |", vertexNames[i].c_str(), vertexNames[j].c_str());

            if (D[i][j] == INFINITY){
                printf("  INF | \n");                
            } else {
                printf(" %4d | ", D[i][j]);
                vector<int> path;
                shortestPath(i, j, pred, path);
                printf("%s->", vertexNames[path[0]].c_str());
                for (int i=1; i<path.size()-1; i+=2)
                    printf("%s->", vertexNames[path[i]].c_str());
                printf("%s\n", vertexNames[path.back()].c_str());
            } // end-else
        } // end-for
    } // end-for
    printf("+--------+------+------+------------------------------+\n");
} // end-floydWarshall

int main(){
    // These are the edges of the graph in the slides
    struct Edge {
        int u;  
        int v;  // (u, v)
        int weight;
        Edge(int u, int v, int weight): u(u), v(v), weight(weight) {}
    }; 

#if 1
    vector<string> vertexNames = {"A", "B", "C", "D"};
    vector<Edge> edges = {
        Edge(0, 1, 8), Edge(0, 3, 1),
        Edge(1, 2, 1),
        Edge(2, 0, 4),
        Edge(3, 1, 2), Edge(3, 2, 9)
    };
#else
    // Vertex "E" is NOT reachable from any of the other vertices
    vector<string> vertexNames = {"A", "B", "C", "D", "E"};
    vector<Edge> edges = {
        Edge(0, 1, 8), Edge(0, 3, 1),
        Edge(1, 2, 1),
        Edge(2, 0, 4),
        Edge(3, 1, 2), Edge(3, 2, 9),
        Edge(4, 3, 1)
    };
#endif    
    int n = vertexNames.size();
    vector<vector<int>> G(n, vector<int>(n, INFINITY));
    for (int i=0; i<n; i++) G[i][i] = 0; // diagonal

    for (auto &edge: edges){
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        // directed graph
        G[u][v] = weight;
    } // end-for

    floydWarshall(G, vertexNames);

    return 0;
}
