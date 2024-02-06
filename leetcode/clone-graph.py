"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        copies = dict() # val : node
        q = [node]
        while len(q) > 0:
            u = q[0]
            q.pop(0)
            if u.val in copies:
                continue
            clone = Node(u.val)
            copies[u.val] = clone
            for v in u.neighbors:
                q.append(v)
        vis = dict() # val : bool
        q = [node]
        while len(q) > 0:
            u = q[0]
            q.pop(0)
            if u.val in vis:
                continue
            vis[u.val] = True
            for v in u.neighbors:
                copies[u.val].neighbors.append(copies[v.val])
                q.append(v)
                
        return copies[node.val]