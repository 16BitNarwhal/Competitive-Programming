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
        
        ld = self.depth(root.left)
        rd = self.depth(root.right)

        if ld==-1 or rd==-1:
            return -1
        
        if abs(ld-rd) > 1:
            return -1
        else:
            return max(ld, rd) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.depth(root) != -1