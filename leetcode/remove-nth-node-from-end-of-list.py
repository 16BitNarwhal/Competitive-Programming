from typing import Optional

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
  assert (n>0)

  cnt = 0
  cur = head
  while cur != None:
    cnt += 1
    cur = cur.next

  prev = None
  cur = head
  n = cnt - n + 1
  while cur != None:
    n -= 1
    if n == 0:
      if prev == None:
        head = cur.next
      else:
        prev.next = cur.next
      break
    prev = cur
    cur = cur.next
  return head