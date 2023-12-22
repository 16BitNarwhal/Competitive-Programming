#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  map<int, int> mp;
  for (int i=0;i<n;i++) {
    int x;cin>>x;
    mp[x]++;
  }
  int ans=0,cnt=0;
  for (int h=1;h<=4000;h++) {
    int len=0;
    for (int i=1;i<=h;i++) {
      int j = h-i;
      len += min(mp[i], mp[j]);
    }
    len /= 2;
    if (len > ans) {
      ans = len;
      cnt = 1;
    } else if (len == ans) {
      cnt++;
    }
  }
  cout << ans << ' ' << cnt << '\n';
}