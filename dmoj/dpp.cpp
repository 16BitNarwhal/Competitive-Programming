#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5, mod = 1e9+7;
// dp[x][0]: painted white
// dp[x][1]: painted black
int N; ll dp[MM][2];
vector<int> adj[MM];
ll mmul(ll a, ll b) { return a * b % mod; }
void dfs(int u, int pa) {
    dp[u][0] = 1;
    dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        // doesn't matter whether v is white or black
        dp[u][0] = mmul(dp[u][0], dp[v][0] + dp[v][1]);
        // only take from white 
        dp[u][1] = mmul(dp[u][1], dp[v][0]);
    }
}
int main() {
    cin >> N;
    for (int i=1,x,y;i<N;i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % mod << '\n';
}