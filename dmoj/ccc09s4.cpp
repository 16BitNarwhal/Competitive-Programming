#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
struct edge { int v, w; };
int N, T, K, D, dis[MM];
vector<edge> adj[MM];
bool vis[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    for (int i=1;i<=N;i++) dis[i] = 1e9;
    for (int i=0,u,v,w;i<T;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> K;
    for (int i=0,u,c;i<K;i++) {
        cin >> u >> c;
        dis[u] = c;
    }
    for (int i=0;i<N;i++) {
        int u = 1;
        for (int j=1;j<=N;j++) {
            if (!vis[j] && dis[j] < dis[u])
                u = j;
        }
        if (vis[u]) break;
        vis[u] = 1;
        for (auto e : adj[u])
            dis[e.v] = min(dis[e.v], dis[u] + e.w); 
    }
    cin >> D; 
    cout << dis[D] << '\n';
}