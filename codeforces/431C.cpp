#include <bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int n,k,d,dp[102][2];
int main() {
    cin >> n >> k >> d;
    memset(dp, 0, sizeof dp);
    dp[0][0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=k;j++) {
            if (i-j<0) break;
            bool ok = j>=d;
            dp[i][ok] = (dp[i][ok]+dp[i-j][0])%m;
            dp[i][1] = (dp[i][1]+dp[i-j][1])%m;
        }
    }
    cout << dp[n][1] << '\n'; 
}