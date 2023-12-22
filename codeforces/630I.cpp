#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastpow(ll a, ll b) { return (b==0?1:(b&1?a:1)*fastpow(a*a, b/2)); }

int main() {
    int n;cin>>n;
    cout << 2*4*3*fastpow(4,n-3) + (n>3?(n-3)*4*3*3*fastpow(4,n-4):0);
}