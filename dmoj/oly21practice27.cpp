// if have time, try segment tree ranged update
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
typedef long long ll;
struct order { int v, l, r; } orders[MM];
int N, M; 
ll ar[MM], psa[MM];
bool check(int mid) {
    memset(psa, 0, sizeof psa);
    for (int i=1;i<=mid;i++) {
        psa[orders[i].l] += orders[i].v;
        psa[orders[i].r+1] -= orders[i].v;
    }
    for (int i=1;i<=N;i++) {
        psa[i] += psa[i-1];
        if (ar[i] < psa[i]) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for (int i=1;i<=N;i++) cin>>ar[i];
    for (int i=1,v,l,r;i<=M;i++)
        cin >> orders[i].v >> orders[i].l >> orders[i].r;
    int l=1,r=M;
    while (l<r) {
        int mid = (l+r)/2;
        if (check(mid)) l = mid+1;
        else r = mid;
    }
    if (l==M) {
        cout << "0\n"; return 0;
    }
    cout << "-1\n" << l << '\n';
}