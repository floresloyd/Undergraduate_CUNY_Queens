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

public class BinarySearchTest {
    /**
     * Searches a key in sorted array A[left..right]
     */
    static int BinarySearch(int nums[], int left, int right, int key) {
        /* Base case 1: Number of elements in the array */
        if (left > right) return -1; /* Unsuccessful search */

        /* Compare the key with the middle element */
        int middle = left + (right - left) / 2;
        if (key == nums[middle]) return middle; /* Success */

        /* Conquer & Merge */
        else if (key < nums[middle])
            return BinarySearch(nums, left, middle - 1, key);
        else
            return BinarySearch(nums, middle + 1, right, key);
    } //end-BinarySearch

    public static void main(String[] args){
        int nums[] = { 1, 4, 5, 6, 10, 12, 13, 17, 25, 30, 32, 33, 50, 54, 55, 58 };
        int lastIndex = nums.length-1;

        System.out.print("nums: [");
        for (var num: nums)
            System.out.printf("%d, ", num);
        System.out.println("\b\b]");        

        int key = 12;
        int index = BinarySearch(nums, 0, lastIndex, key);
        if (index < 0) System.out.printf("Key %d does not exist in the array.\n", key);
        else System.out.printf("The last index of key %d is %d\n", key, index);

        key = 77;
        index = BinarySearch(nums, 0, lastIndex, key);
        if (index < 0) System.out.printf("Key %d does not exist in the array.\n", key);
        else System.out.printf("The last index of key %d is %d\n", key, index);
    } // end-main
} // end-BinarySearchTest