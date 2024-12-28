# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if root is None: return result

        Q = []
        Q.append(root)
        
        while len(Q) > 0:
            n = len(Q)  # Number of nodes at this level
            
            # Add a new list to the end of the result
            result.append([])
            index = len(result)-1

            for i in range(n):
                p = Q.pop(0)
                result[index].append(p.val)
                if p.left is not None: Q.append(p.left)
                if p.right is not None: Q.append(p.right)
        return result