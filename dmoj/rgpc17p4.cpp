#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
struct E { int v, w; };
int N, M, vis[MM], ans, cnt[MM], d[MM];
vector<E> g[MM];
stack<int> res;
void dfs(int u) { 
    vis[u] = 1;
    for (E ed : g[u]) {
        if (!vis[ed.v]) {
            dfs(ed.v);
        } else if(vis[ed.v]==1) {
            cout << "-1\n"; exit(0);
        }
    } 
    vis[u] = 2;
    res.push(u);
} 
int main() {
    cin >> N >> M;
    for (int i=0,u,v,w;i<M;i++) {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    dfs(1);
    if (!vis[N]) { cout << "-1\n"; exit(0); }
    cnt[1] = 1;
    while (!res.empty()) {
        int u = res.top(); res.pop();
        for (E ed : g[u]) {
            if (d[u] + ed.w > d[ed.v])
                d[ed.v] = d[u] + ed.w, cnt[ed.v] = cnt[u] + 1;
            else if (d[u] + ed.w == d[ed.v] && cnt[u] + 1 > cnt[ed.v])
                d[ed.v] = d[u] + ed.w, cnt[ed.v] = cnt[u] + 1;
        }
    }
    cout << d[N] << ' ' << cnt[N] << '\n';
}