#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll MOD = 998224353;
ll a[MM];
int main() {
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        ll mnc=0, mxc=0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            mnc += a[i];
            mxc += a[i];
            mxc = max(abs(mxc), abs(mnc));
        }
        cout << mxc << '\n';
    }
}