class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        c1 = Counter(list(ransomNote))
        c2 = Counter(list(magazine))
        
        for l, c in c1.items():
            if c2[l] < c:
                return False
        return True