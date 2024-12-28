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
        We will push the tree nodes into a queue by attaching a "level" value to
        each node. Thus, when we get the node from the queue, we know at which level
        this node resides.
        """
        result = []
        if root == None: return result

        # <node, level>
        Q = []
        currentLevel = 0
        Q.append([root, currentLevel])

        sum = 0   # Sum of the elements at this level
        n = 0     # number of nodes at this level

        while len(Q) > 0:
            p, level = Q.pop(0)

            # Did we go to the next level?
            if level > currentLevel:
                result.append(sum/n)
                sum = n = 0
                currentLevel = level

            n += 1
            sum += p.val

            if p.left != None: Q.append([p.left, level+1])
            if p.right != None: Q.append([p.right, level+1])

        # Push the average for the last level
        if n > 0: result.append(sum/n)
            
        return result
        