#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
        int n = g_nodes+1;  // Nodes are numbered from 1..n
        vector<vector<pair<int, int>>> G(n);
    
        for (int i=0; i<g_from.size(); i++){
            int u = g_from[i];
            int v = g_to[i];
            int w = g_weight[i];
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        } // end-for

        enum Color {BLACK, WHITE};           
        vector<Color> color(n, WHITE);       
        vector<int> cost(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                       std::greater<pair<int, int>>> Q; // Min Heap
        int root = 1;
        cost[root] = 0;
        Q.push({0, root});
        int totalCost = 0;
        while (Q.size()){
            auto p = Q.top(); Q.pop();
            int u = p.second;
            if (color[u] == BLACK) continue;
            
            color[u] = BLACK;
            totalCost += cost[u];
            
            for (auto e: G[u]){
                int v = e.first;
                int weight = e.second;
                if (color[v] == WHITE and weight < cost[v]){
                    cost[v] = weight;
                    Q.push({weight, v});
                } // end-if
            } // end-for
        } // end-while
        return totalCost;        
} // end-kruskals

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res << endl;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
