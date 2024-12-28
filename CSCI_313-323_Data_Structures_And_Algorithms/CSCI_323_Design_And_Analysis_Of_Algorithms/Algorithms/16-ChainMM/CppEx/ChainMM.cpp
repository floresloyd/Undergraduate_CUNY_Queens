#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define NO_SOL -1

///--------------------------------------------
/// Computes the optimum cost of multiplying a chain of "N" matrices (Ai..Aj)
/// whose dimensions are given in P[0]..P[N]. That is, the dimension of
/// matrix1 is P[0]xP[1], the dimension of matrix2 is P[1]xP[2], etc.
/// i = The number of the first matrix, e.g., 1
/// j = The number of the last matrix, e.g., 4
///
int numRecursiveCalls = 0;

int ChainMM_Recursive(vector<int> &P, int i, int j){
    if (i == j) return 0;
    numRecursiveCalls++;

    int minCost = INT_MAX;
    for (int k=i; k <= j-1; k++){
        int cost1 = ChainMM_Recursive(P, i, k);
        int cost2 = ChainMM_Recursive(P, k+1, j);
        int totalCost = cost1 + cost2 + P[i-1]*P[k]*P[j];

        minCost = std::min(minCost, totalCost);
    } //end-for

    return minCost;
} //end-ChainMM_Recursive

///--------------------------------------------
/// Computes the optimum cost of multiplying a chain of "N" matrices
/// whose dimensions are given in P[0]..P[N]. That is, the dimension of
/// matrix1 is P[0]xP[1], the dimension of matrix2 is P[1]xP[2], etc.
///
int numRecursiveCallsForChainMMMemoize = 0;

int ChainMM_Memoize(vector<int> &P, int i, int j, vector<vector<int>> &T){
    if (i == j) return 0;
    if (T[i][j] != NO_SOL) return T[i][j];

    numRecursiveCallsForChainMMMemoize++;

    int minCost = INT_MAX;
    for (int k=i; k <= j-1; k++){
        int cost1 = ChainMM_Memoize(P, i, k, T);
        int cost2 = ChainMM_Memoize(P, k+1, j, T);
        int totalCost = cost1 + cost2 + P[i-1]*P[k]*P[j];

        minCost = std::min(minCost, totalCost);
    } //end-for    

    return T[i][j] = minCost;
} //end-ChainMM_Memoize

int ChainMM_TopDownDP(vector<int> &P){
    int n = P.size()-1; // # of matrices
    vector<vector<int>> T(n+1, vector<int>(n+1, NO_SOL));
    return ChainMM_Memoize(P, 1, n, T);
} // end-ChainMM_TopDownDP

///--------------------------------------------
/// Computes the optimum cost of multiplying a chain of "N" matrices
/// whose dimensions are given in P[0]..P[N]. That is, the dimension of
/// matrix1 is P[0]xP[1], the dimension of matrix2 is P[1]xP[2], etc.
///
int ChainMM_BottomUpDP(vector<int> &P){
    int n = P.size()-1; // # of matrices
    vector<vector<int>> T(n+1, vector<int>(n+1, 0));

    for (int len=2; len <= n; len++){             // len: length of sub matrices
        for (int i = 1; i <= n-len+1; i++){
            int j = i + len - 1;
            T[i][j] = INT_MAX;

            for (int k = i; k <= j-1; k++){     // Check all possible splits
              int cost = T[i][k] + T[k+1][j] + P[i-1]*P[k]*P[j];
              T[i][j] = std::min(T[i][j], cost);
            } //end-for
        } //end-for
    } //end-for

    return T[1][n];
} //end-ChainMM_BottomUpDP

///--------------------------------------------
/// Computes the optimum cost of multiplying a chain of "N" matrices
/// whose dimensions are given in P[0]..P[N]. That is, the dimension of
/// matrix1 is P[0]xP[1], the dimension of matrix2 is P[1]xP[2], etc.
///
void MultOrder(int i, int j, vector<vector<int>> &s, string &result){
    if (i == j){
        result.append("A" + std::to_string(i));
    } else {
        result.append("(");
        MultOrder(i, s[i][j], s, result);
        MultOrder(s[i][j]+1, j, s, result);
        result.append(")");
    } // end-else
} // end-MultOrder

int ChainMM_BottomUpDP2(vector<int> &P, string &multOrder){
    int n = P.size()-1; // # of matrices
    vector<vector<int>> T(n+1, vector<int>(n+1, 0));
    vector<vector<int>> s(n+1, vector<int>(n+1, 0));

    for (int len=2; len <= n; len++){             // len: length of sub matrices
        for (int i = 1; i <= n-len+1; i++){
            int j = i + len - 1;
            T[i][j] = INT_MAX;

            for (int k = i; k <= j-1; k++){     // Check all possible splits
                int cost = T[i][k] + T[k+1][j] + P[i-1]*P[k]*P[j];
                if (cost < T[i][j]){
                    T[i][j] = cost;
                    s[i][j] = k;
                } // end-if
            } //end-for
        } //end-for
    } //end-for

    MultOrder(1, n, s, multOrder);

    return T[1][n];
} //end-ChainMM_BottomUpDP2

///----------------------------------------------
/// Main function
///
int main(int argc, char* argv[]){
    vector<int> P = {5, 4, 6, 2, 7};
//    vector<int> P = {5, 4, 6, 2, 7, 11, 3, 18};
//    vector<int> P = {5, 4, 6, 2, 7, 11, 3, 18, 2, 9, 20, 44, 23, 12, 8};
    int n = P.size()-1; // # of matrices
    int cost;

    cost = ChainMM_Recursive(P, 1, n);
    printf("[Recursive] ChainMM: %d multiplications. Times called: %d\n", cost, numRecursiveCalls);

    cost = ChainMM_TopDownDP(P);
    printf("[Memoized DP] ChainMM: %d multiplications. Times called: %d\n", cost, numRecursiveCallsForChainMMMemoize);

    cost = ChainMM_BottomUpDP(P);
    printf("[BottomUp DP] ChainMM: %d multiplications.\n", cost);

    string multOrder;
    cost = ChainMM_BottomUpDP2(P, multOrder);
    printf("[BottomUp DP2] ChainMM: %d multiplications.\n", cost);
    printf("MultOrder: %s\n", multOrder.c_str());

    return 0;
}

