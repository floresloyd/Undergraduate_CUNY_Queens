///-------------------------------------------------------------------
/**************************************************************
* Pseudocode Template for Divide & Conquer Algorithms
*
* How to solve a problem P recursively:
*
Solve(P) {
    // Base case(s)
    if P is a base case problem
        return the solution immediately

    // Divide P into P1, P2, ..Pn each of smaller scale (n>=2)
    // Solve subproblems recursively
    S1 = Solve(P1);  // Solve P1 recursively to obtain S1
    S2 = Solve(P2);  // Solve P2 recursively to obtain S2
    ...
    Sn = Solve(Pn);  // Solve Pn recursively to obtain Sn

    // Merge the solutions to subproblems
    // to get the solution to the original big problem
    S = Merge(S1, S2, ..., Sn);

    // Return the solution
    return S;
} //end-Solve
*/
#include <iostream>

/**
 * Computes a^n
 */
static double Power(double a, int n) {
    /* Base cases */
    if (n == 0) return 1;
    if (n == 1) return a;

    /* partialResult = a^(n-1) */
    double partialResult = Power(a, n - 1);

    /* Merge */
    return partialResult * a;
} /* end-Power */

int main(){
    double p = Power(3, 4);
    printf("3^4 = %.2lf\n", p);
    printf("--------------------------\n");

    p = Power(2.1, 8);
    printf("2.1^8 = %.2lf\n", p);

    return 0;
} // end-main
