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
 * Recursive backward linear search
 */
int BackwardLinearSearch(int nums[], int index, int key) {
    /* Base case */
    if (index < 0) return -1; /* Unsuccessful search */

    // Compare "key" with the last element
    if (key == nums[index]) return index;   /* Success */

    /* Divide & Conquer & Merge */
    return BackwardLinearSearch(nums, index-1, key);
} //end-BackwardLinearSearch

int main(){
    int nums[] = { 9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 12, 62, 55 };
    int lastIndex = sizeof(nums)/sizeof(int)-1;

    printf("nums: [");
    for (auto num: nums)
        printf("%d, ", num);
    printf("\b\b]\n");

    int key = 12;
    int index = BackwardLinearSearch(nums, lastIndex, key);        
    if (index < 0) printf("Key %d does not exist in the array.\n", key);
    else printf("The first index of key %d is %d\n", key, index);
    printf("--------------------------\n");

    key = 77;
    index = BackwardLinearSearch(nums, lastIndex, key);
    if (index < 0) printf("Key %d does not exist in the array.\n", key);
    else printf("The first index of key %d is %d\n", key, index);

    return 0;
} // end-main
