#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(a==0) return b;
    return gcd(b%a, a);
}
int main() {
    int n;cin>>n;
    ll cgcd=0;
    for(int i=0,buf;i<n;i++) {
        cin>>buf;
        cgcd = gcd(cgcd, buf);
    }
    if(cgcd==1) {
        cout<<"DNE\n";
        return 0;
    }
    ll cgcd1 = cgcd;
    ll n1 = min((ll)sqrt(cgcd)+1,cgcd);
    ll res = 0;
    for(ll i=2;i<=n1;i++) {
        while(cgcd%i==0) {
            cgcd /= i;
            res = i;
        }
    }
    if(!res) cout<<cgcd1<<'\n';
    else if(cgcd>1) cout<<cgcd<<'\n';
    else cout<<res<<'\n';
}