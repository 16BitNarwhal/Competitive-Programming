#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld EPS = 1e-9;
vector<pair<int,ld>> adj[3003];
ld dst[3003];
int cnt[3003];
bool inq[3003];
int main() { 
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v; ld w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }
  ld l=-1e7, r=1e7;
  while (r-l>EPS) {
    ld mid = (l+r)/2; 
    fill(dst, dst+n+1, 1e9);
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    bool ok = false;
    queue<int> q;
    q.push(1);
    dst[1] = 0;
    int bound=10*n; // test
    while (!q.empty()) {
      int u = q.front(); q.pop();
      inq[u] = false;
      bound--;
      if (bound<=0) {
        ok = true;
        break;
      }
      for (auto [v, w]: adj[u]) { 
        if (dst[v] > dst[u]+w-mid) {
          dst[v] = dst[u]+w-mid;
          if (!inq[v]) {
            inq[v] = true;
            q.push(v);
            cnt[v]++;
            
            if (cnt[v]>n) { 
              ok = true;
              break;
            }
          }
        }
      } 
      if (ok) break;
    }
    if (ok) r = mid;
    else l = mid;
  } 
  cout << fixed << setprecision(10) << l << endl; 
}