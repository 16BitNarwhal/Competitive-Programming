from collections import Counter

def palindrome_permutation(s: str) -> bool:
  c = Counter(s)
  odds = 0
  for k, v in c.items():
    if k != ' ':
      odds += (v%2==1)
  
  return odds <= 1

s = input()

print(palindrome_permutation(s))
