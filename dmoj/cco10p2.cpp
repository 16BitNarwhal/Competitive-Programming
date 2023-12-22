#include <bits/stdc++.h>
using namespace std;
const int MM = 303; 
// dp[node u][i white][j black] : minimum # prunes
int N, D, col[MM], dp[MM][MM][MM];
vector<int> adj[MM];
void dfs(int u, int pa) {
    dp[u][0][0] = 1;
    bool w = col[u], b = !col[u];
    dp[u][w][b] = 1;
    for (int v : adj[u]) {
        if (v==pa) continue;
        dfs(v, u);
        bool wh = col[v], bl = !col[v];
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                // inherit from child
                dp[u][i][j] = min(dp[u][i][j], dp[v][i][j]);
                // join
                // dp[u][i+wh][j+bl] = min(dp[u][i+wh][j+bl], dp[u][i][j]+1);
                // if (dp[u][i+wh][j+bl] < MM)
                // cout << u << ' ' << i + wh << ' ' << j + bl << '\n';
            }
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            dp[u][i+w][j+b] = min(dp[u][i+w][j+b], dp[u][i][j]+1);
            if (dp[u][i+w][j+b]==adj[u].size()+1) dp[u][i+w][j+b]=1;
        }
    }
}
int main() {
    memset(dp, 0x3f, sizeof dp);
    cin >> N >> D;
    for (int i=0, u, c;i<N;i++) {
        cin >> u;
        cin >> col[u] >> c;
        for (int j=0,v;j<c;j++) {
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    dfs(1,0);
    for (int i=1;i<=N;i++) {
        cout << i << " | ";
        for (int j=1;j<=N;j++) {
            cout << dp[1][i][j] << ' ';
        } cout << '\n';
    }
}

/*
dp[node u][i white][j black]
        1W
       /   \
      2B     5W
     /  \   / | \
    3W  4W 6W 7W 8B

all dp carry to oarent

dp[u][0][0] = 1

dp[3][1][0] = 1

dp[4][1][0] = 1
dp[2][2][0] = 2 (added to dp[2][1][0])

dp[2][1][0] = 1 (because dp[3][1][0] = 1 or dp[4][1][0] = 1)
dp[2][2][0] = 1 (because dp[4][2][0] = 2 and children = 2)

dp[6][1][0] = 1

dp[7][1][0] = 1
dp[5][2][0] = 2 (added to dp[5][1][0])

dp[8][0][1] = 1
dp[5][1][1] = 2 (added to dp[5][1][0])
dp[5][2][1] = 3 (added to dp[5][2][0])

dp[5][1][0] = 1 (because dp[6][1][0] = 1 or dp[7][1][0] = 1)
dp[5][2][0] = 2 (because dp[7][2][0] = 2)
dp[5][1][1] = 2 (because dp[8][1][1] = 1)
dp[5][2][1] = 1 (because dp[8][2][1] = 3 and children = 3)


*/