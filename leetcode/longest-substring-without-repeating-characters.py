class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = 0
        c = Counter()
        ans = 0
        while j < len(s):
            while j < len(s) and c[s[j]] == 0:
                c[s[j]] += 1
                j += 1
            ans = max(ans, j-i)
            c[s[i]] -= 1
            i += 1
        return ans