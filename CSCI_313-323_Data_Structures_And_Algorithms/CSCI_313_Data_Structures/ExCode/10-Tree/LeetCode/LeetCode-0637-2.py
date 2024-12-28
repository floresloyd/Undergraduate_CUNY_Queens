# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        """
        Do a level-by-level traversal using a queue
        Do not attach "level" to each node in the queue
        But how do we determine the end of a level? The idea is to push
        a NULL pointer to the queue to mark the end of a level
        """
        result = []
        if root == None: return result

        Q = []
        Q.append(root)
        Q.append(None)    # This marks the end of the nodes at this level

        sum = 0   # Sum of the elements at this level
        n = 0     # Number of nodes at this level

        while len(Q) > 0:
            p = Q.pop(0)

            # Have we reached the end of a level?
            if p == None:
                result.append(sum/n)
                sum = n = 0
                if len(Q) > 0: Q.append(None)  # Mark the end of the next level

            else:
                n += 1
                sum += p.val
                if p.left != None: Q.append(p.left)
                if p.right != None: Q.append(p.right)

        return result