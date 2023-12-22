// // kruskal
// #include <bits/stdc++.h>
// using namespace std;
// const int MM = 1e5+2;
// int n, m, ds[MM]; vector<int> res;
// int root(int u) { return ds[u]==u?u:(ds[u]=root(ds[u])); }
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     cin >> n >> m;
//     for (int i=1; i<=n; i++) ds[i]=i;
//     for (int i=1, u, v; i<=m; i++) { // i is weight
//         cin >> u >> v;
//         int ru = root(u), rv = root(v);
//         if (ru!=rv) {
//             res.push_back(i);
//             ds[ru] = rv;
//             n--;
//         }
//     }
//     if (n<=1) for(int x:res) cout<<x<<'\n';
//     else cout << "Disconnected Graph\n";
// }

// prim
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi> adj[100010];
int dst[100010];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1,u,v;i<=m;i++) {
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    set<int> ans;
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dst[u]) continue;
        if (d) ans.insert(d);
        for (auto [v,w] : adj[u]) {
            if (dst[v] > w) {
                dst[v] = w;
                pq.push({dst[v], v});
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (dst[i]==0x3f3f3f3f) {
            cout << "Disconnected Graph\n";
            return 0;
        }
    }
    for (int i:ans) cout << i << '\n';
}