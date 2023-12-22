#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+10;
ll a[MM], pre[MM], n;
void sol(int sum, int x) {
    for (int i=0;i<n+2;i++) {
        if (i!=sum && i!=x) 
            cout<<a[i]<<' ';
    }
    cout << '\n';
}
void solve() {
    cin>>n;
    for (int i=0;i<n+2;i++)
        cin >> a[i];
    sort(a, a+n+2);
    pre[0] = a[0];
    for (int i=1;i<n+2;i++) {
        pre[i] = pre[i-1] + a[i];
    }
    // make n+1 (last) the sum
    for (int j=0;j<n+1;j++) { 
        // make jth item 'x'
        if (pre[n] - a[j] == a[n+1]) {
            sol(n+1, j); 
            return;
        }
    }
    // make n (second last) the sum
    // make n+1 (last) item 'x' 
    if (pre[n-1] == a[n]) {
        sol(n, n+1);
        return;
    }    
    cout << "-1\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while (t--) solve();
}