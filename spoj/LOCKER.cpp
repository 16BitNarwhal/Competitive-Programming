#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9+7;
ll fastpow(ll a, ll b) { return (b==0?1:(b&1?a:1)*(fastpow((a*a)%m,b/2)%m)%m); }

int main() {
    int t; cin >> t;
    while(t--) {
        ll n, res; cin >> n;
        if (n<3) res = n;
        else if (n%3==1) res = 4*fastpow(3, (n-4)/3);
        else if (n%3==2) res = 2*fastpow(3, (n-2)/3);
        else res = fastpow(3, n/3);
        res %= m;
        cout << res << '\n';
    }
}