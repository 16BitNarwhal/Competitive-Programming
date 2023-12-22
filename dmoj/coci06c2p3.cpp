#include <bits/stdc++.h>
using namespace std;
const int MM = 55; 
int n, m, t;
string a, b, ans;
int main() {
    cin >> n >> m >> a >> b >> t;
    ans.resize(n+m);
    for (int i=0;i<n;i++) {
        int idx = n-i-1;
        idx += min(max(t-i, 0), m);
        ans[idx] = a[i];
    }
    for (int i=0;i<m;i++) {
        int idx = n+i;
        idx -= min(max(t-i, 0), n);
        ans[idx] = b[i];
    }
    cout << ans;
}