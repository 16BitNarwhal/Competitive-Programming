#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  for (int &i:a) cin>>i;
  int ans=0;
  int l,r;
  cin >> l >> r;
  for (int i=l;i<=r;i++) ans += a[i];
  cout << ans << '\n';
}