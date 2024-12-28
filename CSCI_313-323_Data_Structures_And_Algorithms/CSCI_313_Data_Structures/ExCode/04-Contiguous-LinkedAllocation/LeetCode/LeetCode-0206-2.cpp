/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    /// Avoids the if (r != NULL) check inside the while loop
    ///
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL;
        ListNode *q = head;
        ListNode *r = head;

        while (q != NULL){
            r = r->next;
            q->next = p;
            p = q;
            q = r;
        } //end-while

        return p;
    } // end-reverseList
};