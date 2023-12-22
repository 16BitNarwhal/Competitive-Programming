#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, k, a[MM], cnt[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n >> k;
    fill(cnt, cnt+n+1, 0);
    for (int i=0;i<n;i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    int l=1, x=1, y=n;
    int sum = -n;
    for (int r=1;r<=n;r++) {
      sum += 2*cnt[r];
      while (l<=r && sum>=k) {
        if (r-l < y-x) {
          x=l;
          y=r;
        }
        sum -= 2*cnt[l];
        l++;
      }
    }
    vector<int> L, R;
    sum = 0;
    L.push_back(1);
    for (int i=0;i<n;i++) {
      if (a[i]>=x && a[i]<=y) sum++;
      else sum--;
      if (sum>=1 && R.size()+1 < k) {
        R.push_back(i+1);
        L.push_back(i+2);
        sum--;
      }
    }
    R.push_back(n);
    assert(sum >= 1);
    cout << x << ' ' << y << '\n';
    for (int i=0;i<L.size();i++) cout << L[i] << ' ' << R[i] << '\n';
  }
}