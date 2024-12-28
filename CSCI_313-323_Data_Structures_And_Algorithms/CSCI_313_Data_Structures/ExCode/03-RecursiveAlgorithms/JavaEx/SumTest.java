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

public class SumTest {
    /**
     * Computes 1+2+3+...+n
     */
    static int Sum(int n) {
        /* Base case */
        if (n == 1) return 1;

        /* Divide and conquer */
        int partialSum = Sum(n - 1);

        /* Merge */
        return partialSum + n;
    } /* end-Sum */

    public static void main(String[] args){
        int x = Sum(4);
        System.out.printf("1+2+3+4 = %d\n", x);
        System.out.println("--------------------------");

        x = Sum(7);
        System.out.printf("1+2+3+4+5+6+7 = %d\n", x);
    } // end-main
} // end-SumTest
