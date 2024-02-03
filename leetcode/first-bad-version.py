# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 0
        r = n-1
        ans = n
        while l <= r:
            m = (l+r)//2
            if isBadVersion(m):
                r = m-1
                ans = m
            else:
                l = m+1
        return ans