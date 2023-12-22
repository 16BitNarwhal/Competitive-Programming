#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

struct ed {
    int v, w;
    bool operator<(const ed o) const {
        return w > o.w;
    }
};

int dis[1001];
vector<ed> g[1001];
bool inQ[1001];

int main() {
    for(int i=0;i<1001;i++) dis[i] = INF;
    int n,m;cin>>n>>m;
    for(int i=0,u,v,w;i<m;i++) {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    // Dijkstra's
    priority_queue<ed> pq;
    pq.push({1,0});
    dis[1] = 0;
    while(!pq.empty()) {
        ed cur = pq.top(); pq.pop();
        
        for(ed x : g[cur.v]) {
            int new_dis = dis[cur.v] + x.w;
            if(new_dis < dis[x.v]) {
                dis[x.v] = new_dis;
                pq.push({x.v, new_dis});
            }
        }
    }

    for(int i=1;i<=n;i++) 
        cout<<(dis[i]==INF ? -1 : dis[i]) <<'\n';
    

}