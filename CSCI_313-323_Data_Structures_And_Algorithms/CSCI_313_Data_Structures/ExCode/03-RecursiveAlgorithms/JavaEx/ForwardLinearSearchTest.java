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

public class ForwardLinearSearchTest {
    /**
     * Recursive forward linear search
     */
    static int ForwardLinearSearch(int nums[], int index, int key) {
        /* Base cases */
        if (index == nums.length) return -1; /* Unsuccessful search */
        if (key == nums[index]) return index;   /* Success */

        /* Divide & Conquer & Merge */
        return ForwardLinearSearch(nums, index + 1, key);
    } //end-ForwardLinearSearch

    public static void main(String[] args){
        int[] nums = { 9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 12, 62, 55 };

        System.out.print("nums: [");
        for (var num: nums)
            System.out.printf("%d, ", num);
        System.out.println("\b\b]");

        int key = 12;
        int index = ForwardLinearSearch(nums, 0, key);        
        if (index < 0) System.out.printf("Key %d does not exist in the array.\n", key);
        else System.out.printf("The first index of key %d is %d\n", key, index);
        System.out.println("--------------------------");

        key = 77;
        index = ForwardLinearSearch(nums, 0, key);
        if (index < 0) System.out.printf("Key %d does not exist in the array.\n", key);
        else System.out.printf("The first index of key %d is %d\n", key, index);
    } // end-main
} // end-ForwardLinearSearchTest
