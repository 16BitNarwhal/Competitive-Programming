#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,ll> pi;
#define f first
#define s second

ll inp[100005][2];
vector<pi> ar[20005];
ll sum[100005][2];

void calc(int ax) {
  for (int i=0;i<20005;i++) {
    if (ar[i].size()==0) continue;
    sort(ar[i].begin(), ar[i].end());
    ll cur=0;
    int sz = ar[i].size();
    for (int j=0;j<sz;j++)  
      cur = (cur + (ar[i][j].f - ar[i][0].f)) % mod;
    for (int j=0;j<sz;j++) {
      if (j) cur = (cur + (2LL*j - sz) * (ar[i][j].f - ar[i][j-1].f)) % mod;
      sum[ar[i][j].s][ax] = cur;
    }
  }
}

int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> inp[i][0] >> inp[i][1];
    inp[i][0] += 1e4; inp[i][1] += 1e4;
  }
  for (int i=0;i<n;i++) 
    ar[inp[i][0]].push_back({inp[i][1], i});
  calc(0);
  for (int i=0;i<20005;i++) ar[i].clear();
  for (int i=0;i<n;i++)
    ar[inp[i][1]].push_back({inp[i][0], i});
  calc(1);
  ll ans=0;
  for (int i=0;i<n;i++) 
    ans = (ans + sum[i][0] * sum[i][1]) % mod;
  cout << ans << '\n';
}