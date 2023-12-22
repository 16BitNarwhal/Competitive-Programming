#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 1e9+7;
int N, ar[MM];
int main() {
    cin >> N;
    for (int i=1;i<=N;i++) 
        cin >> ar[i];
    ll ans = 1, prev=1, mx=ar[1];
    for (int i=2;i<=N;i++) {
        if (ar[i] >= mx) {
            mx = ar[i];
            ans = ans * (i - prev + 1) % mod;
            prev = i;
        }
    }
    cout << ans << '\n';
}