#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s; cin >> s;
    int cnt=0;
    int i=n/2;
    for (int i=(n+1)/2;i<n;i++) {
      if (s[i]==s[i-1]) cnt++;
      else break;
    }
    int cnt2=0;
    for (int i=n/2-1;i>=0;i--) {
      if (s[i]==s[i+1]) cnt2++;
      else break;
    }
    cout << (cnt+cnt2+ (n&1)) << '\n';
  }
}