#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 1e9+7;
int N, D, ar[MM], freq[MM];
ll fac[MM], inv[MM];
ll qpow(ll a, ll b) { return (b==0)?1:(b&1?a:1)*qpow((a*a)%mod, b>>1)%mod; }
void init() {
    fac[0] = inv[0] = 1;
    for (int i=1;i<MM;i++) fac[i] = (fac[i-1] * i) % mod;
    for (int i=1;i<MM;i++) inv[i] = qpow(fac[i], mod-2);
}
ll choose(int n, int k) { return fac[n] * inv[k] % mod * inv[n-k] % mod; }
int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    init(); memset(freq, 0, sizeof freq);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin>>ar[i]; freq[ar[i]]++;
    }
    sort(ar+1, ar+N+1);
    for (int i=1;i<=N;i++) freq[i] += freq[i-1];
    cin >> D;
    while (D--) {
        int k;cin>>k;
        int p = ar[k], need = k-freq[p-1], tot = freq[p]-freq[p-1];
        cout << choose(tot, need) << '\n';
    }
}