#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll fastMul(ll x, ll y, ll mod) {
    if(y==0) return 0;
    return ((y&1)*x + fastMul((x+x)%mod, y>>1, mod)) % mod;
}
ll fastPow(ll x, ll y, ll mod) {
    if(y==0) return 1;
    return fastMul((y&1) ? x:1, fastPow(fastMul(x,x,mod),y>>1,mod),mod);
}

const int maxrand = 50;
mt19937_64 gen(time(0));

bool isprime(ll x) {
    if(x==2) return 1;
    uniform_int_distribution<ll> dist(2, x);
    for(int i=0;i<maxrand;i++) {
        ll a = dist(gen);
        while(a==x) a = dist(gen);
        if(fastPow(a,x-1,x)!=1) return 0;
    }
    return 1;
}

int main() {
    ll x;cin>>x; 
    if(x<2) x=2;
    while(1) {
        if(isprime(x)) {
            cout<<x<<'\n';
            return 0;
        }
        x++;
    }
}