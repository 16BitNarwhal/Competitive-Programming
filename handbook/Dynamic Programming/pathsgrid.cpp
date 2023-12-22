/*
Our next problem is to find a path from the upper-left corner to the lower-right
corner of an n × n grid, such that we only move down and right. Each square
contains a positive integer, and the path should be constructed so that the sum of
the values along the path is as large as possible
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n;cin>>n;
    vector<vi> a(n, vi(n)), dp(n+1, vi(n+1,0));
    for(auto &i:a) for(auto &j:i) cin>>j;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i-1][j-1];
        }
    }    
    cout<<dp[n][n]<<"\n";
}