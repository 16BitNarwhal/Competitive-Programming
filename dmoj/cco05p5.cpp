#include <bits/stdc++.h>
using namespace std;

int dp[20005][2], a[20005][2];
int n;

int f(int x, int s) {
    if(x==n+2) return 0;
    if(dp[x][s]!=-1) return dp[x][s];
    int pos = a[x-1][s];
    int n1 = abs(pos-a[x][0]) + f(x+1, 1); // l -> r
    int n2 = abs(pos-a[x][1]) + f(x+1, 0); // r -> l
    return dp[x][s] = (min(n1,n2) + abs(a[x][0]-a[x][1]));
}

int main() {
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
    a[0][0] = a[0][1] = 1;
    a[n+1][0] = a[n+1][1] = n;
    cout<<f(1,0) + n-1<<'\n';
}