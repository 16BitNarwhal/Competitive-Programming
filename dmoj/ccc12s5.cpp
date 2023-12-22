#include <bits/stdc++.h>
using namespace std;
const int N = 30;
bool a[N][N];
int dp[N][N];

int main() {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        a[i][j] = 1;
        dp[i][j] = 0;
    }
    while(k--) {
        int y,x;cin>>y>>x;
        a[y][x] = 0;
    }
    dp[1][1] = 1;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            if(a[i][j]) dp[i][j] += dp[i-1][j] + dp[i][j-1];
    
    cout<<dp[n][m]<<"\n";

}