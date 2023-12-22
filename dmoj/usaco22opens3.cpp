#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n;
int a[MAXN];

int combine(int a, int b) {
  if (a==0) return b;
  if (b==0) return a;
  if (a==b) return 0;
  for (int i=1;i<=3;i++) {
    if (a!=i && b!=i) return i;
  }
  return 0;
}

struct Node {
  int l, r;
  int val;
} tree[MAXN * 4];

void build(int u, int l, int r) {
  tree[u] = {l, r};
  if (l == r) {
    tree[u].val = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(u * 2, l, mid);
  build(u * 2 + 1, mid + 1, r);
  tree[u].val = combine(tree[u*2].val, tree[u*2 + 1].val);
}

int query(int u, int l, int r) {
  if (l <= tree[u].l && tree[u].r <= r) {
    return tree[u].val;
  }
  int mid = (tree[u].l + tree[u].r) / 2;
  int res = 0;
  if (l <= mid) {
    res = combine(res, query(u * 2, l, r));
  }
  if (mid < r) {
    res = combine(res, query(u * 2 + 1, l, r));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;cin>>s;
  n = s.length();
  for (int i=0;i<n;i++) {
    if (s[i]=='C') a[i+1] = 1;
    else if (s[i]=='O') a[i+1] = 2;
    else if (s[i]=='W') a[i+1] = 3;
  }
  build(1, 1, n);
  int Q;cin>>Q;
  while (Q--) {
    int l, r;
    cin>>l>>r;
    if (query(1, l, r) == 1) {
      cout << "Y";
    } else {
      cout << "N";
    }
  }
  cout << '\n';
}