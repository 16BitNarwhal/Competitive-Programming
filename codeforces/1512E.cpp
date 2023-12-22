#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, l, r, s; cin >> n >> l >> r >> s;
    if (s > (n-(r-l) + n) * (r-l+1) / 2) {
        cout << "-1\n"; return;
    }
    vector<int> ar(r-l+1);
    for (int i=0;i<=r-l;i++)
        ar[i] = i+1;
    s -= (r-l+1)*(r-l+2)/2;
    if (s<0) {
        cout << "-1\n"; return;
    }
    int add_each = s/(r-l+1), leftover = s%(r-l+1);
    for (int i=r-l-leftover+1;i<=r-l;i++)
        ar[i]++;
    for (int i=0;i<=r-l;i++)
        ar[i] += add_each;
    map<int, bool> used;
    for (int i=0;i<=r-l;i++)
        used[ar[i]] = 1;
    for (int i=1;i<l;i++) {
        for (int j=1;j<=n;j++) {
            if (!used[j]) {
                cout << j << ' ';
                used[j] = 1;
                break;
            }
        }
    }
    for (int i=0;i<=r-l;i++) 
        cout << ar[i] << ' ';
    for (int i=r+1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (!used[j]) {
                cout << j << ' ';
                used[j] = 1;
                break;
            }
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}