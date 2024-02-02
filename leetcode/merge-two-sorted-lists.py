from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None:
            return list2
        if list2 == None:
            return list1
        cur = None
        if list1.val < list2.val:
            cur = ListNode(list1.val)
            list1 = list1.next
        else:
            cur = ListNode(list2.val)
            list2 = list2.next
        
        head = cur

        while list1 and list2:
            if list1.val < list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next
        
        if list1:
            cur.next = list1
        else:
            cur.next = list2
        return head

ListNode1 = ListNode(1, ListNode(2, ListNode(4)))
ListNode2 = ListNode(1, ListNode(3, ListNode(4)))

sol = Solution()
res = sol.mergeTwoLists(ListNode1, ListNode2)

while res:
    print(res.val)
    res = res.next