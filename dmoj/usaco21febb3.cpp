#include <bits/stdc++.h>
using namespace std;
const int MM = 410, MX = 50*50;
int g[MM][MM],cnt;
void dfs(int x, int y) {
    if(x<0||y<0||x==MM||y==MM||g[x][y]) return;
    // cout << x << ' ' << y << '\n';
    g[x][y] = 1;
    cnt++;
    if (cnt>MX) return;
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x-1,y);
}
int main() {
    int n;cin>>n;
    while(n--) {
        memset(g, 0, sizeof g);
        string inp;cin>>inp;
        int x=200,y=200;
        for (char c:inp) {
            for (int i=0;i<2;i++) {
                if (c=='N') g[x][++y]=1;
                else if (c=='S') g[x][--y]=1;
                else if (c=='E') g[++x][y]=1;
                else if (c=='W') g[--x][y]=1;
            }
        }   
        char c = inp[0]; 
        cnt=0; 
        if (c=='N') {
            y++;
            dfs(x-1, y); 
        } else if (c=='S') {
            y--;
            dfs(x+1, y); 
        } else if (c=='E') {
            x++;
            dfs(x, y+1); 
        } else if (c=='W') {
            x--;
            dfs(x, y-1); 
        }   
        if (cnt<MX) cout<<"CCW\n";
        else cout<<"CW\n"; 
    }
}