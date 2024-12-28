class Solution {
public:
    /// O(klogn) algorithm with O(1) extra space
    /// Here, we use "piles" directly as the heap space
    int minStoneSum(vector<int>& piles, int k) {
        // Turn piles into a max-heap
        std::make_heap(piles.begin(), piles.end());
        
        while (k-->0){
            // Move the largest element to the end
            pop_heap(piles.begin(), piles.end());
            
            // Update the largest element
            piles.back() = piles.back() - piles.back()/2;
            
            // Push the new value up the heap to restore the heap property
            push_heap(piles.begin(), piles.end());
        } // end-while
        
        return std::accumulate(piles.begin(), piles.end(), 0);
    } // end-minStoneSum
};