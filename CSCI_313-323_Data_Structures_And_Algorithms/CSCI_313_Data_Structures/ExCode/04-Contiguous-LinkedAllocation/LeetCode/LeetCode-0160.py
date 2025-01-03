# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # O(n+m) algorithm with O(1) extra space
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        p = headA
        q = headB

        while p != q:
            p = headB if p == None else p.next
            q = headA if q == None else q.next
        return p 