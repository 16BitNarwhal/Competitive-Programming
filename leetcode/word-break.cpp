class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i=0;i<=n;i++) {
            for (string w : wordDict) {
                int m = w.length();
                if (i+m<=n) {
                    if (s.substr(i, m) == w) 
                        dp[i+m] = dp[i] || dp[i+m];
                }
            }
        }
        return dp[n];
    }
};