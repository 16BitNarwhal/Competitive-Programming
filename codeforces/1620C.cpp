#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    ll n, k, x;
    cin >> n >> k >> x;
    string s;cin>>s;
    reverse(s.begin(), s.end());
    string ans="";
    x--;
    for (int i=0;i<s.size();) {
      if (s[i]=='a') {
        ans += 'a';
        i++;
      } else {
        int j=i;
        while (j<s.size() && s[j]=='*')
          j++;
        ll d = (j-i) * k + 1;
        ans += string(x % d, 'b');
        x /= d;
        i=j;
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}