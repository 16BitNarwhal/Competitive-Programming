#include <bits/stdc++.h>
using namespace std;
const int MM = 15000010;
int n, spf[MM], ar[300005];
map<int, int> mp;
void sieve() {
  for (int i=1;i<MM;i++) spf[i]=i;
  for (int i=2;i<MM;i++) {
    if (spf[i]==i) {
      for (int j=i*2;j<MM;j+=i) 
        if (spf[j]==j) spf[j] = i;
    }
  }
}
int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
int main() {
  sieve();
  int n; cin >> n;
  int g;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
    if (i==0) g=ar[i];
    else g = gcd(ar[i], g);
  }
  for (int i=0;i<n;i++) { 
    int x = ar[i]/g;
    set<int> pr;
    while (x > 1) { 
      pr.insert(spf[x]);
      x /= spf[x];
    } 
    for (int p : pr) 
      mp[p]++; 
  }
  int ans=1e9;
  for (auto it : mp) 
    ans = min(ans, n - it.second);  
  cout << (ans==1e9 ? -1 : ans) << '\n';
}