#include <bits/stdc++.h>
using namespace std;
int n, pa[101], sz[101];
string inp[101];
map<string, int> mp;
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    int cnt=0;
    mp.clear();
    for (int i=0;i<n;i++) {
      cin >> inp[i];
      if (mp[inp[i]]==0) {
        cnt++;
        mp[inp[i]] = cnt;
      }
    } 
    fill(pa, pa+101, -1);
    int cur = mp[inp[n-1]];
    sz[mp[inp[n-1]]] = 0;
    int mx=0;
    for (int i=0;i<n;i++) {
      int nxt = mp[inp[i]];
      if (pa[cur] != nxt) {
        pa[nxt] = cur;
        sz[nxt] = sz[cur]+1;
      }
      cur = nxt;
      mx = max(mx, sz[cur]);
    }
    cout << (n*10) - (mx*20) << '\n';
  }
}