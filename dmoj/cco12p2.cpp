#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+2;
struct edge { 
    int v, w;
    friend bool operator<(const edge a, const edge b) { return a.w < b.w; }
};
int N, M, dis1[MM], dis2[MM], vis[MM];
vector<edge> adj[MM]; 
queue<int> q;
void add(int u) {
    q.push(u);
    vis[u] = 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i=0,u,v,w;i<M;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w}); 
    }
    memset(dis1, 0x3f, sizeof dis1); memset(dis2, 0x3f, sizeof dis2); 
    q.push(1);
    dis1[1] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop(); 
        vis[u] = 0;
        for (edge e : adj[u]) {
            int v = e.v, w = e.w;
            if (dis1[u] + w < dis1[v]) {
                dis2[v] = dis1[v];
                dis1[v] = dis1[u] + w;
                add(v);
            } else if (dis1[u] + w < dis2[v] && dis1[u] + w != dis1[v]) {
                dis2[v] = dis1[u] + w;
                add(v);
            } else if (dis2[u] + w < dis2[v] && dis2[u] + w != dis1[v]) {
                dis2[v] = dis2[u] + w;
                add(v);
            }
        }
    }
    if (dis2[N] == 0x3f3f3f3f) cout << "-1\n";
    else cout << dis2[N] << '\n';
}