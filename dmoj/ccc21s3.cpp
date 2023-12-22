// binary search
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N, P[MM], W[MM], D[MM];
ll cost(int c) {
    ll ret=0;
    for (int i=0;i<N;i++) {
        if (c<P[i]-D[i]) ret += 1LL*(P[i]-D[i]-c)*W[i];
        else if (c>P[i]+D[i]) ret += 1LL*(c-(P[i]+D[i]))*W[i];
    }
    return ret;
}
int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin>>P[i]>>W[i]>>D[i];
    int l=0, r=1e9, m;
    while(l<r) {
        m = (l+r)/2;
        if (cost(m) < cost(m+1)) r = m;
        else l = m+1;
    }
    cout << cost(l);
}
