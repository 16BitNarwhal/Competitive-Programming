#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, q, ar[MM], S[MM];
ll pre[MM];
unordered_map<ll, bool> mp; 
void dac(int L, int R) { 
  mp[pre[R] - pre[L-1]] = 1;  
  int l=L, r=R, mid=-1;
  int x = (ar[l] + ar[r]) / 2;
  while (l <= r) {
    int m = (l+r)/2;
    if (ar[m] <= x) l=m+1, mid=m;
    else r=m-1;
  } 
  // cout << x << "| " << L << " " << mid << " " << R << "\n";
  if (mid==-1 || mid==R) return;
  dac(L, mid);
  dac(mid+1, R);
} 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    mp.clear();
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> ar[i];
    sort(ar+1, ar+n+1);
    for (int i=1;i<=n;i++) 
      pre[i] = ar[i] + pre[i-1];
    dac(1, n); 
    while (q--) {
      int x;cin>>x;
      if (mp[x]) cout << "Yes\n";
      else cout << "No\n"; 
    }
    // for (auto it : mp) 
    //   if (it.second) cout << it.first << ' ';
  }
}