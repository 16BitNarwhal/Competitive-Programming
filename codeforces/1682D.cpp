#include <bits/stdc++.h>
using namespace std; 
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    int cnt1=0;
    for (char c:s) cnt1 += c-'0';
    if (cnt1==0 || cnt1%2==1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> points;
    for (int i=0;i<n;i++) {
      if (s[i]=='1') points.push_back((i+1)%n);
    }
    for (int i=1;i<points.size();i++) {
      cout << points[0]+1 << ' ' << points[i]+1 << '\n';
    } 
    for (int i=0;i<n;i++) {
      if (s[i]=='0') cout << i+1 << ' ' << (i+1)%n+1 << '\n';
    }
  }
}
