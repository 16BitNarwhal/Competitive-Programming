# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# works for any binary tree!

class Solution:
    def find(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> tuple[Optional['TreeNode'], bool, bool]:
        if root == None:
            return (None, False, False)

        left = self.find(root.left, p, q)
        right = self.find(root.right, p, q)
        if left[0]:
            return (left[0], True, True)
        if right[0]:
            return (right[0], True, True)
            
        found_p = (root==p) or left[1] or right[1]
        found_q = (root==q) or left[2] or right[2]

        return (root if found_p and found_q else None, found_p, found_q)

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.find(root, p, q)[0]