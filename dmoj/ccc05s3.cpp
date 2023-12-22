#include<bits/stdc++.h>
using namespace std;
struct mat {
  int n, m;
  vector<vector<int>> a; 
  mat tensor(mat o) {
    mat r;
    r.init(n * o.n, m * o.m);
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        for (int i1=0;i1<o.n;i1++) {
          for (int j1=0;j1<o.m;j1++) {
            r.a[i*o.n+i1][j*o.m+j1] = a[i][j] * o.a[i1][j1];
          }
        }
      }
    }
    return r;
  }
  void init(int n_, int m_) {
    n = n_;
    m = m_;
    a.resize(n, vector<int>(m));
  }
};
vector<mat> ar;
int main() {
  int N; cin >> N;
  ar.resize(N);
  for (int i=0;i<N;i++) {
    int n, m; cin >> n >> m; 
    ar[i].init(n, m);
    for (int j=0;j<ar[i].n;j++) {
      for (int k=0;k<ar[i].m;k++)
        cin >> ar[i].a[j][k];
    }
  }
  mat r = ar[0];
  for (int i=1;i<N;i++) {
    r = r.tensor(ar[i]);
  } 
  int ans[6];
  ans[0] = ans[2] = ans[4] = -1e9;
  ans[1] = ans[3] = ans[5] = 1e9;
  for (int i=0;i<r.n;i++) {
    int sm=0;
    for (int j=0;j<r.m;j++) {
      ans[0] = max(ans[0], r.a[i][j]);
      ans[1] = min(ans[1], r.a[i][j]);
      sm += r.a[i][j];
    }
    ans[2] = max(ans[2], sm);
    ans[3] = min(ans[3], sm);
  }
  for (int j=0;j<r.m;j++) {
    int sm=0;
    for (int i=0;i<r.n;i++) {
      sm += r.a[i][j];
    }
    ans[4] = max(ans[4], sm);
    ans[5] = min(ans[5], sm);
  }
  for (int i : ans) cout << i << '\n';
}