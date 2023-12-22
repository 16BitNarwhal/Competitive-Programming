#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 355, mod = 1e9+7;
// dp[i ppl][j task] at least 1 programmer happy
int N;
ll dp[MM][MM], fac[MM], inv[MM];
ll qpow(ll a, ll b) { return (b==0)?1:(b&1?a:1)*qpow(a*a%mod, b>>1) % mod; }
void init() {
    fac[0] = inv[0] = 1;
    for (int i=1;i<MM;i++) fac[i] = fac[i-1] * i % mod;
    for (int i=1;i<MM;i++) inv[i] = qpow(fac[i], mod-2);
}
ll c(int n, int k) { return fac[n] * inv[k] % mod * inv[n-k] % mod; }
int main() {
    init();
    cin >> N;
    dp[1][1] = 1;
    for (int i=2;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            // case: i th programmer happy
            if (j>=i) // # ways j tasks go i slots * # total ways leftover (j-i tasks pick i-1 ppl)
                dp[i][j] = c(j, i) * qpow(i-1, j-i) % mod;
            // case: i th programmer not happy (give k tasks where k /= i)
            for (int k=0;k<=j;k++) {
                // # ways [i-1 ppl][j-k tasks] * # ways j tasks go k slots
                if (k!=i) dp[i][j] = (dp[i][j] + dp[i-1][j-k] * c(j, k) % mod) % mod;
            }
        }
    }
    cout << dp[N][N];
}