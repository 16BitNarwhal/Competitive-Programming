#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l[100005],r[100005],h[100005],dp[100005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>r[i]>>l[i]>>h[i];
    for(int i=n-1;i>=0;i--) {
        int j = lower_bound(r, r+n, r[i]+l[i]) - r;
        dp[i] = max(h[i] + dp[j], dp[i+1]);
    }
    cout<<dp[0]<<'\n';
}
