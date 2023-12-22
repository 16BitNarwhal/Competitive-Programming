#include <bits/stdc++.h>
using namespace std;
const int MM = 101;
int N, K, memo[MM][MM];
vector<int> g[MM];
int dfs(int u, int d) {
    if (memo[u][d]) return memo[u][d];
    if (d==K) return 1;
    int ret=0;
    for (int v : g[u]) {
        ret += dfs(v, d+1);
    }
    return memo[u][d] = ret;
}
int main() {
    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        for (int j=1, x;j<=N;j++) {
            cin >> x;
            if (x) g[i].push_back(j);
        }
    } 
    int ans=0;
    for (int i=1;i<=N;i++)
        ans += dfs(i, 0);
    cout << ans;
}