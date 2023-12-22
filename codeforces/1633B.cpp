#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    string s;cin>>s;
    int n = s.size();
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i=0;i<n;i++)
      cnt[s[i]-'0']++;
    if (cnt[0]==cnt[1]) {
      cnt[s[n-1]-'0']--;
    }
    cout << min(cnt[0], cnt[1]) << '\n';
  }
}