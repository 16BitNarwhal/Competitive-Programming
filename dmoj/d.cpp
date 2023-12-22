#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MM = 2023;
struct edge {
  ll u, v, l, c;
  bool operator<(const edge &o) const {
    return c < o.c;
  }
};
ll n, m;
vector<edge> adj[MM];
vector<edge> edges;
ll dsu[MM];
ll root(ll x) {
  return dsu[x] == x ? x : dsu[x] = root(dsu[x]);
}
bool join(ll a, ll b) {
  a = root(a), b = root(b);
  if (a == b) return false;
  dsu[a] = b;
  return true;
}
ll dst[MM][MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // minimum spanning tree with kruskal with cost and length (max length) ?
  cin >> n >> m;
  for (ll i=0;i<m;i++) {
    ll u, v, l, c; cin >> u >> v >> l >> c;
    adj[u].push_back({u, v, l, c});
    adj[v].push_back({v, u, l, c});
    edges.push_back({u, v, l, c});
  }

  for (ll i=1;i<=n;i++) {
    for (ll j=1;j<=n;j++) {
      dst[i][j] = 1e18;
    }
  }
  for (ll i=1;i<=n;i++) {
    for (edge e : adj[i]) {
      dst[i][e.v] = min(dst[i][e.v], e.l);
    }
  }
  for (ll source=1;source<=n;source++) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
      ll d = pq.top().first, u = pq.top().second;
      pq.pop();
      if (d > dst[source][u]) continue;
      for (edge e : adj[u]) {
        if (d + e.l < dst[source][e.v]) {
          dst[source][e.v] = d + e.l;
          pq.push({dst[source][e.v], e.v});
        }
      }
    }
  }

  for (ll i=1;i<=n;i++) dsu[i] = i;
  ll ans = 0;
  vector<edge> mst;
  sort(edges.begin(), edges.end());
  for (edge e : edges) {
    if (join(e.u, e.v)) {
      ans += e.c;
      mst.push_back(e);
    }
  }
  cout << ans << '\n';

}

/*
5 7
1 2 15 1
2 4 9 9
5 2 5 6
4 5 4 4
4 3 3 7
1 3 2 7
1 4 2 1
*/