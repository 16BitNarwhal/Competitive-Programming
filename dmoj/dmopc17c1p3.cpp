#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define F first
#define S second
typedef pair<int,int> pi;
typedef pair<pi, int> ppi;

vector<pi> g[100001];
pi d[100001];

int main() {
    for(int i=0;i<100001;i++) d[i] = {INF,INF};
    int n,m; cin>>n>>m;
    for(int i=0,u,v,t;i<m;i++) {
        cin>>u>>v>>t;
        g[u].push_back({v,t}); // (index, type)
        g[v].push_back({u,t});
    }
    
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq; // (danger, distance, index)
    pq.push({{0,0},1});
    d[0] = {0,0};
    while(!pq.empty()) {
        ppi cur = pq.top(); pq.pop(); 
        for(pi adj : g[cur.S]) {
            pi new_d = {cur.F.F + adj.S, cur.F.S + 1};
            if(d[adj.F].S == INF || new_d < d[adj.F]) {
                pq.push({new_d, adj.F});
                d[adj.F] = new_d;
            }
        }
    } 
    if(d[n].S==INF) cout<<"-1\n";
    else cout<<d[n].F<<' '<<d[n].S<<'\n';
} 