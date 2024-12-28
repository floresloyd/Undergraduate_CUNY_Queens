/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    /// O(n) algorithm with O(1) extra space
    /// Change your point of view :-)
    /// Imagine the problem as moving the nodes from the given
    /// list to a new list, where we always add the node to head
    /// of the new list.
    public ListNode reverseList(ListNode head) {
        ListNode newHead = null;
        while (head != null){
            ListNode curr = head;
            head = head.next;

            curr.next = newHead;
            newHead = curr;
        } // end-while

        return newHead;              
    } // end-reverseList
}