#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n,k,ar[MM];
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> ar[i];
  map<int,int> mp;
  int l=0, cnt=0;
  long long ans=0;
  for (int r=0;r<n;r++) {
    mp[ar[r]]++;
    if (mp[ar[r]]==1) cnt++; 
    while (cnt>k) {
      mp[ar[l]]--;
      if (mp[ar[l]]==0) cnt--;
      l++;
    }
    ans += r-l+1;
  }
  cout << ans << '\n';
}