#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
map<pi,int> mp;
int gcd(int a, int b) { return (b==0?a: gcd(b, a%b)); }
pi calc(int a, int b) {
  int x = gcd(a, b);
  return {a/x, b/x};
}
int main() {
  int t;cin>>t;
  while(t--) {
    mp.clear();
    int n;cin>>n;
    string s;cin>>s;
    int a=0,b=0;
    for (int i=0;i<n;i++) {
      if (s[i]=='D') a++;
      else b++;
      mp[calc(a,b)]++;
      cout << mp[calc(a,b)] << ' ';
    }
    cout << '\n';
  }
}