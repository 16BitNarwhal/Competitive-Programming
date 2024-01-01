#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+2;
pair<int,int> a[MM];
int main() {
  int n; cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a,a+n);
  int cur=0, ans=0;
  for (int i=0;i<n;i++) {
    if (a[i].second >= cur) {
      cur = a[i].first;
      ans++;
    }
  }
  cout << ans << endl;
}