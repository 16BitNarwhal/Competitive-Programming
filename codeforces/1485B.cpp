#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n,q,k,a[MM]; 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> k;
    for (int i=1;i<=n;i++) 
        cin>>a[i]; 
    while(q--) {
        int l,r;cin>>l>>r;
        cout << k + a[r] - a[l] - 2*(r-l) -1 << '\n';
    }
}