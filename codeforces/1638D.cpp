#include <bits/stdc++.h>
using namespace std;
const int MM = 1001;
struct op {
  int i, j, c;
};
vector<op> res;
int n, m, a[MM][MM];
int get(int i, int j) {
  int x = max(a[i][j], a[i+1][j]);
  x = max(x, a[i][j+1]);
  x = max(x, a[i+1][j+1]);
  return x;
}
bool check(int i, int j) {
  int x = get(i, j);
  if (x==0) return false;
  if (a[i][j]!=0 && a[i][j]!=x) return false;
  if (a[i+1][j]!=0 && a[i+1][j]!=x) return false;
  if (a[i][j+1]!=0 && a[i][j+1]!=x) return false;
  if (a[i+1][j+1]!=0 && a[i+1][j+1]!=x) return false;
  return true;
}
void fun(int i, int j) {
  if (!check(i, j)) return;
  int x = get(i, j);
  res.push_back({i+1, j+1, x});
  a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = 0;
  if (i>0) fun(i-1, j);
  if (j>0) fun(i, j-1);
  if (i<n-2) fun(i+1, j);
  if (j<m-2) fun(i, j+1);
}
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) 
      cin >> a[i][j];
  }
  for (int i=0;i<n-1;i++) {
    for (int j=0;j<m-1;j++) {
      fun(i, j); 
    }
  }
  bool ans=true;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (a[i][j] != 0) {
        ans = false;
        break;
      }
    }
  }
  if (!ans) {
    cout << "-1\n";
    return 0;
  }
  reverse(res.begin(), res.end());
  cout << res.size() << '\n';
  for (op x : res) {
    cout << x.i << " " << x.j << " " << x.c << '\n';
  }
}