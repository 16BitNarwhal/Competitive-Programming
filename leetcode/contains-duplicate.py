nums = [int(x) for x in input().split()]

def containsDuplicate(nums):
  return len(nums) != len(set(nums))