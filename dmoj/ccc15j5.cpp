#include <bits/stdc++.h>
using namespace std;
 
int dp[251][251];
int pi(int n, int k) {
    if(n<0 || (k==0 && n!=0)) return 0;
    if(n==0 && k!=0) { dp[n][k] = 1; return 1; }
    if(dp[n][k]!=0) return dp[n][k];
    dp[n][k] = pi(n,k-1) + pi(n-k,k);
    return dp[n][k];
}

int main() {
    int n,k;cin>>n>>k;
    memset(dp, 0, sizeof(dp));
    cout<<pi(n-k,k)<<'\n';
}