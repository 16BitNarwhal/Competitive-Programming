#include <bits/stdc++.h>
using namespace std;

// void solve(int t){
// 	cout << "Case #" << t << ": ";
// 	int x, y;
// 	string s;
// 	cin >> x >> y >> s;
// 	int n = (int)s.size();
// 	vector<vector<int> > dp(n+1, vector<int>(2, 1e9));
// 	dp[0][0] = dp[0][1] = 0;
// 	for(int i = 1; i <= n; i++){
// 		for(int c = 0; c < 2; c++){
// 			if(c == 0 && s[i-1] == 'J') continue;
// 			if(c == 1 && s[i-1] == 'C') continue;
// 			for(int d = 0; d < 2; d++) {
// 				int cost = 0;
// 				if(i > 1){
// 					if(d == 0 && c == 1) cost += x;
// 					if(d == 1 && c == 0) cost += y;
// 				}
// 				dp[i][c] = min(dp[i][c], dp[i-1][d] + cost);
// 			}
// 		}
// 	}
// 	cout << min(dp[n][0], dp[n][1]) << '\n';
// }
int dp[1001][2];
void solve() {
    memset(dp, 0x3f, sizeof dp);
    int x,y;string s;
    cin >> x >> y >> s;
    int n = (int)s.size();
    for (int i=1;i<=n;i++) {
        for (int c=0;c<2;c++) {
            if (c==0 && s[i-1] == 'J') continue;
            if (c==1 && s[i-1] == 'C') continue;
            for (int d=0;d<2;d++) {
                int cost = 0;
                if (i>1) {
                    if (d==0 && c==1) cost += x;
                    if (d==1 && c==0) cost += y;
                }
                dp[i][c] = min(dp[i][c], dp[i-1][d] + cost);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}