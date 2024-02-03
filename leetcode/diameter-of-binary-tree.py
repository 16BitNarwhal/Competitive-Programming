# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return root.depth

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        dleft = self.diameterOfBinaryTree(root.left)
        dright = self.diameterOfBinaryTree(root.right)
        root.depth = max(self.depth(root.left), self.depth(root.right)) + 1

        return max(dleft, dright,
           self.depth(root.left) + self.depth(root.right))