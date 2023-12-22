#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll X, d;
  cin >> X >> d;
  ll cur=1;
  vector<ll> ans;
  for (int i=0;i<31;i++) {
    if ((X>>i)&1) {
      for (int j=0;j<i;j++) {
        ans.push_back(cur);
      }
      cur += d;
      ans.push_back(cur);
      cur += d;
    }
  }
  cout << ans.size() << '\n';
  for (ll i:ans)cout<<i<< ' ';
}