class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
  def deleteNode(self, node):
    node.next.val, node.val = node.val, node.next.val
    
    if node.next.next == None:
      node.next = None
      return

    self.deleteNode(node.next)