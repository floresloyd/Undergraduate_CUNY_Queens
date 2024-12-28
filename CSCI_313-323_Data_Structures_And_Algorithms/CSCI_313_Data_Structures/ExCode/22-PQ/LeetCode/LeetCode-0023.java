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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        if (lists.length == 1) return lists[0];

        record Pair(int val, int listIndex){};
        PriorityQueue<Pair> Q = 
            new PriorityQueue<>((left, right)->left.val()-right.val());

        // Create the initial PQ
        for (int i=0; i<lists.length; i++){
            if (lists[i] != null)
                Q.offer(new Pair(lists[i].val, i));
        } //end-for

        ListNode head = null, tail = null;

        while (!Q.isEmpty()){
            var index = Q.poll().listIndex();

            if (tail == null){ 
                head = tail = lists[index];
            } else {
                tail.next = lists[index];
                tail = tail.next;
            } // end-else

            lists[index] = lists[index].next;

            if (lists[index] != null)
                Q.offer(new Pair(lists[index].val, index));
        } //end-while

        return head;
    }
}
