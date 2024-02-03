class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        has_odd = False
        res = 0
        for num in c.values():
            if num%2==1:
                has_odd = True
            res += (num//2)*2
        return res + int(has_odd)