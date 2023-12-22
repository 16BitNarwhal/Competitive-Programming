#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n;
ll ar[MM], st[60][MM];
void build() {
  for (int i=0;i<n;i++) st[0][i] = ar[i];
  for (int i=1;(1<<i)<=n;i++) {
    for (int j=0;j+(1<<(i-1))<n;j++) {
      st[i][j] = gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    }
  }
}
ll get(int l, int r) {
  int k = log2(r-l+1);
  return gcd(st[k][l], st[k][r-(1<<k)+1]);
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>n;
    for (int i=0;i<n;i++) cin >> ar[i];
    n--;
    for (int i=0;i<n;i++) ar[i] = abs(ar[i+1] - ar[i]);
    build();
    int l=0, ans=0;
    for (int r=0;r<n;r++) {
      while (l<=r && get(l, r)==1) l++;
      ans = max(ans, r-l+1); 
    }
    ans++;
    cout << ans << '\n';
  }
}