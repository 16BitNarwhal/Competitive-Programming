#include <bits/stdc++.h>
using namespace std;

vector<string> words = {
  "ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"
};

int main() {
  int t=10;
  while (t--) {
    string s;cin>>s;
    int n=s.size();
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i=0;i<=n;i++) { 
      for (string w : words) {
        int l = w.size();
        if (i+l>n) continue;
        if (s.substr(i,l)==w)
          dp[i+l] += dp[i];
      }
    }
    cout<<dp[n]<<endl;
  }
}
