from collections import Counter

class Node:
  def __init__(self, data: int):
    self.data = data
    self.next = None

  def find(self, data: int):
    print('hi')
    return
  
  @classmethod
  def from_list(self, lst: list[int]) -> 'Node':
    if len(lst) == 0:
      return None
    res = Node(lst[0])
    cur = res
    for i in range(1, len(lst)):
      cur.next = Node(lst[i])
      cur = cur.next
    return res
  
  def to_list(self) -> list[int]:
    res: list[int] = []
    cur = self
    while cur != None:
      res.append(cur.data)
      cur = cur.next
    return res

  def remove(self, data: int): # removes all but first occurence of data
    found_first: bool = False
    prev = None
    cur = self
    while cur != None:
      if cur.data == data:
        if found_first:
          prev.next = cur.next
        else:
          found_first = True
          prev = cur
      else:
        prev = cur
      cur = cur.next

  def remove_duplicates(self): # removes all duplicates after first
    cur = self
    while cur != None:
      cur.remove(cur.data)
      cur = cur.next

  def remove_duplicates_hash(self): # remove duplicates using 
    freq = Counter()
    prev = None
    cur = self
    while cur != None:
      if freq[cur.data] > 0:
        prev.next = cur.next
      else:
        prev = cur
      freq[cur.data] = 1
      cur = cur.next
  

inp = [1,2,4,24,4,4,3,3,5,1,3,4,5,1,1,1]
print(inp)

n = Node.from_list(inp)
n.remove_duplicates_hash()

print(n.to_list())

n2 = Node.from_list(inp)
n2.remove_duplicates()

print(n2.to_list())

assert(n.to_list() == n2.to_list())

print('Passed!')