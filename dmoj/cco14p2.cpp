#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct ed { int v, l; };
int N, M, A, B, dis1[MM], dis2[MM];
vector<ed> adj1[MM], adj2[MM];
int edges[MM][4];
bool inq[MM];
void dij(int st, vector<ed> adj[MM], int (&dis)[MM]) {
    memset(dis, 0x3f, sizeof dis);
    memset(inq, 0, sizeof inq);
    queue<int> q;
    q.push(st);
    inq[st] = 1; dis[st] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); 
        inq[u] = 0;
        for (ed e : adj[u]) {
            if (dis[u] + e.l < dis[e.v]) {
                dis[e.v] = dis[u] + e.l;
                if (!inq[e.v]) {
                    q.push(e.v);
                    inq[e.v] = 1;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> A >> B;
    for (int i=0,u,v,l,c;i<M;i++) {
        cin >> u >> v >> l >> c;
        adj1[u].push_back({v,l});
        adj2[v].push_back({u,l});
        edges[i][0] = u; edges[i][1] = v;
        edges[i][2] = l; edges[i][3] = c;
    } 
    dij(A, adj1, dis1);  
    dij(B, adj2, dis2);
    vector<pair<int,int>> res(M);
    for (int i=0;i<M;i++) {
        int u = edges[i][0], v = edges[i][1], l = edges[i][2], c = edges[i][3];
        res[i] = { dis1[u] + dis2[v] + l, c };
    }
    sort(res.begin(), res.end());
    for (int i=1;i<M;i++) res[i].second += res[i-1].second;
    int Q; cin >> Q;
    while(Q--) {
        int D; cin >> D;
        int l=0, r=M-1, ans=0;
        while (l<=r) {
            int m = (l+r)/2; 
            if (res[m].first <= D) ans = res[m].second, l = m+1;
            else r = m-1;
        }
        cout << ans << '\n';
    }
}