#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;cin>>t;
    while(t--) {
        ll n,s;cin>>n>>s;
        ll x = n*(n+1)/2 - s; 
        cout << min((x-1)/2, n+1 - (x/2+1)) << '\n';
    }
}
