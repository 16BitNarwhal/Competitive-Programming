#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<int> a(n);
    for (int &i:a) cin>>i;
    bool ans = true, one = false;
    for (int i=0;i<n;i++) {
      if (a[i]==1) {
        if (one) ans = false;
        else one = true;
      }
      if (a[(i+1)%n]-a[i]>1) ans=false;
    }
    if (!one) ans = false;
    cout << (ans ? "YES" : "NO") << '\n';
  }
}