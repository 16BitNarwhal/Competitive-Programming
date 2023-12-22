#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
ld fastpow(ld a, ll b) { return (b==0?1:(b&1?a:1)*fastpow(a*a, b/2)); }

int main() {
    int n,t;cin>>n>>t;
    cout << fixed;
    cout << n * fastpow(1.000000011, t);
}