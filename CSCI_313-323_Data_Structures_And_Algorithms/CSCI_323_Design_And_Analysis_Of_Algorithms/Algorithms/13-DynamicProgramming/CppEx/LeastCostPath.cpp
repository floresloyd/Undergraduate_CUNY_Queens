#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NO_SOL -1   // The problem is NOT solved yet

///-----------------------------------------------------------
/// The recursive (backtracking) algorithm for the lowest cost problem
///
int numRecursiveCalls = 0;

int LeastCostPath_Recursive(vector<vector<int>>& grid, int i, int j) {
	int N = grid.size();
	if (i >= N || j >= N) return INT_MAX;
	if (i == N - 1 && j == N - 1) return 0; // Reached the goal state
	numRecursiveCalls++;

	// Compute the cost of the path that goes through the down slot
	int downCost = LeastCostPath_Recursive(grid, i + 1, j);

	// Compute the cost of the path that goes through the right slow
	int rightCost = LeastCostPath_Recursive(grid, i, j + 1);

	// Min cost
	int minCost = std::min(downCost, rightCost);

	return grid[i][j] + minCost;
} // LeastCostPath_Recursive

///-----------------------------------------------------------
/// Top-down DP solution
///
int numRecursiveCallsForLeastCostMemoize = 0;

int LeastCostPath_Memoize(vector<vector<int>>& grid, int i, int j, 
						  vector<vector<int>> &T) {

	int N = grid.size();
	if (i >= N || j >= N) return INT_MAX;
	if (T[i][j] != NO_SOL) return T[i][j];

	numRecursiveCallsForLeastCostMemoize++;

	// Compute the cost of the path that goes through the down cell
	int downCost = LeastCostPath_Memoize(grid, i + 1, j, T);

	// Compute the cost of the path that goes through the right cell
	int rightCost = LeastCostPath_Memoize(grid, i, j + 1, T);

	// Min cost
	int minCost = std::min(downCost, rightCost);

	return T[i][j] = grid[i][j] + minCost;
} // LeastCostPath_Memoize

int LeastCostPath_TopDownDP(vector<vector<int>>& grid) {
	int N = grid.size();
	vector<vector<int>> T(N, vector<int>(N, NO_SOL));  // Solution table	
	T[N-1][N-1] = 0;   // Solution for the destination cell

    return LeastCostPath_Memoize(grid, 0, 0, T);
} //end-LeastCostPath_TopDownDP

///----------------------------------------------------------------
/// Bottom Up DP solution: We start from T[N-1][N-1] and work backwards
///
int LeastCostPath_BottomUpDP(vector<vector<int>>& grid){
	int N = grid.size();
	vector<vector<int>> T(N, vector<int>(N, 0));

	// Process the last row
	for (int c=N-2; c>=0; c--) T[N-1][c] = grid[N-1][c] + T[N-1][c+1];

	// Process the last column
	for (int r=N-2; r>=0; r--) T[r][N-1] = grid[r][N-1] + T[r+1][N-1];

	// Process the rest of the cells
	for (int r=N-2; r>=0; r--){
		for (int c=N-2; c>=0; c--){
			T[r][c] = grid[r][c] + std::min(T[r+1][c], T[r][c+1]);		
		} // end-for
	} // end-for

    return T[0][0];
} //end-LeastCostPath_BottomUpDP

///----------------------------------------------------------
/// Also computes the cells on the shortest path
///
enum DIR {DOWN, RIGHT};
struct Cell { int i, j; Cell(int i, int j): i(i), j(j) {} };

int LeastCostPath_BottomUpDP2(vector<vector<int>>& grid, vector<Cell>& path){
	int N = grid.size();
	vector<vector<int>> T(N, vector<int>(N, 0));
	vector<vector<DIR>> dir(N, vector<DIR>(N));

	// Process the last row
	for (int c=N-2; c>=0; c--){
		T[N-1][c] = grid[N-1][c] + T[N-1][c+1];
		dir[N-1][c] = RIGHT;
	} // end-for

	// Process the last column
	for (int r=N-2; r>=0; r--){
		T[r][N-1] = grid[r][N-1] + T[r+1][N-1];
		dir[r][N-1] = DOWN;
	} // end-for

	// Process the rest of the cells
	for (int r=N-2; r>=0; r--){
		for (int c=N-2; c>=0; c--){
			if (T[r+1][c] < T[r][c+1]){
				T[r][c] = grid[r][c] + T[r+1][c];		
				dir[r][c] = DOWN;
			} else {
				T[r][c] = grid[r][c] + T[r][c+1];		
				dir[r][c] = RIGHT;
			} // end-else
		} // end-for
	} // end-for

	// Compute the cells on the path from (0, 0)->(N-1, N-1)
	int i = 0;
	int j = 0;
	while (!(i == N - 1 && j == N - 1)) {
		path.push_back(Cell(i, j));

		if (dir[i][j] == DOWN) i++;
		else                    j++;
	} //end-while

	// Push (N-1, N-1)
	path.push_back(Cell(N-1, N-1));

    return T[0][0];
} //end-LeastCostPath_BottomUpDP2

///-----------------------------------------------------------
/// Testcode for Minimum Cost Path
///
void LeastCostPathTest() {
#if 1
	vector<vector<int>> grid = { {0, 1, 5}, 
		                         {2, 4, 2}, 
		                         {1, 3, 0} };
#else
	vector<vector<int>> grid = { {0, 3, 1, 2, 3}, 
		                         {2, 3, 1, 9, 4}, 
							     {2, 4, 1, 2, 3},
							     {1, 2, 3, 4, 2},
							     {5, 4, 5, 2, 0} };
#endif

	int cost = LeastCostPath_Recursive(grid, 0, 0);
	printf("[Recursive] Cost: %d. Times called: %d\n", cost, numRecursiveCalls);

	cost = LeastCostPath_TopDownDP(grid);
	printf("[Memoized DP] Cost: %d. Times called: %d\n", cost, numRecursiveCallsForLeastCostMemoize);

	cost = LeastCostPath_BottomUpDP(grid);
	printf("[BottomUp DP] Cost: %d\n", cost);

	vector<Cell> path;
	cost = LeastCostPath_BottomUpDP2(grid, path);
	printf("[BottomUp DP2] Cost: %d\n", cost);	
	printf("Here are the cells on the least cost path:\n");
	for (auto cell: path) {
		printf("[%d, %d]->", cell.i, cell.j);
	} // end-for
	printf("\b\b  \n");
	printf("-------------------------------------------------------\n");
} //end-LeastCostPathTest

int main() {
	LeastCostPathTest();

	return 0;
} //end-main




