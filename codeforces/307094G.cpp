#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int a[MM];
int n; ll c;
string s;
map<char,int> cnt; 
int main() {
  cin >> n >> c;
  cin >> s;
  int l=0, ans=0;
  ll ways=0;
  for (int r=0;r<n;r++) { 
    if (s[r]=='b') ways += cnt['a'];
    cnt[s[r]]++;
    while (ways > c) {
      if (s[l]=='a') ways -= cnt['b'];
      cnt[s[l]]--;
      l++;
    }
    ans = max(ans, r-l+1);
  }
  cout << ans << '\n';
}