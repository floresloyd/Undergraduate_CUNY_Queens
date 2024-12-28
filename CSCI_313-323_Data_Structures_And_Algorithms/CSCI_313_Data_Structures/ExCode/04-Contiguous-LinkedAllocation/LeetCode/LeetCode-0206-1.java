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
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode p = null;
        ListNode q = head;
        ListNode r = head.next;

        while (q != null){
            q.next = p;
            p = q;
            q = r;
            if (r != null) r = r.next;
        } //end-while

        return p;              
    } // end-reverseList
}