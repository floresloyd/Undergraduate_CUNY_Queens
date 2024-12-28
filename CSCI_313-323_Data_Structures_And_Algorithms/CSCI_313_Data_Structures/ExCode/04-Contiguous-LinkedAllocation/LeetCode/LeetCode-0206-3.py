# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n) algorithm with O(1) extra space
    # Change your point of view :-)
    # Imagine the problem as moving the nodes from the given
    # list to a new list, where we always add the node to head
    # of the new list.
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        newHead = None
        while head != None:
            curr = head
            head = head.next

            curr.next = newHead
            newHead = curr
        return newHead             
              
