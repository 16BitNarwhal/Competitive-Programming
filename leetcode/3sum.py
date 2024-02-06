um.class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()
        n = len(nums)
        for i in range(n):
            j=i+1
            k=n-1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    ans.add((nums[i], nums[j], nums[k]))
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    j += 1
        return ans