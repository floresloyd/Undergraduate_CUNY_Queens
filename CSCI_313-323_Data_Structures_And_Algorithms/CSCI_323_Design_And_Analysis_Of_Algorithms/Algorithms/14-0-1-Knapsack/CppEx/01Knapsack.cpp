#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define NO_SOL -1

///=========================== 0-1 KNAPSACK ===================
int Knapsack_Greedy(vector<int> v, vector<int> w, int W) {
    int n = v.size();
    vector<int> I(n);
    for (int i = 0; i < n; i++) I[i] = i;

    std::sort(I.begin(), I.end(),
        [&](int one, int two) {
            double v1 = (double)v[one] / w[one];
            double v2 = (double)v[two] / w[two];
            return v1 > v2;
        });

    // Take the items in the sorted order (if it fits to the knapsack)
    int totalValue = 0;
    for (auto index: I){
        if (W == 0) break;
        if (w[index] <= W) {
            totalValue += v[index];
            W -= w[index];
        } //end-if
    } //end-for

    return totalValue;
} //end-Knapsack_Greedy

///----------------------------------------
/// Brute-force recursive solution
int numRecursiveCalls = 0;

int Knapsack_Recursive(vector<int> v, vector<int> w, int n, int W) {
    if (n <= 0) return 0;
    
    numRecursiveCalls++;

    // Take the last item
    int index = n-1;
    int take_it = 0;
    if (w[index] <= W) {
        take_it = v[index] + Knapsack_Recursive(v, w, n-1, W - w[index]);
    } //end-if

    // Leave the last item
    int leave_it = Knapsack_Recursive(v, w, n-1, W);

    // Return the better solution
    return std::max(take_it, leave_it);
} //end-Knapsack_Recursive

///----------------------------------------
/// TopDown DP Solution for the Knapsack Problem
//
int numRecursiveCallsForKnapsackMemoize = 0;

int Knapsack_Memoize(vector<int> v, vector<int> w, int n, int W, vector<vector<int>> &T) {
    if (n <= 0) return 0;
    if (W <= 0) return 0;
    if (T[n][W] != NO_SOL) return T[n][W];

    numRecursiveCallsForKnapsackMemoize++;

    int index = n-1;
    int take_it = 0;
    if (w[index] <= W) {
        take_it = v[index] + Knapsack_Memoize(v, w, n-1, W - w[index], T);
    }

    int leave_it = Knapsack_Memoize(v, w, n-1, W, T);

    return T[n][W] = std::max(take_it, leave_it);
} //end-Knapsack_Memoize

int Knapsack_TopDownDP(vector<int> v, vector<int> w, int W) {
    int n = v.size();
    vector<vector<int>> T(n + 1, vector<int>(W + 1, NO_SOL));
    return Knapsack_Memoize(v, w, n, W, T);
} //end-Knapsack_TopDownDP

///----------------------------------------
/// Bottom-up DP for the Knapsack Problem
///
int Knapsack_BottomUpDP(vector<int> v, vector<int> w, int W) {
    int n = v.size();
    vector<vector<int>> T(n+1, vector<int>(W+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int index = i-1;
            int take_it = 0;
            if (w[index] <= j) take_it = v[index] + T[i - 1][j - w[index]];

            int leave_it = T[i - 1][j];
            T[i][j] = std::max(take_it, leave_it);
        } //end-for
    } //end-for

    return T[n][W];
} //end-Knapsack_BottomUpDP

///----------------------------------------
/// Bottom-up DP for the Knapsack Problem
/// Also computes the items taken to form the solution
///
int Knapsack_BottomUpDP2(vector<int> v, vector<int> w, int W, vector<int> &items) {
    int n = v.size();
    vector<vector<int>> T(n+1, vector<int>(W+1, 0));
    vector<vector<bool>> take(n+1, vector<bool>(W+1, false));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int index = i-1;
            int take_it = 0;
            if (w[index] <= j) take_it = v[index] + T[i - 1][j - w[index]];

            int leave_it = T[i - 1][j];

            T[i][j] = std::max(take_it, leave_it);
            if (take_it > leave_it) take[i][j] = true;  // Mark the item as taken
        } //end-for
    } //end-for

    // Compute the items taken to form the solution
    for (int i=n, j=W; i>0 && j>0; i--){
        if (take[i][j]){
            items.push_back(i-1);
            j -= w[i-1];
        } // end-if
    } // end-for
    std::reverse(items.begin(), items.end());

    return T[n][W];
} //end-Knapsack_BottomUpDP2

///----------------------------------------
/// Bottom-up DP for the Knapsack Problem
/// that requires only O(W) space to store the results
///
int Knapsack_BottomUpDP3(vector<int> v, vector<int> w, int W) {
    int n = v.size();
    vector<int> T(W+1, 0);

    for (int i = 1; i <= n; i++) {
        int index = i-1;
        // Process the row in the backwards direction
        for (int j=W; j>=w[index]; j--){
            int take_it = v[index] + T[j - w[index]];
            int leave_it = T[j];
            T[j] = std::max(take_it, leave_it);
        } // end-for
    } //end-for

    return T[W];
} //end-Knapsack_BottomUpDP3

///-------------------------------------------
/// Test for Knapsack
///
void KnapsackTest() {
#if 1
    vector<int> v = { 30, 20, 100, 90, 160 };
    vector<int> w = { 5, 10, 20, 30, 40 };
    int knapsackCapacity = 60;

#else
    vector<int> v = { 30, 20, 100, 90, 160, 30, 60, 100, 20, 10 };
    vector<int> w = { 5, 10, 20, 30, 40, 20, 30, 10, 40, 5, 2 };
    int knapsackCapacity = 100;
#endif
    // Greedy algorithm for Knapsack
    int result = Knapsack_Greedy(v, w, knapsackCapacity);
    printf("Greedy result:     %d\n", result);

    // Recursive version
    result = Knapsack_Recursive(v, w, v.size(), knapsackCapacity);
    printf("[Recursive] Result:  %d. Times called: %d\n", 
        result, numRecursiveCalls);

    // Top-Down DP Solution
    result = Knapsack_TopDownDP(v, w, knapsackCapacity);
    printf("[Memoized DP] Result:  %d. Times called: %d\n", 
        result, numRecursiveCallsForKnapsackMemoize);

    // Bottom up DP version
    result = Knapsack_BottomUpDP(v, w, knapsackCapacity);
    printf("[BottomUp DP] Result: %d\n", result);

    // Bottom up DP version2 that computes the items taken
    vector<int> items;
    result = Knapsack_BottomUpDP2(v, w, knapsackCapacity, items);
    printf("[BottomUp DP2] Result: %d\n", result);
    printf("Items taken to form the solution: {");
    for (auto item: items) printf("%d, ", item);
    printf("\b\b}\n");

    // Bottom up DP version2
    result = Knapsack_BottomUpDP3(v, w, knapsackCapacity);
    printf("[BottomUp DP3] Result: %d\n", result);
} //end-KnapsackTest

int main() {
    KnapsackTest();

	return 0;
} //end-main
