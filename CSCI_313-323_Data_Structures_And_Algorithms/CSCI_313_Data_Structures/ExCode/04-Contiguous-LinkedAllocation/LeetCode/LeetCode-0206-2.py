# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n) algorithm with O(1) extra space
    # Avoids the if (r != None) check inside the while loop
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p = None
        q = head
        r = head

        while q != None:
            r = r.next
            q.next = p
            p = q
            q = r
        return p              
