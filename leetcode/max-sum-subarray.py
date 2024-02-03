class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        mx = -1e9
        for i in range(len(nums)):
            sum += nums[i]
            mx = max(mx, sum)
            if sum < 0:
                sum = 0
        return mx