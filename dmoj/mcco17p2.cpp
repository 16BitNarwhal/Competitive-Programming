#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
struct node { int l, r; ll lz, v; } seg[4*MM];
void build(int i, int l, int r) { 
    seg[i].l = l, seg[i].r = r;
    if (l==r) { return; } // all val start as 0
    int mid = (l+r)/2;
    build(2*i, l, mid);
    build(2*i+1, mid+1, r);
}
void resolve_lz(int i) {
    seg[i].v += seg[i].lz;
    seg[2*i].lz += seg[i].lz;
    seg[2*i+1].lz += seg[i].lz;
    seg[i].lz = 0;
}
ll update(int i, int l, int r, int v) {
    if (l>r) return 0;
    resolve_lz(i);
    if (seg[i].l==l && seg[i].r==r) {
        seg[i].v += v;
        seg[2*i].lz += v;
        seg[2*i+1].lz += v; 
        return seg[i].v;
    }
    int mid = (seg[i].l + seg[i].r) / 2;
    return seg[i].v = max(update(2*i, l, min(mid, r), v), 
                        update(2*i+1, max(l, mid+1), r, v));
    // if (r <= mid) return seg[i].v = update(2*i, l, r, v);
    // if (l > mid) return seg[i].v = update(2*i+1, l, r, v);
    // return seg[i].v = max(update(2*i, l, mid, v),
    //                     update(2*i+1, mid+1, r, v));
}
ll query(int i, int l, int r) { // same as update but doesn't change seg 
    if (l>r) return 0;
    resolve_lz(i);
    if (seg[i].l==l && seg[i].r==r)
        return seg[i].v;
    int mid = (seg[i].l + seg[i].r) / 2;
    if (r <= mid ) return query(2*i, l, r);
    if (l > mid) return query(2*i+1, l, r);

    return max(query(2*i, l, mid), query(2*i+1, mid+1, r));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K, Q;
    cin >> N >> K >> Q;
    build(1, 1, N);
    while (Q--) {
        int op;cin>>op;
        if (op==0){
            int p,v;cin>>p>>v; p++;
            p = min(p, N);
            update(1, max(1,p-K+1), p, v);
        } else {
            int l,r;cin>>l>>r; l++, r++;
            l = min(l, N), r = min(r, N);
            cout << update(1, l, r, 0) << '\n';
        }
    }
}