#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll N, Q, ar[MM], ps[MM][2], ips[MM][2];
void fun() {
    for (int i=1;i<=N;i++) { 
        ps[i][0] = (i&1?1:-1)*ar[i] + ps[i-1][0];
        ps[i][1] = (i&1?-1:1)*ar[i] + ps[i-1][1];
        ips[i][0] = (i&1?1:-1)*i*ar[i] + ips[i-1][0];
        ips[i][1] = (i&1?-1:1)*i*ar[i] + ips[i-1][1];
    }
}
void solve() {
    cin >> N >> Q;
    for (int i=1;i<=N;i++) cin >> ar[i];
    fun(); 
    ll ans=0;
    while (Q--) {
        char op;cin>>op;
        if (op=='U') {
            int j,x;cin>>j>>x;
            ar[j] = x;
            fun();
        } else {
            int l, r; cin>>l>>r;
            int p = (l+1)&1;
            ans += (ips[r][p] - ips[l-1][p]) - (l-1)*(ps[r][p] - ps[l-1][p]);
        }
    }
    cout << ans << '\n';
}
int main() {
    int t; cin >> t; 
    for (int i=1;i<=t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}