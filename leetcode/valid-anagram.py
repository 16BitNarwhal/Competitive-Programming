from collections import Counter

s = input()
t = input()

# # O(n)
# def isAnagram(s, t):
#     return Counter(s) == Counter(t)

# O(n log n)
def isAnagram(s, t):
  return sorted(list(s)) == sorted(list(t))

print(isAnagram(s, t))