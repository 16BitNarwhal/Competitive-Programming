#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, m, ar[MM], mint[4*MM], gcdt[4*MM], cntt[4*MM];

int gcd(int a, int b) { return (b==0?a:gcd(b, a%b)); }

// fix this
int cntfun(int a, int b) {
    if (gcdt[a]!=gcdt[b]) return max(cntt[a], cntt[b]);
    return cntt[a] + cntt[b];
}

void update(int i, int l, int r, int pos, int val) {
    if (l==r) {
        mint[i] = val;
        gcdt[i] = val;
        cntt[i] = 1;
    } else {
        int m = (l+r)/2, lchild = i*2, rchild = i*2+1;
        if (pos <= m) update(lchild, l, m, pos, val);
        else update(rchild, m+1, r, pos, val);
        mint[i] = min(mint[lchild], mint[rchild]);
        gcdt[i] = gcd(gcdt[lchild], gcdt[rchild]);
        cntt[i] = cntfun(lchild, rchild);
    }
}
// l, r : current range
// L, R : desired range
int minq(int i, int l, int r, int L, int R) {
    if (L > R) return 1e9;
    if (l==L && r==R) return mint[i];
    int m = (l+r)/2, lchild = i*2, rchild = i*2+1;
    return min(minq(lchild, l, m, L, min(m, R)), minq(rchild, m+1, r, max(L, m+1), R));
}

int gcdq(int i, int l, int r, int L, int R) {
    if (L > R) return 1e9;
    if (l==L && r==R) return gcdt[i];
    int m = (l+r)/2, lchild = i*2, rchild = i*2+1;
    return gcd(gcdq(lchild, l, m, L, min(m, R)), gcdq(rchild, m+1, r, max(L, m+1), R));
}

int cntq(int i, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (l==L && r==R) return cntt[i];
    int m = (l+r)/2, lchild = i*2, rchild = i*2+1;
    return cntfun(cntq(lchild, l, m, L, min(m, R)), cntq(rchild, m+1, r, max(L, m+1), R));
}

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> ar[i];
        update(1, 1, n, i, ar[i]);
    }
    
    while (m--) {
        char op; cin >> op;
        int a, b; cin >> a >> b;
        if (op=='C') {
            update(1, 1, n, a, b);
        } else if (op=='M') {
            cout << minq(1, 1, n, a, b) << '\n';
        } else if (op=='G') {
            cout << gcdq(1, 1, n, a, b) << '\n';
        } else {
            cout << cntq(1, 1, n, a, b) << '\n';
        }
    }
}