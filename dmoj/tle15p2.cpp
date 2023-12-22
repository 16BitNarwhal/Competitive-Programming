#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

int n,m,t;
ll mw[1000001];
pair<ll,ll> ppl[1000001];

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.f < b.f;
}

int main() {
    cin>>n>>m>>t;
    for(int i=0;i<m;i++) 
        cin>>ppl[i].f>>ppl[i].s;
    sort(ppl, ppl+m, );
    for(int i=0;i<m;i++) {
        int j = upper_bound(mw, mw+n, ppl[i].f)-mw-1;
        if(j) {
            if(ppl[i].f - mw[0] >= t) {
                cout<<mw[0]<<'\n';
                return 0;
            }
            mw[j] = ppl[i].f + ppl[i].s;
        } else mw[0] += ppl[i].s;
        sort(mw, mw+n);
    }
    cout<<mw[0]<<'\n';
}