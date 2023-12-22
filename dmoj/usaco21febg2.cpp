// #include <bits/stdc++.h>
// using namespace std;
// const int MM = 333;
// int N, a[MM], dp[MM][MM]; 
// int main() { 
//     memset(dp, 0x3f, sizeof dp);
//     cin >> N;
//     for (int i=1;i<=N;i++) {
//         cin >> a[i]; dp[i][i] = 1;
//     }
//     for (int len=1;len<N;len++) { // loop strokes of length len
//         for (int l=1;l+len<=N;l++) {
//             int r = l+len;
//             // if colours at L and R are equal, dp[l+1][r] or d[l][r-1]
//             // all previous dp already computed because only taking dp 
//             //      with range less than current len
//             if (a[l]==a[r]) dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
//             for (int m=l;m<r;m++)
//                 dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r]);
//         }
//     }
//     cout << dp[1][N];
// }

// vvv is recursive implementation of ^^^
#include <bits/stdc++.h>
using namespace std;
const int MM = 333;
int N, a[MM], dp[MM][MM];
int rec(int l, int r) {
    if (dp[l][r] < 0x3f3f3f3f) return dp[l][r];
    if (a[l]==a[r]) dp[l][r] = min(rec(l+1,r), rec(l,r-1));
    for (int m=l;m<r;m++) 
        dp[l][r] = min(dp[l][r], rec(l,m) + rec(m+1,r));
    return dp[l][r];
}
int main() { 
    memset(dp, 0x3f, sizeof dp);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> a[i]; dp[i][i] = 1;
    }
    cout << rec(1, N);
}