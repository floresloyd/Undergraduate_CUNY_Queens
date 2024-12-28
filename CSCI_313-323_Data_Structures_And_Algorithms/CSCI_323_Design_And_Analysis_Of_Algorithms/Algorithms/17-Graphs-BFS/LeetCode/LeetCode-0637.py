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
        Consider the state of the Q at the end of an iteration
        Assume we just finished processing a level
        What is the current content of the Q? All nodes at the next level
        So, we will simply have a for loop to process the nodes at the next level!
        """ 
        result = []
        if root == None: return result

        Q = []
        Q.append(root)
        
        while len(Q) > 0:
            n = len(Q)     # Number of nodes at this level
            sum = 0        # Sum of the node values at this level
            
            for i in range(n):
                p = Q.pop(0)
                sum += p.val
                if p.left != None: Q.append(p.left)
                if p.right != None: Q.append(p.right)

            result.append(sum/n)
        return result