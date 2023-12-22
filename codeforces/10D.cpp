#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, n1, n2, n3;
int a[MM], b[MM], c[MM], ar[MM], dp[MM];
int tree[MM];
void upd(int i, int x) {
  for (;i<=n;i+=i&-i) tree[i]=max(tree[i],x);
}
int qry(int i) {
  int mx=0;i--;
  for (;i>0;i-=i&-i) mx=max(mx, tree[i]);
  return mx;
}
int main() {
  cin >> n1 >> n2 >> n3;
  n = n1 + n2 + n3;
  for (int i=0;i<n1;i++) cin >> a[i];
  for (int i=0;i<n2;i++) cin >> b[i];
  for (int i=0;i<n3;i++) cin >> c[i];
  sort(a, a+n1);
  sort(b, b+n2);
  sort(c, c+n3);
  int j=0;
  for (int i=0;i<n1;i++) ar[j++]=a[i];
  for (int i=0;i<n2;i++) ar[j++]=b[i];
  for (int i=0;i<n3;i++) ar[j++]=c[i];
  int ans=0;
  for (int i=0;i<n;i++) {
    int x = qry(ar[i]);
    dp[i] = x+1;
    upd(ar[i], dp[i]); 
    ans = max(ans, dp[i]);
  } 
  cout << n-ans << '\n';
}