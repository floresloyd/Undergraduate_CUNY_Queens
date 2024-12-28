# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePathsAux(self, root, path, paths):
        if root == None: return

        # Push this node to the path
        path.append(root.val)
        
        # Have we reached a leaf node? Then this is the end of a path
        if root.left == None and root.right == None:
            s = "->".join([str(x) for x in path])
            paths.append(s)
            path.pop()
            return

        self.binaryTreePathsAux(root.left, path, paths)  # Traverse the LST
        self.binaryTreePathsAux(root.right, path, paths) # Traverse the RST

        # Pop this node back from the path when we are going back up the tree
        path.pop()    
    
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        path = []
        paths = []

        self.binaryTreePathsAux(root, path, paths)

        return paths
        