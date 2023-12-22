#include <bits/stdc++.h>
using namespace std;
int n, m;
map<int, vector<int>> X, Y;
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    int x, y; cin >> x >> y;
    X[x].push_back(y);
    Y[y].push_back(x);
  }
  for (auto &i : X) 
    sort(i.second.begin(), i.second.end());
  for (auto &i : Y) 
    sort(i.second.begin(), i.second.end());
  cin >> m;
  int px, py;
  cin >> px >> py;
  long long sum=0;
  for (int i=1;i<m;i++) {
    int x,y;cin>>x>>y;
    if (px == x) {
      int mn = min(py, y);
      int mx = max(py, y);
      sum += upper_bound(X[x].begin(), X[x].end(), mx) - lower_bound(X[x].begin(), X[x].end(), mn);
    } else {
      int mn = min(px, x);
      int mx = max(px, x);
      sum += upper_bound(Y[y].begin(), Y[y].end(), mx) - lower_bound(Y[y].begin(), Y[y].end(), mn);
    }
    px = x;
    py = y;
  }
  cout << sum << '\n';
}