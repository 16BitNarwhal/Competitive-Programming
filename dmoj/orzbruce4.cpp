#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, m = 1e9+7;
int N, M, K, dist[MM];
vector<int> g[MM];
bool vis[MM];
void bfs(int i) {
    memset(vis, 0, sizeof vis);
    queue<pair<int,int>> q;
    q.push({i,0}); vis[i]=1;
    while (!q.empty()) {
        int u = q.front().first, d = q.front().second;
        q.pop();
        if (d>K) break; 
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = max(dist[v], d+1);
                q.push({v,d+1});
            }
        }
    }
}
ll fastpow(ll a, ll e) { return (e==0)?1:((e&1?a:1)*fastpow((a*a)%m,e/2)%m); }
int main() { 
    cin >> N >> M >> K;
    for (int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    bfs(1); bfs(N);
    int cnt=0;
    for (int i=2;i<N;i++) {
        if (dist[i]>0 && dist[i]<=K) cnt++; 
    }
    cout << fastpow(2,cnt);
}