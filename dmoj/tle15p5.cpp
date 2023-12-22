#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2001], cf[2001];
const ll mod = 1e9+7;

ll fastMul(ll a, ll b) {
    ll res=0;
    while(b>0) {
        if(b&1) res = (res+a)%mod;
        b >>= 1;
        a = (a+a)%mod;
    }
    return res;
}

ll fastPow(ll a, ll b) {
    ll res=1;
    while(b>0) {
        if(b&1) res = fastMul(res,a);
        b >>= 1;
        a = fastMul(a,a);
    }
    return res;
}

int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int m;cin>>m;m--;
    cf[0] = 1;
    for(int i=1;i<n;i++) 
        cf[i] = fastMul(fastMul(cf[i-1],m+i),fastPow(i,mod-2));
    for(int i=0;i<n;i++) {
        ll sm = 0;
        for(int j=0;j<=i;j++) {
            sm = (sm + fastMul(a[j], cf[i-j])) % mod;
        }
        cout<<sm<<' ';
    }
    cout<<'\n';
}