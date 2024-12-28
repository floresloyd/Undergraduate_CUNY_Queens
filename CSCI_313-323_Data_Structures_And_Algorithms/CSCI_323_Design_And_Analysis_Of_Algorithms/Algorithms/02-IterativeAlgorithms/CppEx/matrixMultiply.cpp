#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

/// --------------------------------------------------
/// O(N^3) algorithm for matrix multiplication
///
void MatrixMultiply(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    for (uint32_t i = 0; i < C.size(); i++) {
        for (uint32_t j = 0; j < C[i].size(); j++) {
            C[i][j] = 0;
            for (uint32_t k = 0; k < A[i].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            } //end-for
        } // end-for
    } // end-for
} //end-MatrixMultiply

int main() {
    vector<vector<int>> A = { {5, 1, 2}, {1, 2, 4}, {6, 2, 7} };
    vector<vector<int>> B = { {1, 2, 2}, {3, 1, 3}, {2, 1, 4} };
    vector<vector<int>> C(3, vector<int>(3));

    MatrixMultiply(A, B, C);
    for (uint32_t i = 0; i < C.size(); i++) {
        for (uint32_t j = 0; j < C[i].size(); j++) {
            printf("%2d, ", C[i][j]);
        } //end-for
        printf("\b\b \n");
    } //end-for

	return 0;
} // end-main

