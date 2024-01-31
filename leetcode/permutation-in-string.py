from collections import Counter

s1 = input()
s2 = input()

def checkInclusion(s1: str, s2: str) -> bool:
  if len(s1) > len(s2):
    return False
  
  # sliding window
  c1 = Counter(s1)
  c2 = Counter(s2[:len(s1)])

  if c1==c2:
    return True

  for i in range(len(s2)-len(s1)):
    c2[s2[i]] -= 1
    c2[s2[i + len(s1)]] += 1

    if c1==c2:
      return True

  return False

print(checkInclusion(s1, s2))