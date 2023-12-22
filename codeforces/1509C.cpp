#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2002;
// dp[l][r] = min for subarray s[l...r]
int N;
ll ar[MM], dp[MM][MM]; 
void solve() {
    cin >> N;
    for (int i=1;i<=N;i++) cin>>ar[i];
    sort(ar+1, ar+N+1);
    for (int len=1;len<=N;len++) {
        for (int l=1;l+len<=N;l++) {
            int r = l+len;
            dp[l][r] = ar[r]-ar[l] + min(dp[l+1][r], dp[l][r-1]);
        }
    }
    cout << dp[1][N] << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}