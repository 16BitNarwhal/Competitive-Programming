#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(ll n) {
    ll res = 0;
    while(n >= 5) {
        n /= 5;
        res += n;
    }
    return res;
}

ll search(ll x) {
    ll l=0,r=1e10,m;
    while(l<r) {
        m = (l+r+1)/2;
        if(count(m) <= x) l = m;
        else r = m-1;
    }
    return r;
}

int main() {
    ll a,b;cin>>a>>b;
    cout<<search(b) - search(a-1)<<'\n';
}