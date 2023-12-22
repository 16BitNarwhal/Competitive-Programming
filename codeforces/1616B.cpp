#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s; 
    string res=""; 
    for (int i=0;i<n;i++) {
      res += s[i];
      if (i<n-1 && s[i]<s[i+1]) {
        break;
      }
    }
    string rev = string(res.rbegin(), res.rend());
    string a = res+rev;
    string b = string(2, s[0]);
    cout << min(a,b) << '\n';
  }
}