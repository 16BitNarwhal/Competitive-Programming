#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+10;
int N, ar[MM], dp[MM];
int min(int a, int b, int c) { return min(a, min(b,c)); }
int main() {
    cin >> N;
    for (int i=1;i<=N;i++) cin>>ar[i];
    for (int i=0;i<MM;i++) dp[i]=1e9;
    dp[0] = 0;
    for (int i=0;i<=N;i++) {
        // next 1
        dp[i+1] = min(dp[i+1], dp[i] + ar[i+1]);
        // next 2
        int mn = min(ar[i+1], ar[i+2]);
        int sum = ar[i+1] + ar[i+2];
        dp[i+2] = min(dp[i+2], dp[i] + sum - mn/4);
        // next 3
        mn = min(ar[i+1], ar[i+2], ar[i+3]);
        sum = ar[i+1] + ar[i+2] + ar[i+3];
        dp[i+3] = min(dp[i+3], dp[i] + sum - mn/2);
    } 
    cout << dp[N] << '\n';
}