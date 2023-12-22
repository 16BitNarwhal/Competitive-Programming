#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, ans=0; bool vis[MM];
vector<int> g[MM];
int main() { 
    cin >> N; 
    for (int i=0,u,v;i<N-1;i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        int dupes = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                dupes++;
                ans++;
                q.push(v);
            }
        }
        int i=20;
        for (;i>=0;i--) {
            if ((1<<i) & dupes) {
                if ((1<<i) != dupes) i++;
                break;
            }
        }
        ans += i;
    }
    cout << ans;
}