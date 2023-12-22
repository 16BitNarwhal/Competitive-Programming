#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;

// bit - binary index tree for array sum
// cnt - binary index tree for count (cnt[n] = # of val in array <= n)
ll n, m, a[MM], bit[MM], cnt[MM];

void update(ll ar[], int pos, int x) { 
    for (int i=pos; i<=MM; i+=i&-i) ar[i] += x;
}

ll query(ll ar[], int pos) {
    ll res = 0;
    for (int i=pos; i>0; i-=i&-i) res+=ar[i];
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        update(bit, i, a[i]);
        update(cnt, a[i], 1);
    }

    while(m--) {
        char op; cin >> op;
        if (op=='C') {
            int x, v; cin >> x >> v;
            update(bit, x, -a[x]);
            update(cnt, a[x], -1);
            update(bit, x, v);
            update(cnt, v, 1);
            a[x] = v;
        } else if (op=='Q') {
            int v; cin >> v;
            cout << query(cnt, v) << '\n';
        } else {
            int l, r; cin >> l >> r;
            cout << query(bit, r) - query(bit, l-1) << '\n';
        }
    }
}