#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int MM = 1e5+2;
int N, M, Q, rt, pre[MM];
vector<pi> adj[MM];
ll D, R, dis[MM], ans=0; vector<ll> vec;
bool vis[MM];
void dfs(int u, int pa, ll d) {
    vis[u] = 1; pre[u] = pa; dis[u] = d;
    if (d>D) { D = d; rt = u; }
    for (auto e : adj[u]) {
        int v = e.first, w = e.second;
        if (v != pa) dfs(v, u, d+w);
    }
}
int main() {
    cin >> N >> M >> Q;
    for (int i=1,u,v,w;i<=M;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    } 
    for (int i=1;i<=N;i++) {
        if (vis[i]) continue;
        D=-1; dfs(i, 0, 0);
        D=-1; dfs(rt, 0, 0);
        if (Q==1) {
            ans += D+1;
        } else {
            R = 1e12;
            for (int u=rt;u!=0;u=pre[u])
                R = min(R, max(dis[u], D-dis[u]));
            vec.push_back(R);
        }
    }
    if (Q==1) {
        cout << ans-1 << '\n';
    } else {
        sort(vec.begin(), vec.end(), greater<ll>());
        if (vec.size()>1 && vec[0]==vec[1]) cout<<vec[0]+1 <<'\n';
        else cout<<vec[0] << '\n';
    }
}