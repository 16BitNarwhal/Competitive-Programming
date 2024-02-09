#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        sort(coins.rbegin(), coins.rend());
        for (int c : coins) {
            for (int i=0;i<=amount-c;i++) {
                if (dp[i] == -1) continue;
                if (dp[i+c] == -1) dp[i+c] = dp[i]+1;
                else dp[i + c] = min(dp[i + c], dp[i]+1);
            }
        }
        return dp[amount];
    }
};
