#include <bits/stdc++.h>
using namespace std;
const int MM = 110;
int n, costH, costV, a[MM];
void solve() { 
    cin >> n >> costV >> costH;
    for (int i=1;i<=n;i++) cin>>a[i];
    int ans=2e9;
    for (int i=1;i<n;i++) {
        if (a[i]==a[i+1]+1) { // next is bottom left
            ans = min(ans, costV);
            ans = min(ans, costH);
        } else if (a[i]==a[i+1]-1) { // next is bottom right
            ans = min(ans, costV);
            if (a[i]>0) ans = min(ans, costH);
        } else if (a[i]==a[i+1]) { // next is bottom middle
            ans = min(ans, costH+costV);
            ans = min(ans, costH+costH);
        } else {
            ans = 0;
        }
    }
    cout << ans << '\n';    
}
int main() {
    int t;cin>>t;
    while(t--) solve();
}