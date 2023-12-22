#include <bits/stdc++.h>
using namespace std;
const int MM = 20;
int N, ans;
vector<int> g[MM];
bool vis[MM];
void dfs(int u, int start) { 
    vis[u] = 1; 
    for (int v:g[u]) {
        if (v < start) continue;
        if (v == start) ans++;
        else if (!vis[v]) dfs(v, start);
    }
    vis[u] = 0;
}
int main() {
    cin >> N; ans=0;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            int x;cin>>x;
            if(x) g[i].push_back(j);
        }
    }
    for (int i=1;i<=N;i++) {
        memset(vis, 0, sizeof vis); 
        dfs(i, i);
    }
    cout << ans;
}