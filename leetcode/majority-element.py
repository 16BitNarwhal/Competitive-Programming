class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        c = Counter(nums)
        res = 0
        for e, cnt in c.items():
            if cnt > c[res]:
                res = e
        return res