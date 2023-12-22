#include <bits/stdc++.h>
using namespace std;
const int MM = 505;
int n, m, k, cnt, space; bool vis[MM][MM];
string g[MM];
vector<pair<int,int>> help = {{1,0},{-1,0},{0,1},{0,-1}};
bool wall(int x, int y) {
    if (x<0||y<0||x==n||y==m) return 1;
    return g[x][y]=='#' || g[x][y]=='X'; 
}
void dfs(int x, int y) { 
    if (wall(x,y) || vis[x][y]) return; 
    if (cnt==space-k) return;
    vis[x][y]=1, cnt++; 
    for (auto p:help) dfs(x+p.first, y+p.second);
}
int main() {
    cnt = space = 0;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) cin>>g[i];
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) space+=(g[i][j]=='.'); 
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!wall(i,j)) {
                dfs(i, j);
                goto q;
            }
        }
    }
    q:;  
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vis[i][j] && g[i][j]=='.')
                g[i][j]='X';
        }
    } 
    for (int i=0;i<n;i++) {
        cout << g[i] << '\n';
    }
}