#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, D, dis[MM], ans=0;
vector<int> adj[MM];
void dfs(int u) {
    deque<int> q;
    for (int v : adj[u]) {
        dfs(v);
        q.push_back(dis[v] + 1);
    }
    sort(q.begin(), q.end());
    while (q.size() >= 2 && q[0] + q[1] < D) {
        ans--; q.pop_front();
    }
    if (q.empty()) dis[u] = 0;
    else dis[u] = q[0] % D;
    if (dis[u] == 0) ans++;
}
int main() {
    cin >> N >> D;
    for (int i=1,pa;i<N;i++) {
        cin >> pa;
        adj[pa].push_back(i);
    }
    dfs(0); 
    cout << ans << '\n';
}