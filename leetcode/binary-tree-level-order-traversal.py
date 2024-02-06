# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans = []
        q = []
        buffer = [root]
        while len(buffer) > 0:
            q = list(buffer)
            buffer = []
            cur_res = []
            for node in q:
                cur_res.append(node.val)
                if node.left:
                    buffer.append(node.left)
                if node.right:
                    buffer.append(node.right)
            ans.append(cur_res)
        return ans