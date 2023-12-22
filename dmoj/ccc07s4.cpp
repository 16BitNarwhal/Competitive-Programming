#include <bits/stdc++.h>
using namespace std;

int a[10005];
vector<int> g[10005];

int dfs(int u) {
    if(!a[u])
        for(int v:g[u])
            a[u] += dfs(v);
    return a[u];
}

int main() {
    memset(a, 0, sizeof(a));
    int n;cin>>n;
    int u,v;cin>>u>>v;
    while(u!=0 && v!=0) {
        g[u].push_back(v);
        cin>>u>>v;
    }
    a[n]=1;
    cout<<dfs(1)<<'\n';
}