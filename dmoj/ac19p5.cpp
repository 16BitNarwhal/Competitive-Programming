#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3;
int N, mat[MM][MM], res[MM][MM], ans=0;
vector<vector<int>> adj = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void dfs(int x, int y) {
    if (res[x][y]) return;
    for (vector<int> nxt : adj) {
        int newx = x + nxt[0], newy = y + nxt[1];
        if (newx<0 || newy<0 || newx==N || newy==N) continue;
        if (mat[x][y] < mat[newx][newy]) {
            dfs(newx, newy);
            res[x][y] = max(res[x][y], res[newx][newy]+1); 
        }
    }
    ans = max(ans, res[x][y]);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0;i<N;i++) 
        for (int j=0;j<N;j++)
            cin >> mat[i][j];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++) 
            dfs(i, j);
    cout << ans << '\n';
}