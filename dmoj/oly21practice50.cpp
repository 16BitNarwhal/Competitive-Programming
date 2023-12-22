#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int ar[MM], cnt[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
    cnt[ar[i]]++;
  }
  for (int i=0;i<n;i++) {
    int ans=0;
    for (int j=1;j*j<=ar[i];j++) {
      if (ar[i]%j==0) {
        ans += cnt[j];
        if (j*j!=ar[i]) ans += cnt[ar[i]/j];
      }
    }
    ans--;
    cout << ans << '\n';
  }
}