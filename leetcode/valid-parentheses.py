class Solution:
    def isValid(self, s: str) -> bool:
        l = []
        opened = ['(','[','{']
        closed = [')',']','}']
        for c in s:
            if c in opened:
                l.append(c)
            else:
                if len(l)==0 or opened.index(l[-1]) != closed.index(c):
                    print(l, c)
                    return False
                else:
                    l.pop()
        return len(l)==0