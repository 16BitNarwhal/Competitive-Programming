def minDistance(word1: str, word2: str) -> int:
  dp = [[0] * (len(word1)+1) for _ in range(len(word2)+1)]
  for i in range(0, len(word1)+1):
    dp[0][i] = i
  for i in range(0, len(word2)+1):
    dp[i][0] = i

  for i in range(1, len(word2)+1):
    for j in range(1, len(word1)+1):
      dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1 # add / delete
      dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1) # replace
      if word1[j-1]==word2[i-1]:
        dp[i][j] = min(dp[i][j], dp[i-1][j-1])   # no need to replace. same char
  
  return dp[len(word2)][len(word1)]

word1 = input()
word2 = input()

print(minDistance(word1, word2))