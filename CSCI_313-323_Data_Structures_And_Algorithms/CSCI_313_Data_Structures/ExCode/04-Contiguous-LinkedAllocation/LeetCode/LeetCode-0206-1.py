# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n) algorithm with O(1) extra space
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None: return head

        p = None
        q = head
        r = head.next

        while q != None:
            q.next = p
            p = q
            q = r
            if r != None: r = r.next
        return p 