#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int N, M, cap[MM], ar[MM];
ll P[MM], V[MM], cst[MM], dp[MM];
int main() { 
    cin >> N >> M;
    int ptr=1;
    for (ll i=1, n, a, b;i<=N;i++) {
        cin >> n >> a >> b;
        ll x = n*b;
        for (ll j=0;x>=(1<<j)*b;j++) {
            x -= (1<<j) * b;
            V[ptr] = (1<<j) * a;
            P[ptr] = (1<<j) * b;
            ar[ptr] = i;
            ptr++;
        }
        if (x) {
            V[ptr] = x/b*a;
            P[ptr] = x;
            ar[ptr] = i;
            ptr++;
        }
    }
    N = ptr - 1;
    for (int i=1;i<=N;i++) {
        for (int j=5000;j>=V[i];j--)
            dp[j] = max(dp[j], dp[j-V[i]] + P[i]);
    }
    for (int i=0;i<M;i++)
        cin >> cap[i] >> cst[i];
    ll ans=-1e18; 
    for (int i=0;i<M;i++) {
        ans = max(ans, dp[cap[i]] - cst[i]);
    }
    cout << ans << '\n';
}