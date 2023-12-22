#include <bits/stdc++.h>
using namespace std;

bool a[10010][10010];

int main() {
    int n,m;cin>>n>>m;
    for(int i=0,x,y,w,h;i<m;i++) {
        cin>>x>>y>>w>>h;
        x++;y++;
        a[x][y] ^= 1;
        a[x+w][y] ^= 1;
        a[x][y+h] ^= 1;
        a[x+w][y+h] ^= 1;
    }
    int res=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) { 
            a[i][j] ^= a[i-1][j] ^ a[i][j-1] ^ a[i-1][j-1];
            res += a[i][j];
        } 
    }
    cout<<res<<'\n';
}