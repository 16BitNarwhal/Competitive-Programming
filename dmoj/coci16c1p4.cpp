 
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
typedef long long ll;
struct frac {
    ll x, y;
    frac(ll x0, ll y0) { x=x0/__gcd(x0,y0); y=y0/__gcd(x0,y0); }
    bool operator<(const frac &a) const { return x*a.y < y*a.x; }
};
int N, ar[MM], len[MM], mx[MM], mx2[MM], ch[MM];
vector<int> adj[MM];
frac ans(1e18, 1);
void dfs1(int u, int pa) {
    len[u] = (ar[u]==1);
    for (int v : adj[u]) {
        if (v==pa) continue;
        dfs1(v, u);
        if (len[v] > mx[u]) {
            mx2[u] = mx[u];
            mx[u] = len[v];
            ch[u] = v;
        } else if (len[v] > mx2[u]) {
            mx2[u] = len[v];
        }
        if (ar[u]==1) {
            len[u] = max(len[u], len[v]+1);
        }
    }
}
void dfs2(int u, int pa, int up) {
    ans = min(ans, frac{ar[u], mx[u] + mx2[u] + 1});
    ans = min(ans, frac{ar[u], mx[u] + up + 1});
    for (int v : adj[u]) {
        if (v==pa) continue;
        int tmp = 0;
        if (ar[u]==1) {
            if (v==ch[u]) tmp = max(up, mx2[u]) + 1;
            else tmp = max(up, mx[u]) + 1;
        }
        dfs2(v, u, tmp);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=1,u,v;i<N;i++) {
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i=1;i<=N;i++) { 
        cin >> ar[i]; ans = min(ans, frac{ar[i], 1});
    } 
    dfs1(1, 0); dfs2(1, 0, 0);
    cout << ans.x << '/' << ans.y << '\n';
}