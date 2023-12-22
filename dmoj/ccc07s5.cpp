#include <bits/stdc++.h>
using namespace std;
// dp[i ball][j pin]
int pins[30005], ar[30005], sum[30005], dp[505][30005];
int t,n,k,w;

int main() {
    cin>>t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        cin>>n>>k>>w;
        for (int i=0;i<n;i++) cin>>pins[i];
        for (int i=0;i<n;i++) {
            sum[i] = pins[i] + (i ? sum[i-1] : 0);  
            ar[i] = sum[i] - (i>=w ? sum[i-w] : 0);
        }
        for (int i=1;i<=k;i++) {
            for (int j=1;j<n;j++) {
                dp[i][j] = max(dp[i][j-1], ar[j] + ((j>=w) ? dp[i-1][j-w] : 0));
            }
        }
        cout << dp[k][n-1] << '\n';
    }
}