#include <bits/stdc++.h>
using namespace std;
const int MM = 2505, MN = 400;
string in; 
int G, dp[MN][MM], lft[MM], rit[MM], pos=0;
void build(int rt) {
    while (pos < (int)in.size() && (in[pos]==' ' || in[pos]==')'))
        pos++;
    if (in[pos]=='(') {
        pos++;
        build(2*rt); build(2*rt+1);
    } else {
        int num = 0;
        while (isdigit(in[pos])) {
            num = num * 10 + in[pos]-'0';
            pos++;
        }
        // update growths for dp[rt]
        for (int i=0;i<=G;i++)
            dp[rt][i] = num + i;
    }
}
void solve(int rt) {
    // already calculated
    if (dp[rt][0]) return;
    int lc = 2*rt, rc = 2*rt + 1;
    solve(lc); solve(rc);
    memset(lft, 0, sizeof lft); memset(rit, 0, sizeof rit);
    // update left/right edge, i total growths, j for edge, i-j for nutrition
    for (int i=0;i<=G;i++) 
        for (int j=0;j<=i;j++) 
            lft[i] = max(lft[i], min((1+j)*(1+j), dp[lc][i-j]));
    for (int i=0;i<=G;i++)
        for (int j=0;j<=i;j++)
            rit[i] = max(rit[i], min((1+j)*(1+j), dp[rc][i-j]));
    // update current dp, i total growths, j for left, i-j for right
    for (int i=0;i<=G;i++) 
        for (int j=0;j<=i;j++) 
            dp[rt][i] = max(dp[rt][i], lft[j] + rit[i-j]);
}
int main() {
    getline(cin, in); cin >> G;
    build(1); solve(1); 
    cout << dp[1][G] << '\n';
}