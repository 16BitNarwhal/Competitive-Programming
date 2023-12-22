#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+2;
int N, M, a[MM], b[MM], dp[MM][MM];
int main() {
    cin >> N >> M;
    for (int i=1;i<=N;i++) cin>>a[i];
    for (int i=1;i<=M;i++) cin>>b[i];
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[N][M] << '\n';
}