#include <bits/stdc++.h>
using namespace std;
const int m = 10;

int bpow(int a, int b) {
    if (b==0) return 1;
    return (b&1?a:1)*(bpow((a*a)%m, b/2)%m)%m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int a, b; 
        cin >> a >> b;
        cout << bpow(a%m, b) << '\n';
    }
}