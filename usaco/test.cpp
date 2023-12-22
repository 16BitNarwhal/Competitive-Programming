#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MM = 1002, MN = 1e5+2; 
int g[MM][MM], ans;
pair<int,int> ar[MM];
bool a[MM][MM];
void func(int x, int y, bool add) {
    ans += add;
    a[x][y] = 1;
    if (g[x][y]==3) {
        if (x>0 && a[x-1][y]==0) ans++, func(x-1,y,1);
        if (y>0 && a[x][y-1]==0) ans++, func(x,y-1,1);
        if (a[x+1][y]==0) ans++, func(x+1,y,1);
        if (a[x][y+1]==0) ans++, func(x,y+1,1);
    }
    if(x) {
        g[x-1][y]+=add;
        if (a[x-1][y]) {
            if (g[x-1][y]==3) func(x-1,y,0); 
        }
    }
    if(y) {
        g[x][y-1]+=add;
        if (a[x][y-1]) {
            if (g[x][y-1]==3) func(x,y-1,0);
        }
    }
    {
        g[x+1][y]+=add;
        if (a[x+1][y]) {
            if (g[x+1][y]==3) func(x+1,y,0);
        }
    }
    {
        g[x][y+1]+=add;
        if (a[x][y+1]) {
            if (g[x][y+1]==3) func(x,y+1,0);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(g, 0, sizeof g);
    int n;cin>>n; 
    for (int i=0;i<n;i++) {
        ans = 0;
        int x,y;cin>>x>>y;
        func(x,y,1); 
        cout << ans << '\n';
    }
}