#include <bits/stdc++.h>
using namespace std;

int a[101], dp[100001];
int main() {
    memset(dp, -1, sizeof dp);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    dp[0] = 0;
    for(int i=0;i<=k;i++) {
        if(dp[i]!=-1) continue;
        dp[i] = 0;
        for(int j=0;j<n;j++) {
            if(i>=a[j]) {
                dp[i] = max(dp[i], (int)!dp[i-a[j]]);
            }
        }
    }
    cout<<(dp[k] ? "First" : "Second") <<'\n'; 
}