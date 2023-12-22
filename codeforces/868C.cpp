#include <bits/stdc++.h>
using namespace std;
int n, k, cnt[20];
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    int s=0;
    for (int j=0;j<k;j++) {
      int x; cin >> x;
      s = 2*s + x;
    }
    cnt[s]++;
  }
  for (int i=0;i<(1<<k);i++) {
    for (int j=0;j<(1<<k);j++) {
      if (cnt[i]>0 && cnt[j]>0 && ((i&j)==0)) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}