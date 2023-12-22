#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e4+5;
int N, len[MM], dia;
ll cnt[MM], ans;
vector<int> adj[MM];
void dfs(int u, int pa) {
    len[u] = 0; cnt[u] = 1;
    for (int v : adj[u]) {
        if (v==pa) continue;
        dfs(v, u);
        if (len[v] + 1 + len[u] > dia) {
            dia = len[v] + 1 + len[u];
            ans = cnt[v] * cnt[u];
        } else if (len[v] + 1 + len[u] == dia) {
            ans += cnt[v] * cnt[u];
        }
        if (len[v] + 1 > len[u]) {
            len[u] = len[v] + 1;
            cnt[u] = cnt[v];
        } else if (len[v] + 1 == len[u]) {
            cnt[u] += cnt[v];
        }
    }
}
int main() {
    cin >> N;
    for (int i=1,x,y; i<N;i++) {
        cin >> x >> y; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << '\n';
}