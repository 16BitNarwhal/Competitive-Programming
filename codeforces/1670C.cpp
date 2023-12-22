#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const int MM = 2e5+2, mod = 1e9+7;
ll qpow(ll a, ll b) { return b==0?1:(b&1?a:1ll)*qpow(a*a%mod, b>>1)%mod; }
int a[MM], b[MM], c[MM];
int dsu[MM], has[MM];
int root(int u) {
  if (dsu[u] == u) return u;
  return dsu[u] = root(dsu[u]);
}
void join(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return;
  dsu[a] = b;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=1;i<=n;i++) dsu[i] = i;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    for (int i=0;i<n;i++) join(a[i], b[i]);

    for (int i=0;i<n;i++) cin >> c[i];
    
    for (int i=1;i<=n;i++) has[i] = 0;  
    for (int i=0;i<n;i++) {
      if (a[i]==b[i]) {
        has[a[i]] = 1;
      } else if (c[i] != 0) {
        has[root(a[i])] = 1;
      }
    }
    set<int> s;
    for (int i=0;i<n;i++) {
      if (!has[root(a[i])]) s.insert(root(a[i]));
    }
    int cnt= s.size();
    cout << qpow(2, cnt) << '\n';
  }
}