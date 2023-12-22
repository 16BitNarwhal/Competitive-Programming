#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int N, K, cows[MM], ans[MM];
vector<int> adj[MM];
bool vis[MM];
int main() {
    cin >> N >> K; 
    for (int i=1;i<=N;i++) {
        cows[i] = i;
        adj[i].push_back(i);
    }
    for (int i=0,a,b;i<K;i++) {
        cin >> a >> b; 
        swap(cows[a], cows[b]);
        adj[cows[a]].push_back(a);
        adj[cows[b]].push_back(b);
    }
    for (int i=1;i<=N;i++) {
        if (vis[i]) continue;
        vector<int> cycle;
        int u = i;
        while (!vis[u]) {
            cycle.push_back(u);
            vis[u] = 1;
            u = cows[u];
        }
        set<int> res;
        for (int x : cycle) 
            res.insert(adj[x].begin(), adj[x].end());
        for (int cow : cycle)
            ans[cow] = res.size();
    }
    for (int i=1;i<=N;i++) 
        cout << ans[i] << '\n';
}