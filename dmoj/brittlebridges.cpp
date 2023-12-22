#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
#define f first
#define s second
const int MM = 2e5+2;
int N; ll a[MM];
bool vis[MM];
vector<pi> g[MM];
void dfs(int u) {
    vis[u] = 1;
    ll best=0;
    for (pi ed : g[u]) {
        int v = ed.f, t = ed.s;
        if (vis[v]) continue;
        dfs(v);
        if (t==1) best = max(best, a[v]);
        else a[u] += a[v];
    }
    a[u] += best;
}
int main() {
    cin >> N;
    for (int i=1;i<=N;i++) cin>>a[i];
    for (int i=1,u,v,t;i<N;i++) {
        cin >> u >> v >> t;
        g[u].push_back({v,t});
        g[v].push_back({u,t});
    }
    dfs(1);
    cout << a[1] << '\n';
}