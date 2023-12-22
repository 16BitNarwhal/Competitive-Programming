#include <bits/stdc++.h>
using namespace std;
const int n = 20;

int main() {
    long long dp[n+1][n+1];
    for(int i=0;i<=n;i++) {
        dp[i][0]=1;
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    cout<<dp[n][n]<<"\n";

}