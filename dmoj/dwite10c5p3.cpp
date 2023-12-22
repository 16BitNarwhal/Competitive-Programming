#include <bits/stdc++.h>
using namespace std;
const int MM = 30*1000 + 2;
int n, ar[1001];
bool dp[MM];
int main() {
    int tc = 5;
    while (tc--) {
        cin >> n;
        for (int i=0;i<n;i++) cin>>ar[i];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int sum = 0;
        for (int i=0;i<n;i++) {
            for (int w=MM-1;w>=ar[i];w--)
                dp[w] |= dp[w-ar[i]];
            sum += ar[i];
        }
        int ans = sum; 
        for (int i=0;i<MM;i++) {
            if (dp[i] && abs(sum - i - i) < ans) 
                ans = abs(sum - i - i);
        }
        cout << ans << '\n';
    }
}