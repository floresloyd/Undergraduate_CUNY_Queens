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

public class FibonacciTest {
    /**
     * Computes nth Fibonacci number
     */
    static int Fibonacci(int n) {
        /* Base cases */
        if (n == 0) return 0;
        if (n == 1) return 1;

        return Fibonacci(n - 1) + Fibonacci(n - 2);
    } /* end-Fibonacci */

    public static void main(String[] args){
        System.out.printf("5th Fibonacci number is: %d\n", Fibonacci(5));
        System.out.printf("9th Fibonacci number is: %d\n", Fibonacci(9));
    } // end-main
} // end-FibonacciTest
