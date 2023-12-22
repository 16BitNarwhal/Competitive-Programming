#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool pr(ll x) {
    for(ll i=2;i<=sqrt(x);i++)
        if(x%i==0) return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll x;cin>>x;
    if(x<2) {
        cout<<"2\n";
        return 0;
    }
    while(1) {
        if(pr(x)) {
            cout<<x<<'\n';
            return 0;
        }
        x++;
    }
}