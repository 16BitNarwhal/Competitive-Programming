#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+10, INF=0x3f3f3f3f;
int N, W, D, st[MM], dist[MM];
vector<int> g[MM];
multiset<int> s; 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(dist, 0x3f, sizeof dist);
    cin >> N >> W >> D;
    for (int i=0,u,v;i<W;i++) {
        cin >> u >> v;
        g[v].push_back(u); // go backwards
    }
    queue<int> q;
    q.push(N); dist[N]=0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v:g[u]) {
            if (dist[u]+1<dist[v]) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    for (int i=1;i<=N;i++) {
        cin>>st[i]; 
        // dist[st[i]] <- distance from st[i] to N by walk
        // i-1 <- distance to st[i] from start by train
        s.insert(dist[st[i]]+i-1); 
    }
    while (D--) {
        int a, b; cin >> a >> b;
        s.erase(s.find(dist[st[a]]+a-1));
        s.erase(s.find(dist[st[b]]+b-1));
        swap(st[a], st[b]); 
        s.insert(dist[st[a]]+a-1);
        s.insert(dist[st[b]]+b-1);
        cout << *s.begin() << '\n';
    }
}