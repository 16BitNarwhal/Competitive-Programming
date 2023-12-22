#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int pr[MM], res[MM];
void sieve() {
  memset(pr, 1, sizeof pr);
  for (int i=2;i<MM;i++) {
    if (!pr[i]) continue;
    for (int j=2*i;j<MM;j+=i)
      pr[j] = 0;
  }
  res[1] = 1;
  for (int i=2;i<MM;i++) {
    if (!pr[i]) continue;
    res[i]++;
    if (1LL*i*i < MM) res[i*i]--;
  }
  for (int i=2;i<MM;i++) res[i] += res[i-1];
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  sieve();
  int t;cin>>t;
  while(t--) {
    int n;cin>>n;
    cout << res[n] << '\n';
  }
}