// https://atcoder.jp/contests/agc009/tasks/agc009_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
    ll n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    ll ans=0;
    for(int i=n-1;i>=0;i--) {
        a[i] += ans;
        a[i] %= b[i];
        if(a[i])
            ans += b[i]-a[i];
    }
    cout<<ans<<"\n";
}