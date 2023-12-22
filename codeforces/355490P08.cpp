#include<bits/stdc++.h>
using namespace std; 
int main() {
  int n, L, a;
  cin >> n >> L >> a;
  vector<pair<int,int>> v;
  v.push_back({0, 0});
  for (int i=0;i<n;i++) {
    int l, r;
    cin >> l >> r;
    r += l;
    v.push_back({l, r});
  }
  v.push_back({L, L});
  sort(v.begin(), v.end());
  int ans=0;
  for (int i=1;i<v.size();i++) {
    ans += (v[i].first - v[i-1].second) / a;
  }
  cout << ans << '\n';
}