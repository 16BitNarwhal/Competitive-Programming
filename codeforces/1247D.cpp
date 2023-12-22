#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int spf[MM];
void sieve() {
  for (int i=2;i<MM;i++) spf[i]=i;
  for (int i=2;i<MM;i++) {
    if (spf[i]==i) {
      for (int j=2*i;j<MM;j+=i)
        if (spf[j]==j) spf[j]=i; 
    }
  }
}
int cnt[MM];
int main() {
  sieve();
  int n, k;
  cin>>n>>k;
  ll ans=0;
  for (int i=0;i<n;i++) {
    int x;cin>>x;
    ll y=1,z=1;
    while (x>1) { 
      int p = spf[x], c = 0;
      while (x%p==0) {
        x /= p;
        c++;
      }
      c %= k;
      int d = (k-c)%k;
      while (c--) {
        y *= p;
        if (y>=MM) break;
      }
      while (d--) {
        z *= p;
        if (z>=MM) break;
      }
      if (y>=MM) break;
      if (z>=MM) break;
    }
    if (y>=MM) continue;
    if (z>=MM) continue;
    ans += cnt[z];
    cnt[y]++;
  }
  cout << ans << '\n';
}