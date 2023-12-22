#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5;
int ar[MM];
int main() {
  int t;cin>>t;
  while(t--) {
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++) {
      cin >> ar[i];
      for (int k=2;k*k<=ar[i];k++) {
        while (ar[i] % (k*k)==0) 
          ar[i] /= k*k;
      }
    }
    set<int> s;
    int ans=1;
    for (int i=0;i<n;i++) {
      if (s.count(ar[i])) {
        s.clear();
        ans++;
      }
      s.insert(ar[i]);
    }
    cout << ans << '\n';
  }
  
}