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

public class PowerTest {
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

    public static void main(String[] args){
        double p = Power(3, 4);
        System.out.printf("3^4 = %.2f\n", p);
        System.out.println("--------------------------");

        p = Power(2.1, 8);
        System.out.printf("2.1^8 = %.2f\n", p);
    } // end-main
} // end-PowerTest
