#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 5e5+2;
int N, M, D, dis1[MM], dis2[MM];
vector<pi> adj1[MM], adj2[MM];
bool vis[MM];
void dij(int st, int (&dis)[MM], vector<pi> adj[MM]) {
    memset(dis, 0x3f, sizeof dis);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,st});
    dis[st] = 0;
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (d > dis[u]) continue;
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (d + w < dis[v]) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}
// spfa not working for sum reason
void spfa(int st, int (&dis)[MM], vector<pi> adj[MM]) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!vis[u]) {
                    q.push(v);
                    vis[u] = 1;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i=0,u,v,w;i<M;i++) {
        cin >> u >> v >> w;
        adj1[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }
    dij(1, dis1, adj1);
    dij(N, dis2, adj2);
    cin >> D;
    int ans = dis1[N];
    for (int i=0,u,v,w;i<D;i++) {
        cin >> u >> v >> w;
        ans = min(ans, dis1[u] + w + dis2[v]);
    }
    if (ans==0x3f3f3f3f) cout<<"-1\n";
    else cout << ans << '\n';
}