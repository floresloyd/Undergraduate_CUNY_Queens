class Solution {
public:
    // O(n+m) algorithm with O(1) extra space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;  
        int j = n-1;
        int k = m+n-1;
        while (i>=0 and j>=0){
            if (nums2[j] >= nums1[i])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        } // end-while

        while (j>=0)
            nums1[k--] = nums2[j--];           
    } // end-merge
};