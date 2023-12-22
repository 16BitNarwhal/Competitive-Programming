#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll x,y;

void euclid(ll a, ll b) {
    if(a==0) {
        x=0;y=1;
        return;
    }
    euclid(b%a,a);
    ll tmp = x;
    x = y - (b/a*x);
    y = tmp;
}

int main() {
    ll n,m;
    cin>>n>>m;
    euclid(n,m);
    ll res = (x+m)%m;
    cout<<res<<'\n';
}