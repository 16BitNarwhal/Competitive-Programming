#include <bits/stdc++.h>
using namespace std;
#define lc 2*i
#define rc 2*i+1
const int MM = 1e6+2;
struct node { int l, r, lz, v; } seg[4*MM];
int N, M, ar[MM], k;
int build(int i, int l, int r) {
    seg[i].l = l, seg[i].r = r;
    if (l==r) return seg[i].v=ar[l];
    int mid = (l+r)/2;
    return seg[i].v=min(build(lc, l, mid), build(rc, mid+1, r));
}
int update(int i, int p) {
    if (seg[i].l==p && seg[i].r==p) return seg[i].v = ar[p];
    int mid = (seg[i].l + seg[i].r) / 2; 
    if (p <= mid) return seg[i].v=min(update(lc, p), seg[rc].v);
    else return seg[i].v=min(update(rc, p), seg[lc].v);
}
int query(int i, int l, int r) { 
    if (seg[i].l == l && seg[i].r == r) {
        if (seg[i].v < k) {
            if (l==r) return l;
            int mid = (seg[i].l + seg[i].r) / 2;
            if (seg[lc].v < k) return query(lc, l, mid);
            else if (seg[rc].v < k) return query(rc, mid+1, r);   
        }
        return -1;
    }
    int mid = (seg[i].l + seg[i].r) / 2;
    if (r <= mid) return query(lc, l, r);
    if (l > mid) return query(rc, l, r);
    int left = query(lc, l, mid);
    if (left < 0) return query(rc, mid+1, r);
    return left;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M; 
    for (int i=1;i<=N;i++) cin>>ar[i];
    build(1, 1, N);
    int ans = 0; 
    while(M--) {  
        int op;cin>>op;
        if (op==1) {
            int p, x;cin>>p>>x;
            p ^= ans, x ^= ans; // encrypt
            ar[p] = x;
            update(1, p); 
        } else {
            int l, r; cin>>l>>r>>k;
            l ^= ans, r ^= ans, k ^= ans; // encrypt
            ans = query(1, l, r);
            cout << ans << '\n';
        }
    }
}