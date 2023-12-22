#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
// sz[u] = # of nodes in u subtree (including u)
int N, sz[MM], val[MM];
vector<int> adj[MM];
// dis[u] = total distance move all nodes to u (child, down -> up)
// dpa[u] = total distance move all nodes to u (parent, up -> down)
// len[u] = total length of all paths that pass through u
ll dis[MM], dpa[MM], len[MM], ans;
// child first transition (update dis and sz)
void dfs1(int u, int pa) {
    sz[u] = 1; dis[u] = 0;
    for (int v : adj[u]) {
        if (v==pa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dis[u] += sz[v] + dis[v];
    }
}
// parent first transition (update len)
void dfs2(int u, int pa) { 
    // add # of paths subtree u (dis[u])
    // for every other node in tree (N - sz[u] + 1)
    len[u] = dis[u] * (N - sz[u] + 1);
    // add # of paths not in subtree u (dpa[u])
    // for every node in subtree (sz[u])
    len[u] += dpa[u] * sz[u];
    for (int v : adj[u]) {
        if (v==pa) continue;
        // add # of paths from v to u (dis[v] + sz[v])
        // for every other child of u (sz[u] - sz[v] - 1)
        len[u] += (sz[u] - sz[v] - 1) * (dis[v] + sz[v]);
        // # of paths from other children (dis[u] - (dis[v] + sz[v]))
        // # of paths from parent node (dpa[u])
        // every node outside v subtree (N - sz[v])
        dpa[v] = dis[u] - (dis[v] + sz[v]) + dpa[u] + (N - sz[v]);
        dfs2(v, u);
    }
}
int main() {
    cin >> N;
    for (int i=1;i<=N;i++) cin >> val[i];
    for (int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 0);
    for (int i=1;i<=N;i++) ans += val[i] * len[i];
    cout << ans << '\n'; 
} 