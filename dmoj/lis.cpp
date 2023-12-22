#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 +5, INF = 1e9;
int a[N],dp[N];

int main() { 
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[i] = INF;
    dp[0] = -INF;   
    for(int i=0;i<n;i++) {
        int j = upper_bound(dp, dp+n, a[i])-dp;
        if(dp[j-1] < a[i] && dp[j] > a[i]) 
            dp[j] = a[i]; 
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(dp[i]<INF) ans++;
    }
    cout<<ans<<"\n";
    // for(int i=0;i<n;i++) {
    //     dp[i] = 1;
    //     for(int j=0;j<i;j++) 
    //         if(a[i]>a[j]) dp[i] = max(dp[i], dp[j]+1); 
    // }
    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";cout<<"\n"; 
    // int ans=0;
    // for(int i=0;i<n;i++)
    //     ans = max(ans, dp[i]);
    // cout<<ans<<"\n";
}