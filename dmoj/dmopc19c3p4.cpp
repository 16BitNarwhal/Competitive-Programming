// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int MM = 3e5+2, mod = 1e9+7;
// int N, parent[MM];
// // dp[u] -> # ways including node u where u is root (not necessarily a leaf)
// ll dp[MM];
// vector<int> adj[MM];
// bool col[MM];
// void dfs(int u, int pa) {
//     dp[u] = 0; parent[u] = pa;
//     for (int v : adj[u]) {
//         if (v == pa) continue;
//         dfs(v, u);
//         // dp[v] -> # ways children with parent leaf
//         // dp[u] * dp[v] -> # ways children with other children leaf in subtree
//         dp[u] = (dp[u] + dp[v] + (dp[u] * dp[v]) % mod) % mod;
//     }
//     dp[u] += col[u];
// }
// ll summ() {
//     ll ret = 0;
//     for (int u=1;u<=N;u++) {
//         ret = (ret + dp[u]) % mod;
//         if (!col[u]) {
//             for (int v : adj[u]) {
//                 if (v == parent[u]) continue;
//                 // parent can't be leaf
//                 // so remove instances where child with parent leaf
//                 ret = (ret - dp[v] + mod) % mod;
//             }
//         }
//     }
//     return ret;
// }
// int main() {
//     cin >> N;
//     for (int i=1;i<=N;i++) {
//         char c;cin>>c;
//         col[i] = (c=='R');
//     }
//     for (int i=1,u,v;i<N;i++) {
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // solve for R's
//     dfs(1, 0);
//     ll ans = summ();
//     // swap colours to solve for B's
//     for (int i=1;i<=N;i++) 
//         col[i] = !col[i];
//     dfs(1, 0);
//     ans = (ans + summ()) % mod;
//     cout << ans << '\n';
// }

// olympads sol
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+2, mod = 1e9+7;
int N; bool col[MM];
ll dp[MM], ans=0;
vector<int> adj[MM];
ll dfs(int u, int pa) {
    ll sum = 0, join = 0;
    for (int v : adj[u]) {
        if (v==pa) continue;
        dfs(v, u);
        join = (join + (sum + join) * dp[v]) % mod;
        sum = (sum + dp[v]) % mod;
    }
    if (col[u]) {
        dp[u] = (1 + sum + join) % mod;
        ans = (ans + dp[u]) % mod;
    } else {
        ans = (ans + join) % mod;
        dp[u] = (sum + join) % mod;
    }
}
int main() {
    cin >> N;
    for (int i=1;i<=N;i++) {
        char c;cin>>c;
        col[i] = (c=='B');
    }
    for (int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i=1;i<=N;i++) col[i] ^= 1;
    dfs(1, 0);
    cout << ans << '\n';
}