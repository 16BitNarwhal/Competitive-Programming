#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 100;
ll fastpow(ll a, ll b) { return (b==0?1:(b&1?a:1)*fastpow(a*a%m, b/2)%m)%m; }

int main() {
    int n;cin>>n;
    cout << fastpow(5, n);
}