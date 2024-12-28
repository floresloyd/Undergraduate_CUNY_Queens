#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

///=================== LEAST COST PATH =====================
/// The greedy algorithm for the least cost problem
/// Assume that M is a NxN matrix
///
int GreedyLeastCostPath(vector<vector<int>>& M) {
	int N = M.size();
	int i = 0; 
	int j = 0;
	int cost = 0;
	
	int numIterations = 0;
	while (!(i == N-1 && j == N-1)) {
		numIterations++;

		int down = INT_MAX;
		if (i + 1 <= N - 1)	down = M[i + 1][j];

		int right = INT_MAX;
		if (j + 1 <= N - 1)	right = M[i][j+1];

		if (down <= right) {
			cost += down;
			i++;

		} else {
			cost += right;
			j++;
		} //end-else
	} //end-while

	printf("Greedy algorithm iterated %d times\n", numIterations);

	return cost;
} //end-GreedyLeastCostPath

///-----------------------------------------------------------
/// The recursive (backtracking) algorithm for the least cost problem
///
int numTimesCalled = 0;
int RecursiveLeastCostPathAux(vector<vector<int>>& M, int i, int j) {
	int N = M.size();
	if (i >= N or j >= N) return INT_MAX;

	numTimesCalled++;
	if (i == N - 1 && j == N - 1) return 0; // Reached the goal state

	// Compute the cost of the path that goes through the down slot
	int downCost = RecursiveLeastCostPathAux(M, i + 1, j);

	// Compute the cost of the path that goes through the right slow
	int rightCost = RecursiveLeastCostPathAux(M, i, j+1);

	// Min cost
	int minCost = std::min(downCost, rightCost);

	return M[i][j] + minCost;
} // RecursiveLeastCostPathAux

int RecursiveLeastCostPath(vector<vector<int>>& M) {
	int cost = RecursiveLeastCostPathAux(M, 0, 0);
	printf("RecursiveLeastCostPathAux called %d times\n", numTimesCalled);
	return cost;
} //end-RecursiveLeastCostPath

///-----------------------------------------------------------
/// Testcode for Least Cost Path
///
void LeastCostPathTest() {
	vector<vector<int>> M = { {0, 1, 5}, {2, 4, 2}, {1, 3, 0} };

	int cost = GreedyLeastCostPath(M);
	printf("The least cost path by the Greedy algorithm is: %d\n", cost);
	printf("---------------------------------------------------\n");

	cost = RecursiveLeastCostPath(M);
	printf("The least cost path by the Recursive algorithm is: %d\n", cost);
} //end-LeastCostPathTest

int main() {
	LeastCostPathTest();
	
	return 0;
} // end-main
