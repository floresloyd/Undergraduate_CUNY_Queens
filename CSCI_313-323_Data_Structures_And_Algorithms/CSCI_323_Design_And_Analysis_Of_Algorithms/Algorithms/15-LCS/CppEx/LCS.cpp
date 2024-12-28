#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NO_SOL -1

/// Returns the length of the longest common subsequence 
/// of two strings X & Y. Using recursive algorithm.
///
int numRecursiveCalls = 0;

int LCS_Recursive(string &X, int m, string &Y, int n){
    // Base cases: If any of the strings is empty, the LCS is empty
    if (m == 0 || n == 0) return 0;   

    numRecursiveCalls++;

    // If the last chars equal then
    if (X[m-1] == Y[n-1]) {
        return 1 + LCS_Recursive(X, m - 1, Y, n - 1);
    }
    else {
        int length1 = LCS_Recursive(X, m - 1, Y, n);
        int length2 = LCS_Recursive(X, m, Y, n - 1);

        return std::max(length1, length2);
    } //end-else
} //end-LCS_Recursive

///--------------------------------------------
/// Returns the length of the longest common subsequence 
/// of two strings X & Y. Using Memoized DP.
///
int numRecursiveCallsForLCSMemoize = 0;

int LCS_Memoize(string &X, int m, string &Y, int n, vector<vector<int>> &T) {
    if (m == 0) return 0;
    if (n == 0) return 0;
    if (T[m][n] != NO_SOL) return T[m][n];

    numRecursiveCallsForLCSMemoize++;

    // If the last chars equal then
    if (X[m-1] == Y[n-1]){
        LCS_Memoize(X, m - 1, Y, n - 1, T);
        T[m][n] = 1 + T[m - 1][n - 1];

    } else {
        LCS_Memoize(X, m - 1, Y, n, T);
        LCS_Memoize(X, m, Y, n - 1, T);

        int length1 = T[m - 1][n];
        int length2 = T[m][n - 1];

        T[m][n] = std::max(length1, length2);
    } //end-else

    return T[m][n];
} //end-LCS_Memoize

int LCS_TopDownDP(string& X, string& Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> T(m + 1, vector<int>(n + 1, NO_SOL));
    return LCS_Memoize(X, m, Y, n, T);
} //end-LCS_TopDownDP

///--------------------------------------------
/// Returns the length of the longest common subsequence 
/// of two strings X & Y. Using BottomUp DP.
///
int LCS_BottomUpDP(string &X, string &Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> T(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) T[i][j] = 1 + T[i - 1][j - 1];
            else {
                int length1 = T[i - 1][j];
                int length2 = T[i][j - 1];

                T[i][j] = std::max(length1, length2);
            } //end-else
        } //end-for
    } //end-for

    return T[m][n];
} //end-LCS_BottomUpDP

///--------------------------------------------
/// Returns both the length of the LCS and the actual LCS sequence
///
enum DIR {LEFT=1, UP=2, CROSS=3};

void GetLCSSequence(string &X, string &lcs, int m, int n, 
                    vector<vector<DIR>> &dirTable) {
    if (m == 0 || n == 0) return;

    if (dirTable[m][n] == LEFT) 
        GetLCSSequence(X, lcs, m, n - 1, dirTable);
    else if (dirTable[m][n] == UP)
        GetLCSSequence(X, lcs, m - 1, n, dirTable);
    else { // CROSS
        GetLCSSequence(X, lcs, m - 1, n - 1, dirTable);
        lcs.push_back(X[m-1]);
    } //end-else
} //end-GetLCSSequence

int LCS_BottomUpDP2(string& X, string& Y, string &lcs) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> T(m + 1, vector<int>(n + 1, 0));
    vector<vector<DIR>> dirTable(m + 1, vector<DIR>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                T[i][j] = 1 + T[i - 1][j - 1];
                dirTable[i][j] = CROSS;      // Go to (i-1, j-1)

            } else {
                int length1 = T[i - 1][j];
                int length2 = T[i][j - 1];

                if (length1 > length2) {
                    T[i][j] = length1;
                    dirTable[i][j] = UP;     // Go to (i-1, j)

                } else {
                    T[i][j] = length2;
                    dirTable[i][j] = LEFT;   // Go to (i, j-1)
                } // end-else
            } //end-else
        } //end-for
    } //end-for

    // Construct the actual LCS sequence using the dirTable
    GetLCSSequence(X, lcs, m, n, dirTable);

    return T[m][n];
} //end-LCS_BottomUpDP2

///---------------------------------------------
/// Test for LCS functions
///
void LCSTest(){
    string X = "ABRACADABRA";    // length = 11 chars
    string Y = "YABBADABBADOO";  // length = 13 chars

    int lcsLength;

    lcsLength = LCS_Recursive(X, X.length(), Y, Y.length());
    printf("[Recursive] LCS: %d chars. Times called: %d\n", lcsLength, numRecursiveCalls);

    lcsLength = LCS_TopDownDP(X, Y);
    printf("[Memoized DP] LCS: %d chars. Times called: %d\n", lcsLength, numRecursiveCallsForLCSMemoize);

    lcsLength = LCS_BottomUpDP(X, Y);
    printf("[BottomUp DP] LCS: %d chars.\n", lcsLength);

    string lcsSeq;
    lcsLength = LCS_BottomUpDP2(X, Y, lcsSeq);
    printf("[BottomUp DP2] LCS: %d chars. Seq: <%s>\n", lcsLength, lcsSeq.c_str());
} //end-LCSTest

int main() {
    LCSTest();

	return 0;
} //end-main

