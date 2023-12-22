#include <bits/stdc++.h>
using namespace std;

int a[50],dp[6000];
int main() {
    memset(dp, -1, sizeof(dp));
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++) cin>>a[i];
    dp[0] = 0;
    for(int i=0;i<=n;i++) {
        if(dp[i]!=-1) 
            for(int j=0;j<m;j++)
                dp[i+a[j]] = (dp[i+a[j]]==-1) ? dp[i]+1 : min(dp[i+a[j]],dp[i]+1); 
    }
    if(dp[n]==-1) cout<<"Roberta acknowledges defeat.\n";
    else cout<<"Roberta wins in "<<dp[n]<<" strokes.\n";
}