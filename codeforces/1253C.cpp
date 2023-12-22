#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
vector<ll> pre[MM];
int ar[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;cin>>n>>m;
  for (int i=0;i<n;i++) cin >> ar[i];
  sort(ar, ar+n);
  for (int i=0;i<n;) {
    for (int j=0;j<m;j++,i++)  
      pre[j].push_back(ar[i]);
  }
  for (int i=0;i<m;i++) {
    for (int j=1;j<pre[i].size();j++)
      pre[i][j] += pre[i][j-1];
  }
  ll ans=0;
  for (int i=0;i<n;i++) { 
    ans += pre[i%m][i/m];
    cout << ans << ' ';
  }
}