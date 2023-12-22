// using top sort
#include <bits/stdc++.h>
using namespace std;
const int MM = 50;
int N, vis[MM];
vector<int> g[10];
stack<int> res;
void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
        else if(vis[v]==1) { 
            cout << "Cannot complete these tasks. Going to bed.\n";
            exit(0);
        }
    }
    vis[u] = 2; 
    res.push(u);
}
int main() {
    {
        int u[] = {1, 1, 2, 3, 3};
        int v[] = {7, 4, 1, 4, 5};
        N = 5;
        for (int i=0;i<N;i++)
            g[u[i]].push_back(v[i]);
    }
    while (1) {
        int u,v;cin>>u>>v;
        if(u==0 && v==0) break;
        N++; g[u].push_back(v);
    }
    for (int i=7;i>=1;i--) { 
        if (!vis[i]) dfs(i);
    }
    while (!res.empty()) {
        cout << res.top() << ' '; res.pop();
    }
    cout << '\n';
}