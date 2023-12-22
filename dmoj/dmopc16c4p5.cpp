#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct edge { int v, w; };
int N, M, dis[MM]; bool vis[MM];
vector<edge> adj[MM];
int main() {
    cin >> N >> M;
    for (int i=0, u, v, w;i<M;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    } 
    priority_queue<pair<int,int>> q;
    q.push({1e9,1}); dis[1] = 1e9; 
    while (!q.empty()) {
        int u = q.top().second, d = q.top().first; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        dis[u] = d;
        for (edge e : adj[u])
            q.push({min(dis[u], e.w), e.v});
    }
    dis[1] = 0;
    for (int i=1;i<=N;i++) {
        cout<<dis[i] << '\n';
    }
}