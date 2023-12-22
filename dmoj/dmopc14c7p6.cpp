// use seg tree + lazy propagation
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, ar[MM], seg[2*MM];
bool update(int p) {
    int l=p*2, r=p*2+1;
    seg[p] = seg[l] + seg[r];
    if (seg[p]<0) return 0;
    if (p==1) return 1;
    return update(p/2);
}
bool change(int p, int val) {
    if (val<0) return 0;
    p += N-1;
    seg[p] = val;
    return update(p/2);
}
int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin>>ar[i];
    int ans=0;
    change(ar[0], -1);
    change(ar[1], 1);
    for (int i=1;i<=N/2;i++) {
        change(ar[i], -1);
        change(ar[i*2], 1);
        bool tmp = change(ar[i*2+1], 1);
        cout << i << ' ' << tmp << '\n';
        if (tmp) {
            ans = i;
        }
    }
    cout << ans;
}