#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int spf[MM];
map<int,int> cnt;
void sieve() {
  for (int i=2;i<MM;i++) spf[i]=i;
  for (int i=2;i<MM;i++) {
    if (spf[i]==i) {
      for (int j=i*2;j<MM;j+=i) 
        if (spf[j]==j) spf[j]=i;
    }
  }
}
int main() {
  sieve();
  int n;cin>>n; 
  for (int i=0;i<n;i++) {
    int v;cin>>v;
    while (v > 1) {
      int p = spf[v];
      while (v%p==0) v/=p;
      cnt[p]++;
    }
  }
  int ans=1;
  for (auto it : cnt)
    ans = max(ans, it.second);
  cout << ans << '\n';
}