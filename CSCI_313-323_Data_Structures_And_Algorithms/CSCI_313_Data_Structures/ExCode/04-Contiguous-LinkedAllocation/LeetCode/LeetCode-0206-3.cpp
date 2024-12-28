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
    /// Change your point of view :-)
    /// Imagine the problem as moving the nodes from the given
    /// list to a new list, where we always add the node to head
    /// of the new list.
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head != NULL){
            ListNode *curr = head;
            head = head->next;

            curr->next = newHead;
            newHead = curr;
        } // end-while

        return newHead;
    } // end-reverseList
};