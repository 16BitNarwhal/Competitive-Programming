// #include <bits/stdc++.h>
// using namespace std;
// const int MM = 102;
// int N, d[MM], ans;
// vector<int> g[MM];
// int dfs(int start) {
//     memset(d, 0, sizeof d);
//     stack<int> q; q.push(start);
//     while (!q.empty()) {
//         int u = q.top(); q.pop();
//         for (int v:g[u]) {
//             if (d[v]==0) {
//                 q.push(v);
//                 d[v] = d[u] + 1;
//             } else {
//                 ans = d[u] + 1 - d[v];
//                 return v;
//             }
//         }
//     }
//     return 0;
// }
// void solve() { 
//     for (int i=1;i<MM;i++) g[i].clear();
//     cin >> N; int start;
//     for (int i=0,u,v;i<N;i++) {
//         cin >> u >> v;
//         if (i==0) start=u;
//         g[u].push_back(v);
//     } 
//     int u = dfs(start);
//     dfs(u);
//     cout << ans << '\n';
// }
// int main() {
//     ios::sync_with_stdio(0);cin.tie(0);
//     int t=5;
//     while(t--) solve();
// }

#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int N, d[MM], ans, vis[MM];
// vis[0]: unvisited, vis[1]: currently on path, vis[2]: finished visiting (hit dead end)
vector<int> g[MM]; 
void dfs(int u) {
    if (ans>0) return; 
    vis[u] = 1;
    for (int v : g[u]) { 
        if (vis[v]==0) { 
            d[v] = d[u] + 1; 
            dfs(v); 
        }
        else if (vis[v]==1) {
            ans = d[u] - d[v] + 1; 
            return;
        }
    }
    vis[u] = 2;
}
void solve() { 
    memset(d, 0, sizeof d); memset(vis, 0, sizeof vis);
    for (int i=1;i<MM;i++) g[i].clear();
    cin >> N; int start=0;
    for (int i=0,u,v;i<N;i++) {
        cin >> u >> v;
        if (i==0) start=u;
        g[u].push_back(v);
    }
    ans=0; dfs(start);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t=5;
    while(t--) solve();
}