#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
const int INF = 1e9, MM = 2002;
int n,m,b,q,dis[MM];
vector<pi> e[MM];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<MM;i++) dis[i] = INF;
    cin>>n>>m>>b>>q;
    for(int i=0,u,v,w;i<m;i++) {
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dis[b] = 0;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({b,0});
    while(!pq.empty()) {
        pi cur = pq.top(); pq.pop(); 
        for(pi ed : e[cur.F]) {
            int new_dis = cur.S + ed.S; 
            if(new_dis < dis[ed.F]) {
                dis[ed.F] = new_dis;
                pq.push({ed.F, new_dis});
            }
        }
    }
    for(int i=0,x;i<q;i++) {
        cin>>x;
        cout<<(dis[x]==INF?-1:dis[x])<<'\n';
    }
}