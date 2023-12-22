#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define ff first 
#define ss second
bool possible=true;
bool cmp(pi a, pi b) {
  if (a.ff == b.ff) {
    return a.ss > b.ss;
  } else if (a.ss == b.ss) {
    return a.ff > b.ff;
  }
  bool ok1 = a.ff > b.ff;
  bool ok2 = a.ss > b.ss;
  if (ok1 == ok2) {
    return ok1;
  } else {
    possible=false;
  }
  return false;
}
int main() {
  int t;cin>>t;
  while (t--) {
    possible=true;
    int n;cin>>n;
    vector<pi> a(n);
    for (int i=0;i<n;i++) cin >> a[i].ff;
    for (int i=0;i<n;i++) cin >> a[i].ss;
    vector<pi> ans;
    for (int i=0;i<n;i++) {
      for (int j=i;j<n;j++) {
        if (cmp(a[i], a[j])) {
          swap(a[i], a[j]);
          ans.push_back({i, j});
        }
        if (!possible) break;
      }
    }
    if (!possible) {
      cout << "-1\n";
    } else {
      cout << ans.size() << '\n';
      for (pi p : ans) {
        cout << p.ff+1 << " " << p.ss+1 << '\n';
      }
    }
  }
}