#include <bits/stdc++.h>
using namespace std;
const int MM = 30;
bool g[MM][MM], vis[MM][MM];
int N, M, val, ar[MM*MM], rooms;
int dfs(int x, int y) {
    if (!g[x][y] || vis[x][y]) return 0;
    vis[x][y] = 1;
    return dfs(x+1,y) + dfs(x-1,y) + dfs(x,y+1) + dfs(x,y-1) + 1;
}

int main() {
    cin >> val >> N >> M;
    for (int i=1;i<=N;i++) {
        string inp; cin >> inp;
        for (int j=1;j<=M;j++)
            g[i][j] = (inp[j-1]=='.');
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (g[i][j] && !vis[i][j]) {
                ar[rooms++] = dfs(i, j);
            }
        }
    }
    sort(ar, ar+rooms, greater<int>());
    int ans=0;
    for (int i=0;i<rooms;i++) {
        if (val-ar[i]>=0) {
            val -= ar[i];
            ans++;
        } else break;
    } 
    if (ans==1) cout << "1 room";
    else cout << ans << " rooms";
    cout << ", " << val << " square metre(s) left over\n";
}