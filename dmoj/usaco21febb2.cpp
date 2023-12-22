#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MM = 1002, MN = 1e5+2; 
int g[MM][MM];
pair<int,int> ar[MM];
bool a[MM][MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(g, 0, sizeof g);
    int n;cin>>n;
    int ans = 0;
    for (int i=0;i<n;i++) {
        int x,y;cin>>x>>y;
        a[x][y] = 1;
        if(x) {
            g[x-1][y]++;
            if (a[x-1][y]) {
                if (g[x-1][y]==3) ans++;
                else if (g[x-1][y]==4) ans--;
            }
        }
        if(y) {
            g[x][y-1]++;
            if (a[x][y-1]) {
                if (g[x][y-1]==3) ans++;
                else if (g[x][y-1]==4) ans--;
            }
        }
        {
            g[x+1][y]++;
            if (a[x+1][y]) {
                if (g[x+1][y]==3) ans++;
                else if (g[x+1][y]==4) ans--;
            }
        }
        {
            g[x][y+1]++;
            if (a[x][y+1]) {
                if (g[x][y+1]==3) ans++;
                else if (g[x][y+1]==4) ans--;
            }
        }
        if (g[x][y]==3) ans++;
        // ar[i] = {x,y}; 
        // for (int j=0;j<=i;j++) {
        //     if (g[ar[j].X][ar[j].Y]==3) ans++;
        // }
        cout << ans << '\n';
    }
}