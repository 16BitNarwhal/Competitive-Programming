#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    for (int i=0;i<k-1;i++) {
      int x;cin>>x;
      a.push_back(x);
    }
    int h; cin >> h;
    for (int i=k;i<n;i++) {
      int x;cin>>x;
      b.push_back(x);
    }
    if (a.empty() || b.empty()) {
      cout << "YES" << endl;
      continue;
    }
    reverse(a.begin(), a.end());
    int l=-1;
    for (int i=0;i<a.size();i++) {
      if (i) a[i] += a[i-1];
      if (a[i]>=0) {
        if (l==-1) l=i;
        else if (a[i] >= a[l]) l=i;
      }
    }
    int r=-1;
    for (int i=0;i<b.size();i++) {
      if (i) b[i] += b[i-1];
      if (b[i]>=0) {
        if (r==-1) r=i;
        else if (b[i] >= b[r]) r=i;
      }
    }
    h += max(a[a.size()-1]+b[r], b[b.size()-1]+a[r]);
    if (h < 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}