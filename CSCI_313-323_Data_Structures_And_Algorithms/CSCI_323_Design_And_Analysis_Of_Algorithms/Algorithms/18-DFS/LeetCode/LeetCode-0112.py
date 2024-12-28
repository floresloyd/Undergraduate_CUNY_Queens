# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSumAux(self, root, targetSum, pathSum):
        if root is None: return False

        pathSum += root.val

        # Do the check when we are at a leaf node
        if root.left is None and root.right is None:
            return pathSum == targetSum

        if self.pathSumAux(root.left, targetSum, pathSum): return True
        return self.pathSumAux(root.right, targetSum, pathSum)
    
    
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return self.pathSumAux(root, targetSum, 0)
