#include <bits/stdc++.h>
using namespace std;
const int MM = 222, MX = 25555;
int T, N, a[MM];
bool dp[MX];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){ 
        memset(dp, 0, sizeof dp);
        cin>>N;
        int mx = 0, ans = 0;
        for (int i=0;i<N;i++) cin >> a[i];
        sort(a, a+N);
        mx = a[N-1];
        dp[0] = 1;
        for (int i=0;i<N;i++) {
            if (!dp[a[i]]) {
                ans++;
                for (int j=a[i];j<=mx;j++)
                    dp[j] |= (dp[j-a[i]]);
            }
        } 
        cout << ans << '\n';
    }
}