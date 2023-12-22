#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
struct edge {
    int v, t, h;
};
vector<edge> adj[2005];
int dst[2005][205];
bool inq[2005];
int K, V, E;
int main() {
    cin >> K >> V >> E;
    for (int i=0;i<E;i++) {
        int u, v, t, h;
        cin >> u >> v >> t >> h;
        adj[u].push_back({v, t, h});
        adj[v].push_back({u, t, h});
    }
    int A, B;
    cin >> A >> B;
    memset(dst, 0x3f, sizeof(dst));
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[A][0] = 0;
    pq.push({0, A});
    while (!pq.empty()) {
        int u = pq.top().second;
        inq[u] = false;
        pq.pop();
        for (auto e : adj[u]) {
            for (int i=0;i<K-e.h;i++) {
                if (dst[e.v][i+e.h] > dst[u][i] + e.t) {
                    dst[e.v][i+e.h] = dst[u][i] + e.t;
                    if (!inq[e.v]) {
                        inq[e.v] = true;
                        pq.push({dst[e.v][i+e.h], e.v});
                    }
                } 
            }
        }
    }
    int ans=0x3f3f3f3f;
    for (int i=0;i<K;i++) {
        ans = min(ans, dst[B][i]);
    }
    if (ans == 0x3f3f3f3f) cout << -1 << endl;
    else cout << ans << endl; 
}