# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if root is None: return result

        Q = []
        Q.append(root)
        
        while len(Q) > 0:
            n = len(Q)  # Number of nodes at this level
            
            # Add a new list to the end of the result
            maxVal = -1<<31
            for i in range(n):
                p = Q.pop(0)
                maxVal = max(maxVal, p.val)
                if p.left is not None: Q.append(p.left)
                if p.right is not None: Q.append(p.right)
            result.append(maxVal)
        return result        