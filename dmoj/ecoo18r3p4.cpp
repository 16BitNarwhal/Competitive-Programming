#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXN = 5e5+5;
int n,m,a[MXN], b[MXN];
ll d[MXN];
ll dist(int o) {
    if(d[o]!=0) return d[o];
    ll ret=0;
    for(int i=0;i<n;i++) {
        int x = abs(a[i]-b[(i+o)%n]);
        ret += min(m-x, x);
    } 
    return d[o] = ret;
}

ll search(int l,int r) {
    while(l<=r) {
        int m = (l+r)/2;
        if(dist(m)<=dist(m+1)) r = m-1;
        else l = m+1;
    }
    return dist(l);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int T_=10;
    while(T_--) {
        cin>>n>>m; 
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<=n+1;i++) d[i] = 0;
        sort(a,a+n);
        sort(b,b+n);
        cout<<min(search(0,(n-1)/2),search(n/2,n))<<'\n';
    } 
}