#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<ll,ll> pl;
struct edge {
    ll v, w, lv; // node v, time, level
};
ll N, M, A, B, C, dis[100001];
vector<edge> adj[200001];
priority_queue<pl, vector<pl>, greater<pl>> q;
bool dij(ll level) {
    memset(dis, 0x3f3f3f3f, sizeof dis); 
    while(!q.empty()) q.pop();
    q.push({0, A});
    dis[A] = 0;
    while (!q.empty()) {
        ll u = q.top().second, d = q.top().first; 
        q.pop();
        if (d > dis[u]) continue;
        for (auto e : adj[u]) {
            if (dis[u] + e.w < dis[e.v] && e.lv <= level) {
                dis[e.v] = dis[u] + e.w;
                q.push({dis[e.v], e.v});
            }
        }
    } 
    return dis[B] <= C;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (ll i=1,u,v,w;i<=M;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w,i});
        adj[v].push_back({u,w,i});
    }
    cin >> A >> B >> C; 
    ll l=1, r=M, ans=-1;
    while (l<=r) {
        int m = (l+r)/2;
        bool res=dij(m);
        if (res) ans=m, r=m-1;
        else l=m+1;
    } 
    cout << ans << '\n'; 
}