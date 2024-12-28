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
    // O(n) algorithm with O(1) extra space
    ListNode* reverseList(ListNode* head) {
          if (head == NULL || head->next == NULL) return head;

        ListNode *p = NULL;
        ListNode *q = head;
        ListNode *r = head->next;

        while (q != NULL){
            q->next = p;
            p = q;
            q = r;
            if (r != NULL) r = r->next;
        } //end-while

        return p;      
    } // end-reverseList
};