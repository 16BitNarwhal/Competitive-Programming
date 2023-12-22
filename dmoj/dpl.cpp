#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

int a[3001];
ll dp[3001][3001];

ll f(int l, int r) {
    if(l==r) return a[l]; 
    if(dp[l][r] != INF) return dp[l][r];
    return dp[l][r] = max(a[l] - f(l+1,r), a[r] - f(l,r-1));
}

int main() {
    for(int i=0;i<3001;i++) for(int j=0;j<3001;j++) dp[i][j] = INF;
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    
    cout<< f(0, n-1) <<'\n';
}