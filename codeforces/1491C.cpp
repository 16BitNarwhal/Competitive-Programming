#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
int n,a[MM];
ll pek[MM]; // # pekoras
void solve() {
    memset(pek, 0, sizeof pek);
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    ll ans=0;
    for (int i=0;i<n;i++) {
        if (pek[i] < a[i]-1) { // not enough pekoras for cur
            ans += a[i]-1-pek[i]; // new pekoras added
            pek[i] += a[i]-1-pek[i];
        }
        pek[i+1] += pek[i] - a[i] + 1; // extra pekoras carry over to next
        for (int j=i+2;j<min(n,i+a[i]+1);j++) pek[j]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}