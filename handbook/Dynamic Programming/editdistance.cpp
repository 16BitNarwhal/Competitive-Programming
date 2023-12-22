/*
The edit distance or Levenshtein distance1
is the minimum number of editing operations needed to transform a 
string into another string. The allowed editing operations are 
as follows:
• insert a character (e.g. ABC → ABCA)
• remove a character (e.g. ABC → AC)
• modify a character (e.g. ABC → ADC)
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    string x,y;cin>>x>>y;
    int n=x.length(),m=y.length();
    vector<vi> dp(n+1, vi(m+1));
    for(int i=0;i<=n;i++) {
        dp[i][0] = i;
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int c = (x[i-1]==y[j-1] ? 0 : 1);
            dp[i][j] = min(min(dp[i-1][j],dp[i][j-1])+1,
                dp[i-1][j-1]+c);
        }
    }
    for(auto i:dp) {for(auto j:i)cout<<j<<" "; cout<<"\n"; }
    cout<<dp[n][m]<<"\n";
}