#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct edge { int u, v, w; };
bool cmp (edge a, edge b) { return a.w < b.w; }
int N, M, ds[MM];
pair<int,int> ar[MM]; 
int root(int u) {
    if (ds[u] != u) return ds[u]=root(ds[u]);
    return u;
}
void join(int u, int v) {
    ds[root(u)] = root(v);
}
int main() {
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        cin >> ar[i].first;
        ar[i].second = i;
        ds[i] = i;
    }
    for (int i=0,x,y;i<M;i++) {
        cin >> x >> y;
        join(x, y);
    }
    sort(ar+1, ar+N+1);
    long long ans = 0;
    deque<edge> q;
    for (int i=2;i<=N;i++) {
        int u = ar[i-1].second, v = ar[i].second, w = ar[i].first - ar[i-1].first; 
        q.push_back({u,v,w});  
    }
    sort(q.begin(), q.end(), cmp);
    while (!q.empty()) {
        edge e = q.front(); q.pop_front(); 
        if (root(e.u) != root(e.v)) {  
            join(e.u, e.v);
            ans += e.w;
        }
    }
    cout << ans << '\n';
}
