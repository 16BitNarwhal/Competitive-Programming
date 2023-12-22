#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) cin >> ar[i];
    vector<int> v;
    for (int i=0;i<n;i++) {
      if (ar[i] != i) 
        v.push_back(ar[i]);
    }
    int ans=0;
    for (int p=0;(1<<p)<n;p++) {
      bool flag = true;
      for (int b : v) {
        if (!((1<<p)&b)) flag=false;
      }
      if (flag) ans += (1<<p);
    }
    cout << ans << '\n';
  }
}