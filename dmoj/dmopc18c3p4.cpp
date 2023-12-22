#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int N, K, ar[MM], sz[MM], dis[MM]; ll ans;
vector<pair<int,int>> adj[MM];
void szDfs(int u, int pa) {
    sz[u] = ar[u];
    for (auto e : adj[u]) {
        int v=e.first;
        if (v==pa) continue;
        szDfs(v, u);
        sz[u] += sz[v]; 
    }
}
int getCent(int u, int pa) {
    for (auto e:adj[u]) {
        int v=e.first;
        if (v==pa) continue;
        if (sz[v]>K/2) return getCent(v, u);
    }
    return u;
}
void dfs(int u, int pa) {
    ans += 1LL * ar[u] * dis[u];
    for (auto e:adj[u]) {
        int v=e.first, w=e.second;
        if (v==pa) continue;
        dis[v] = dis[u]+w;
        dfs(v,u);
    }
}
int main() {
    memset(ar, 0, sizeof ar);
    cin >> K >> N;
    for (int i=0,x;i<K;i++) {
        cin>>x;ar[x]++;
    }
    for (int i=1,u,v,w;i<N;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    szDfs(1, 0);
    int centroid = getCent(1, 0);
    dfs(centroid, 0);
    cout << ans;
}