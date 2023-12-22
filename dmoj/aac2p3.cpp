#include <bits/stdc++.h>
using namespace std;
const int MM = 1502;
int N, M, X, grid[MM][MM], psa[MM][MM];
bool vis[MM][MM];
bool check(int x, int y) {
    x--; y--;
    int x2 = min(x+X, N-1), y2 = min(y+X, M-1);
    int sum = psa[x2][y2];
    if (x>=0) sum -= psa[x][y2];
    if (y>=0) sum -= psa[x2][y];
    if (x>=0 && y>=0) sum += psa[x][y]; 
    return sum==X*X;
}
bool fun(int n) {
    X = n;
    memset(vis, 0, sizeof vis);
    queue<pair<int,int>> q;
    int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    if (check(0,0)) { q.push({0,0}); vis[0][0] = 1; }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; 
        q.pop();
        if (x==N && y==M) return 1;
        for (int k=0;k<4;k++) {
            int nx = x+d[k][0], ny = y+d[k][1];
            if (nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if (!vis[nx][ny] && check(nx, ny)) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            } 
        }
    }
    return vis[N-X][M-X];
}
int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            char c;cin>>c;
            grid[i][j] = (c=='O');
            psa[i][j] = grid[i][j];
            if (i) psa[i][j] += psa[i-1][j];
            if (j) psa[i][j] += psa[i][j-1];
            if (i&&j) psa[i][j] -= psa[i-1][j-1];
        }
    }   
    int l=0, r=min(N, M), ans=0;
    while (l<=r) {
        int m = (l+r)/2;
        if (fun(m)) { ans=m; l = m+1; }
        else r = m-1;
    }
    cout << ans;
}