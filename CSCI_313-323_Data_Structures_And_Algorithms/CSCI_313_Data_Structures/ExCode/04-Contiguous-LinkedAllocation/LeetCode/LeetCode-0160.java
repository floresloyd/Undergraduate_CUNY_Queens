/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /// O(n+m) algorithm with O(1) extra space
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p = headA;
        ListNode q = headB;

        while (p != q){
            p = p == null? headB: p.next;
            q = q == null? headA: q.next;
        } // end-while

        return p;        
    } // end-getIntersectionNode
}