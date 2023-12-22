#include <bits/stdc++.h>
using namespace std;
const int MM = 2001;
int N, dp[MM][MM];
int main() {
    cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) {
        char c; cin >> c; dp[i][j] = (c=='#');
    }
    for (int i=1;i<N;i++) {
        for (int j=2;j<N;j++) {
            if (dp[i][j]) 
                dp[i][j] += min(min(dp[i][j-1], dp[i][j-2]), dp[i-1][j-1]); 
        }
    }
    int ans=0;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) ans += dp[i][j];
    cout << ans << '\n';
}