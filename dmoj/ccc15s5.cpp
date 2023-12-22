
#include <bits/stdc++.h>
using namespace std;
const int MM = 3002;
int n,a[MM],m,b[102],dp[MM][2][102][102];

int fun(int i, bool can, int l, int r) {
    if (dp[i][can][l][r] != -1) return dp[i][can][l][r];
    int best = 0;
    if (i <= n) {
        best = max(best, fun(i+1, 1, l, r));
        if (can) best = max(best, a[i] + fun(i+1, 0, l, r));
    }
    if (l <= r) {
        best = max(best, fun(i, 1, l+1, r));
        if (can) best = max(best, b[r] + fun(i, 0, l, r-1));
    }
    return dp[i][can][l][r] = best;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(b+1, b+m+1);
    memset(dp, -1, sizeof dp);
    cout<< fun(1, 1, 1, m);
}