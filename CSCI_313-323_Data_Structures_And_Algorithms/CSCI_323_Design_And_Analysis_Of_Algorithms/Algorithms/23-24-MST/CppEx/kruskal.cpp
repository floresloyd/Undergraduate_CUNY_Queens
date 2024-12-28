#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/// Disjoint set class
class DS {
    vector<int> sets;
    int numSets;
public:
    DS(int n){sets.resize(n, -1); numSets = n;}
    
    // Find set with path compression
    int find(int u){
        if (sets[u] < 0) return u;
        
        int s = find(sets[u]);
        sets[u] = s;
        return s;
    } // end-findSet
    
    void join(int u, int v){
        if (sets[u] >= 0) u = find(u);
        if (sets[v] >= 0) v = find(v);
        if (u == v) return;

        numSets--;
        if (sets[u] < sets[v]){
            sets[u] += sets[v];
            sets[v] = u;
        } else {
            sets[v] += sets[u];
            sets[u] = v;
        } //end-else
    } // end-join
    
    // Assume that "u" is a valid set head
    int size(int u){return -sets[u];}    
    int numberOfSets(){return numSets;}
    int numberOfElements(){return sets.size();}
}; // end-DS

///-------------------------------------------------
/// Run Kruskal's algorithm to compute the MST
///
struct Edge {
    int u;
    int v;  // (u, v)
    int weight;
    Edge(int u, int v, int weight): u(u), v(v), weight(weight) {}
};

void kruskal(vector<Edge> &edges, vector<string> &vertexNames){
    std::sort(edges.begin(), edges.end(), 
        [](Edge &one, Edge &two){
            return one.weight < two.weight;
        });
    
    int n = vertexNames.size();
    DS ds(n);
    vector<Edge> mst;
    for (auto &edge: edges){
        int u = edge.u;
        int v = edge.v;

        if (ds.find(u) != ds.find(v)){
            ds.join(u, v);
            mst.push_back(edge);
        } // end-if
    } // end-for

    printf("MST edges: \n");
    int mstCost = 0;
    for (auto &edge: mst){
        printf("  (%s, %s, %d)\n", vertexNames[edge.u].c_str(), vertexNames[edge.v].c_str(), edge.weight);
        mstCost += edge.weight;
    } // end-for
    printf("Total cost of the MST: %d\n", mstCost);
} // end-kruskal

int main(){
    // These are the edges of the graph in the slides
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
    kruskal(edges, vertexNames);

    return 0;
}
