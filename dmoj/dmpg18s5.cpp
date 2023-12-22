#include <bits/stdc++.h>

using namespace std;

map<int,int> fenwick[200010];

void update(int idx, int val, int x) {
  for (; idx < 200010; idx += idx & -idx) {
    fenwick[idx][x] += val;
  }
}

int qry(int idx, int x) {
  int res = 0;
  for (; idx > 0; idx -= idx & -idx) {
    res += fenwick[idx][x];
  }
  return res;
}

vector<int> get_factors(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      res.push_back(i);
      if (i * i != x) {
        res.push_back(x / i);
      }
    }
  }
  return res;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    // get factors of a[i]
    vector<int> factors = get_factors(a[i]);
    for (int f : factors)
      update(i+1, 1, f);
  }
  while (q--) {
    int op; cin >> op;
    if (op==1) {
      int l, r, x;
      cin >> l >> r >> x;
      cout << qry(r, x) - qry(l-1, x) << '\n';
    } else {
      int idx, val;
      cin >> idx >> val;
      // remove old a[i]
      vector<int> factors = get_factors(a[idx]);
      for (int f : factors)
        update(idx, -1, f);

      // add new
      a[idx] = val;
      factors = get_factors(val);
      for (int f : factors)
        update(idx, 1, f);
    }
  }  
}