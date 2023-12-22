#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int N, adj[MM], dst[MM]; ll K;
bool vis[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i=1,x;i<=N;i++) {
    cin >> x;
    adj[i] = x;
  }
  memset(vis, 0, sizeof vis);
  memset(dst, 0, sizeof dst);
  int u=1, d=0, st=0, cycle=0; 
  while (1) {
    if (vis[u]) {
      st = u;
      cycle = d - dst[st];
      break;
    }
    vis[u] = 1;
    dst[u] = d;
    d++;
    u = adj[u];
  }
  if (K - dst[st] < 0) { 
    u=1;
    while (K--) u = adj[u];
    cout << u << '\n';
    return 0;
  }
  K -= dst[st];
  K %= cycle;
  u=st;
  while (K--) u = adj[u];
  cout << u << '\n';
}