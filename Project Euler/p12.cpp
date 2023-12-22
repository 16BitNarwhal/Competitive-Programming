#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (1e9);

ll div(ll n) {
    ll res = 0;
    for(ll i=1;i*i<=n;i++) {
        ll x = n/i;
        if(x*i == n) {
            res++;
            if(i*i!=n) res++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    ll x=0;
    ll inp; cin>>inp;
    for(ll i=1;i<=INF;i++) {
        x += i;
        if(div(x) > inp) {
            cout<<x<<"\n";
            return 0;
        }
    }
}