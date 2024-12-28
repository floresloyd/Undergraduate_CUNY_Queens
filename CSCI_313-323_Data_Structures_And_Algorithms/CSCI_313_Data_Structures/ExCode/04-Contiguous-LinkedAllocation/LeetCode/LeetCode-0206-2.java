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
    /// Avoids the if (r != null) check inside the while loop
    public ListNode reverseList(ListNode head) {
        ListNode p = null;
        ListNode q = head;
        ListNode r = head;

        while (q != null){
            r = r.next;
            q.next = p;
            p = q;
            q = r;
        } //end-while

        return p;              
    } // end-reverseList
}