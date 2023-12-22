#include <bits/stdc++.h>
using namespace std;

int a[100010],b[100010];
int dp[100010][3];
int main() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        int mx = dp[i-1][0];
        for(int j=1;j<3;j++) {
            mx = max(mx, dp[i-1][j]);
            dp[i][j] = dp[i-1][j-1] + a[i];
        }
        dp[i][0] = mx + b[i];
    }
    cout<< max(dp[n][0], max(dp[n][1], dp[n][2])) <<'\n';
}