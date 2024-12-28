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

public class SuperDigitTest {
    /**
     * Computes the super-digit of a number
     */
    static int superDigit(int n) {
        /* Base case */
        if (n < 10) return n;

        int digitSum = 0;
        while (n > 0) {
            digitSum += n % 10;
            n = n / 10;
        } //end-while

        return superDigit(digitSum);        
    } /* end-superDigit */

    public static void main(String[] args){
        int sd = superDigit(9875);
        System.out.printf("SuperDigit of 9875 is %d\n", sd);

        sd = superDigit(12478453);
        System.out.printf("SuperDigit of 12478453 is %d\n", sd);     
    } // end-main
} // end-SuperDigitTest
