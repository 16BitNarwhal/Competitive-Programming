#include <bits/stdc++.h>
using namespace std;
const int MM = 502;

int n,vol,h[MM],dp[MM][MM*50];
unordered_set<int> used;

int main() {
    cin>>n; vol = 50*n;
    for(int i=0;i<n;i++) cin>>h[i];
    sort(h,h+n,greater<int>());
    dp[0][0] = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<=vol;j++)
            dp[i][j] = dp[i-1][j]; 
        
        for(int x : used) {
            int dif = x - h[i];
            for(int j=0;j+dif<=vol;j++)
                dp[i][j+dif] |= dp[i-1][j];
        }
        used.insert(h[i]);
    }
    for(int i=0;i<=vol;i++) 
        if(dp[n-1][i]) cout<<i<<' ';
}








