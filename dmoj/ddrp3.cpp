#include <bits/stdc++.h>
using namespace std;
const int MXN=1e6+5;
vector<int> g[MXN];
int dist[MXN];

int main(){ 
    int n,m;cin>>n>>m;
    for(int i=0,u,v;i<m;i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s,t;cin>>s>>t;
    queue<int> q;
    q.push(s);
    for(int i=0;i<MXN;i++) dist[i]=MXN;
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v:g[u]) {
            if(dist[v]==MXN) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    cout<<m - dist[t]<<'\n';
}