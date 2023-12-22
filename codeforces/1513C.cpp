#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2, mod=1e9+7;
int N, M, dp[MM]; 
void solve() {
    cin >> N >> M;
    long long ans = 0;
    while (N > 0) {
        int x = N % 10;
        if (M + x < 10) ans++;
        else ans += dp[M - 10 + x];
        ans %= mod;
        N /= 10;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<9;i++) dp[i] = 2;
    dp[9] = 3;
    for (int i=10;i<MM;i++) {
        dp[i] = (dp[i-9] + dp[i-10]) % mod;
    }
    int t;cin>>t;
    while(t--) solve();
}