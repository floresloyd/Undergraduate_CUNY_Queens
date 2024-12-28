#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

///=========================== FRACTIONAL KNAPSACK ===================
/// O(nlogn) algorithm with O(n) extra space
///
double FractionalKnapsack_Greedy(vector<int> v, vector<int> w, int W) {
    int n = v.size();
    vector<int> I(n);
    for (int i = 0; i < n; i++) I[i] = i;

    std::sort(I.begin(), I.end(),
        [&](int one, int two) {
            double v1 = (double)v[one] / w[one];
            double v2 = (double)v[two] / w[two];
            return v1 > v2;
        });

    double result = 0;
    for (auto index: I) {
        if (W == 0) break;
        int taken = std::min(W, w[index]);
        result += taken * ((double)v[index] / w[index]);
        W -= taken;
    } // end-for

    return result;
} // end-FractionalKnapsack_Greedy

///----------------------------------------
/// Greedy Solution: Does not always give the optimal solution
///
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

    double r = FractionalKnapsack_Greedy(v, w, knapsackCapacity);
    cout << "Fractional Knapsack solution: " << r << endl;

    // Greedy algorithm for Knapsack
    int result = Knapsack_Greedy(v, w, knapsackCapacity);
    printf("Greedy result:     %d\n", result);
} //end-KnapsackTest


int main() {
    KnapsackTest();

	return 0;
} //end-main
