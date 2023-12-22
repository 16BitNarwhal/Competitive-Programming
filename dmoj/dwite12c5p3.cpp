#include <bits/stdc++.h>
using namespace std;

int n,t=5,dp[260][260];
string s[260];

int main() {
    while(t--) {
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i]; 
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(s[i][j]=='#') dp[i][j] = 1; 
        else dp[i][j] = 0;
    }
    for(int i=n-2;i>=0;i--) for(int j=1;j<n-1;j++) {
        if(dp[i][j] && dp[i+1][j-1] && dp[i+1][j] && dp[i+1][j+1])
            dp[i][j] += min(min(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]);
    }
    
    int ans=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) 
        ans += dp[i][j];
    
    cout<<ans<<"\n";
    }
}