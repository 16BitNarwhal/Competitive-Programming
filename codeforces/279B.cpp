#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int ar[MM];
int main() {
  int n,t;cin>>n>>t;
  for (int i=0;i<n;i++) cin>>ar[i];
  int l=0,r=0,cur=0,ans=0;
  while (r<n) {
    if (cur+ar[r]<=t) {
      cur += ar[r];
      r++;
    } else {
      cur -= ar[l];
      l++;
    }
    ans = max(ans,r-l);
  }
  cout << ans << '\n';
}