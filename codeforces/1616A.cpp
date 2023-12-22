#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    map<int,int> cnt;
    for (int i=0;i<n;i++) {
      int x;cin>>x;
      cnt[x]++;
    }
    int ans = (cnt[0]>0);
    for (int i=1;i<=100;i++) {
      if (cnt[i]>0 && cnt[-i]>0) {
        ans+=2;
      } else if (cnt[i]>1) {
        ans+=2;
      } else if (cnt[-i]>1) {
        ans+=2;
      } else if (cnt[i]>0 || cnt[-i]>0) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}