#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
string names[MM];
int n, m, ar[MM], dp[MM], res[MM];

int main() {
    cin >> m >> n;
    for (int i=1;i<=n;i++) cin >> names[i] >> ar[i];
    memset(dp, 0x3f, sizeof dp); dp[0]=0;
    for (int i=1;i<=n;i++) {
        int mx=ar[i];
        for (int j=1;j<=m;j++) {
            if (dp[i-j]+mx < dp[i]) {
                dp[i] = dp[i-j]+mx;
                res[i] = i-j;
            }
            mx = max(mx, ar[i-j]);
        }
    }
    cout << "Total Time: " << dp[n] << '\n';
    int l=res[n],r=n;
    stack<string> ans;
    while (r>0) {
        string group="";
        for (int i=l+1;i<=r;i++) group += names[i]+" ";
        group += "\n"; 
        ans.push(group);
        r = l;
        l = max(0,res[l]);
    } 
    while (!ans.empty()) {
        cout << ans.top(); ans.pop();
    }
}