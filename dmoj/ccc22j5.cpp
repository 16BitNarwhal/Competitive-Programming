#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pt {
  int x, y;
  bool operator<(const pt &p) const {
    return x < p.x;
  }
};
pt a[111];
int main() {
  int N, T;
  cin >> N >> T;
  for (int i=1;i<=T;i++) {
    cin >> a[i].x >> a[i].y;
  }
  a[0].x = 0;
  a[T+1].x = N+1;
  ll ans=0;
  sort(a, a+T+2);
  for (int i=0;i<=T+1;i++) {
    for (int j=i+1;j<=T+1;j++) {
      // find all trees x between a[i] and a[j]
      // sort them by y
      // go through each pair of y then maximize
      vector<int> v;
      v.push_back(0);
      for (int k=1;k<=T;k++) {
        if (a[i].x < a[k].x && a[k].x < a[j].x)
          v.push_back(a[k].y);
      }
      v.push_back(N+1);
      
      sort(v.begin(), v.end());
      ll width = a[j].x - a[i].x - 1;
      for (int k=0;k<(int)v.size()-1;k++) {
        ll height = v[k+1] - v[k] - 1;
        ll cur = min(width, height);
        ans = max(ans, cur);
      }
    }
  }
  cout << ans << '\n';
}