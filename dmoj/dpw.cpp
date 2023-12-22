// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<int,int> pi;
// const int MM = 2e5+2;
// struct node { int l, r; ll lz, v; } seg[3*MM];
// int N, M;
// vector<pi> p[MM];
// void build(int l, int r, int idx) {
//     seg[idx].l = l; seg[idx].r = r;
//     if (l==r) { seg[idx].lz = seg[idx].v = 0; return; }
//     int mid = (l+r)/2;
//     build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
// }
// void pushdown(int idx) {
//     int lc = 2*idx, rc = 2*idx+1;
//     seg[lc].lz += seg[idx].lz; seg[rc].lz += seg[idx].lz;
//     seg[lc].v += seg[idx].lz; seg[rc].v += seg[idx].lz;
//     seg[idx].lz = 0;
// }
// void update(int l, int r, ll val, int idx) {
//     if (seg[idx].l == l && seg[idx].r == r) {
//         seg[idx].lz += val; seg[idx].v += val; return;
//     }
//     if (seg[idx].lz) pushdown(idx);
//     int mid = (seg[idx].l + seg[idx].r)/2;
//     if (r <= mid) update(l, r, val, 2*idx);
//     else if (l > mid) update(l, r, val, 2*idx+1);
//     else { update(l, mid, val, 2*idx); update(mid+1, r, val, 2*idx+1); }
//     seg[idx].v = max(seg[2*idx].v, seg[2*idx+1].v);
// }
// ll query(int l, int r, int idx) {
//     if (seg[idx].l == l && seg[idx].r == r) return seg[idx].v;
//     if (seg[idx].lz) pushdown(idx);
//     int mid = (seg[idx].l + seg[idx].r)/2;
//     if (r <= mid) return query(l, r, 2*idx);
//     if (l > mid) return query(l, r, 2*idx+1);
//     return max(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
// }
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     cin >> N >> M;
//     build(0, N, 1);
//     for (int i=1, l, r, v; i<=M; i++) {
//         cin >> l >> r >> v; 
//         p[r].push_back({l, v});
//     }
//     for (int i=1;i<=N;i++) {
//         ll mx = query(0, i-1, 1); update(i, i, mx, 1);
//         for(pi e: p[i]) {
//             update(e.first, i, e.second, 1);
//         }
//     }
//     cout << seg[1].v << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int MM = 2e5+2;
struct node { int l, r; ll lz, v; } seg[3*MM];
int N, M;
vector<pi> p[MM]; // p[right] = {left, value};
void build(int l, int r, int idx) {
    seg[idx].l = l, seg[idx].r = r;
    if (l==r) { seg[idx].v=seg[idx].lz=0; return; }
    int mid = (l+r)/2;
    build(l, mid, idx*2), build(mid+1, r, idx*2+1);
}
void pushdown(int idx) {
    int lc = idx*2, rc = idx*2+1;
    seg[lc].lz += seg[idx].lz; seg[rc].lz += seg[idx].lz;
    seg[lc].v += seg[idx].lz; seg[rc].v += seg[idx].lz;
    seg[idx].lz = 0;
}
void update(int l, int r, ll val, int idx) {
    if (seg[idx].l==l && seg[idx].r==r) {
        seg[idx].lz += val, seg[idx].v += val; return;
    }
    if (seg[idx].lz) pushdown(idx);
    int mid = (seg[idx].l+seg[idx].r)/2;
    if (r <= mid) update(l, r, val, idx*2);
    else if (l > mid) update(l, r, val, idx*2+1);
    else update(l, mid, val, idx*2), update(mid+1, r, val, idx*2+1);    
    seg[idx].v = max(seg[idx*2].v, seg[idx*2+1].v);
}
ll query(int l, int r, int idx) {
    if (seg[idx].l==l && seg[idx].r==r) return seg[idx].v;
    if (seg[idx].lz) pushdown(idx);
    int mid = (seg[idx].l+seg[idx].r)/2;
    if (r <= mid) return query(l, r, idx*2);
    if (l > mid) return query(l, r, idx*2+1);
    return max(query(l, mid, idx*2), query(mid+1, r, idx*2+1));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> M; build(0, N, 1);
    for (int i=1, l, r, v;i<=M;i++) {
        cin >> l >> r >> v;
        p[r].push_back({l, v});
    } 
    for (int i=1;i<=N;i++) { 
        ll mx = query(0, i-1, 1); 
        update(i, i, mx, 1);
        for (pi e : p[i])
            update(e.first, i, e.second, 1);
    }
    cout << seg[1].v;
}