#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2; 
int calc(int num1s, int num2s) {
  return num1s/2 + num2s;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    map<int,int> cnt;
    int mn=1e9, mx=0;
    for (int i=0;i<n;i++) {
      int x;cin>>x;
      cnt[x]++;
      mn = min(mn, x);
      mx = max(mx, x);
    }
    int num2s=0, num1s=0;
    for (auto [v,c] : cnt) {
      if (c>=2) num2s++;
      else if (c==1) num1s++;
    } 
    int ans=0;
    for (auto [v,c] : cnt) {
      if (c>=2) {
      ans = max(ans, calc(num1s, num2s-1)+1);
      } else {
      ans = max(ans, calc(num1s-1, num2s)+1);
      }
    }
    cout << ans << '\n';
  }
}