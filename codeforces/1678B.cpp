#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    int ans1=1e9, ans2=1e9;
    for (int start=0;start<=1;start++) {
      for (int i=1;i<=n;i++) {
        ar[i] = s[i-1]-'0';
      }
      ar[0] = start;
      int cnt=0, seg=0;
      for (int i=1;i<=n;i+=2) {
        if (ar[i] != ar[i+1]) {
          cnt++;
          ar[i] = ar[i+1] = ar[i-1];
        }
      }
      for (int i=1;i<n;i++) {
        if (ar[i] != ar[i+1]) seg++;
      }
      seg++;
      ans1 = cnt;
      ans2 = min(ans2, seg);
    }
    cout << ans1 << ' ' << ans2 << '\n';
  }
}