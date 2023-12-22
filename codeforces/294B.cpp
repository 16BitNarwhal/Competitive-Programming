#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  vector<int> v1, v2;
  for (int i=0;i<n;i++) {
    int t,w;cin>>t>>w;
    if (t==1) v1.push_back(w);
    else v2.push_back(w);
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  int ans=1e9;
  for (int a=0;a<=v1.size();a++) {
    for (int b=0;b<=v2.size();b++) {
      int x = a + 2*b, y = 0;
      for (int i=0;i<v1.size()-a;i++) y += v1[i];
      for (int i=0;i<v2.size()-b;i++) y += v2[i];
      if (y <= x) ans = min(ans, x);
    }
  }
  cout << ans << '\n';
}